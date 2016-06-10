//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//
//using namespace cv;
//using namespace std;
//
//RNG rng(12345);
//double cal_dis(double row, double col, double h, double s, double v, vector<double>& mean){
//	double dis = (row - mean[0])*(row-mean[0]) + (col - mean[1])*(col-mean[1]) + 10*(h - mean[2])*(h-mean[2]) + 10*(s - mean[3])*(s-mean[3]);
//	//double dis = (100)*(h - mean[0])*(h-mean[0]) + 100*(s - mean[1])*(s-mean[1]) + 100*(v-mean[2])*(v-mean[2]);
//	dis = sqrt(dis);
//	return dis;
//}
//
//void kMean(int g, Mat& src){
//	Mat hsv_src;
//	Mat label(src.size(),CV_8UC1);
//	Mat show(src.size(),CV_8UC3);
//	double width = src.size().width;
//	double height = src.size().height;
//	cvtColor(src,hsv_src,CV_BGR2HSV);
//	GaussianBlur(hsv_src,hsv_src,Size(9,9),2,2);
//	
//	///prepare initial mean for g group////////////////////////////////
//	vector<vector<double> > mean;
//	vector<vector<double> > prev_mean;
//	vector<vector<double> > acc_mean;
//	vector<double> count_mean;
//	
//	mean.resize(g);
//	acc_mean.resize(g);
//	count_mean.resize(g);
//	prev_mean.resize(g);
//
//
//	for(double i = 0;i < height;i++){
//		for(double j = 0;j < width;j++){
//			hsv_src.at<Vec3b>(i,j)[2] = 127;
//		}
//	}
//	Mat bgr_src,cie_src;
//	imshow("hsv",hsv_src);
//	cvtColor(hsv_src,bgr_src,CV_HSV2BGR);
//	imshow("BGR_back",bgr_src);
//	cvtColor(bgr_src,cie_src, CV_BGR2Lab);
//	imshow("cie",cie_src);
//	for(int i = 0;i < g;i++){
//		int row,col;
//		row = rng.uniform(0.0,height - 1);
//		col = rng.uniform(0.0,width - 1);
//		mean[i].push_back(row/height);
//		mean[i].push_back(col/width);
//		mean[i].push_back(hsv_src.at<Vec3b>(row,col)[0]/180.0);
//		mean[i].push_back(hsv_src.at<Vec3b>(row,col)[1]/255.0);
//		//mean[i].push_back(cie_src.at<Vec3b>(row,col)[2]/255);
//		acc_mean[i].push_back(0);
//		acc_mean[i].push_back(0);
//		acc_mean[i].push_back(0);
//		acc_mean[i].push_back(0);
//		//acc_mean[i].push_back(0);
//		prev_mean[i].push_back(0);
//		prev_mean[i].push_back(0);
//		prev_mean[i].push_back(0);
//		prev_mean[i].push_back(0);
//		//prev_mean[i].push_back(0);
//		cout << mean[i][0] << " " << mean[i][1] << " " << mean[i][2] << " " << mean[i][3] << "\n";
//		cout << "//////////////////////////////////////////////////////////////////////////////////\n";
//	}
//	///////////////////////////////////////////////////////////////////
//	double min,min_index;
//	int count = 0;
//	///
//	while(true){
//
//	for(double i = 0;i < height;i++){
//		for(double j = 0;j < width;j++){
//			for(int k = 0;k < g; k++){
//				double dis = cal_dis(i/height,j/width,hsv_src.at<Vec3b>(i,j)[0]/180.0,hsv_src.at<Vec3b>(i,j)[1]/255.0,hsv_src.at<Vec3b>(i,j)[2]/255.0,mean[k]);
//				if(k == 0) {min = dis; min_index = k;}
//				else if(dis < min) {min = dis; min_index = k;}
//			}
//			acc_mean[min_index][0] += i/height;
//			acc_mean[min_index][1] += j/width;
//			acc_mean[min_index][2] += hsv_src.at<Vec3b>(i,j)[0]/180.0;
//			acc_mean[min_index][3] += hsv_src.at<Vec3b>(i,j)[1]/255.0;
//			//acc_mean[min_index][4] += cie_src.at<Vec3b>(i,j)[2]/255;
//			count_mean[min_index] += 1;
//			label.at<uchar>(i,j) = min_index;
//		}
//	}
//	for(int i = 0;i < g;i++){
//		mean[i][0] = acc_mean[i][0]/count_mean[i];
//		mean[i][1] = acc_mean[i][1]/count_mean[i];
//		mean[i][2] = acc_mean[i][2]/count_mean[i];
//		mean[i][3] = acc_mean[i][3]/count_mean[i];
//		//mean[i][4] = acc_mean[i][4]/count_mean[i];
//		acc_mean[i][0] = 0;
//		acc_mean[i][1] = 0;
//		acc_mean[i][2] = 0;
//		acc_mean[i][3] = 0;
//		//acc_mean[i][4] = 0;
//		count_mean[i] = 0;
//		cout << mean[i][0] << " " << mean[i][1] << " " << mean[i][2] << " " << mean[i][3] << "\n";
//		cout << "===================================================================================\n";
//	}
//	for(int i = 0;i < height;i++){
//		for(int j = 0;j < width;j++){
//			if(label.at<uchar>(i,j) == 0) show.at<Vec3b>(i,j) = Vec3b(255,0,0);
//			else if(label.at<uchar>(i,j) == 1) show.at<Vec3b>(i,j) = Vec3b(0,255,0);
//			else if(label.at<uchar>(i,j) == 2) show.at<Vec3b>(i,j) = Vec3b(0,0,255);
//			else if(label.at<uchar>(i,j) == 3) show.at<Vec3b>(i,j) = Vec3b(0,0,0);
//			else if(label.at<uchar>(i,j) == 4) show.at<Vec3b>(i,j) = Vec3b(255,255,255);
//			else if(label.at<uchar>(i,j) == 5) show.at<Vec3b>(i,j) = Vec3b(0,255,255);
//			else if(label.at<uchar>(i,j) == 6) show.at<Vec3b>(i,j) = Vec3b(255,0,255);
//			else if(label.at<uchar>(i,j) == 7) show.at<Vec3b>(i,j) = Vec3b(255,255,0);
//			else if(label.at<uchar>(i,j) == 8) show.at<Vec3b>(i,j) = Vec3b(255,255,125);
//			else if(label.at<uchar>(i,j) == 9) show.at<Vec3b>(i,j) = Vec3b(255,125,255);
//			else if(label.at<uchar>(i,j) == 10) show.at<Vec3b>(i,j) = Vec3b(125,255,255);
//		}
//	}
//	count++;
//	cout << count << endl;
//	imshow("show",show);
//	waitKey(0);
//	}
//}
//
//int main(){
//	Mat src = imread("C:/bouy/bouy200.png");
//	imshow("src",src);
//	kMean(11,src);
//	return 0;
//}