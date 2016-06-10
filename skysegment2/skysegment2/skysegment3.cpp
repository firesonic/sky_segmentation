//#include "stdafx.h"
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include "opencv2/imgcodecs.hpp"
//#include <opencv2/highgui.hpp>
//#include <opencv2/ml.hpp>
//#include <opencv2/opencv.hpp>
//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <time.h>
//
//using namespace cv;
//using namespace cv::ml;
//using namespace std;
//
////void cv::Algorithm ::read(const FileNode &fn) {
//	//return 0;
////}
//
//std::string currentDateTime() {
//    time_t     now = time(0);
//    struct tm  tstruct;
//    char       buf[80];
//    tstruct = *localtime(&now);
//    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
//    // for more information about date/time format
//    strftime(buf, sizeof(buf), "%Y-%m-%d-%H-%M-%S", &tstruct);
//
//    return buf;
//}
//
//int main(){
//	int width = 320;
//	int height= 240;
//	int numFile = 715;
//	int readInt;
//	int readInt2;
//	int count_pixel = 0;
//	int count_all = 0;
//	double readDouble;
//	char readChar;
//	string readString;
//	Mat train_data(0,3,CV_32FC1);
//	Mat label(0,1,CV_32SC1);
//	ifstream horizon("C:/iccv09Data/horizons.txt");
//	bool load = true;
//	Ptr<SVM> svm = SVM::create();
//	//cout << Mat() << endl;
//	if(load){
//		svm = Algorithm::load<SVM>("C:/iccv09Data/svm2016-05-21-16-38-17.xml");	
//	} 
//	else{
//		for(int a = 0;a < numFile;a++){
//		
//		horizon >> readString;
//		horizon >> width;
//		horizon >> height;
//		count_all += width * height;
//		horizon >> readDouble;
//		std::cout << "a = " << a << "\n";
//		std::cout << "size = " << width << "," << height << "\n";
//		String imglink = "C:/iccv09Data/image_selected/" + readString + ".jpg";
//		String labellink = "C:/iccv09Data/labels/" + readString + ".regions.txt";
//		ifstream labelin(labellink);
//		Mat img = imread(imglink);
//		if(img.data){
//			//Size img_size = img.size();
//			//width = img_size.width;
//			//height = img_size.height;
//			//cout << width << "," << height << endl;
//			Mat train_temp(width*height,3,CV_32FC1);
//			Mat label_temp(width*height,1,CV_32SC1);
//			Mat grey;
//			cvtColor(img,img,CV_BGR2HLS);
//			cvtColor(img,grey,CV_BGR2GRAY);
//			medianBlur(img,img,31);
//			for(int y = 0;y < height;y++){
//				for(int x = 0;x < width;x++){
//					
//					labelin >> readInt;
//					train_temp.at<float>((y*width) + x,0) = img.at<Vec3b>(y,x)[0];
//					train_temp.at<float>((y*width) + x,1) = img.at<Vec3b>(y,x)[1];
//					train_temp.at<float>((y*width) + x,2) = img.at<Vec3b>(y,x)[2];
//					/*double grey_sum = 0;
//					for(int j = -2;j < 3;j++){
//						for(int i = -2;i < 3;i++){
//							if( x+i < 0 || x+i >= width || y+j<0 || y+j>=height){
//								grey_sum += grey.at<uchar>(y,x);
//							}
//							else{
//								grey_sum += grey.at<uchar>(y+j,x+i);
//							}
//						}
//					}
//					double grey_mean = grey_sum/25;
//					double grey_sum2 = 0;
//					double grey_sum3 = 0;
//					for(int j = -2;j < 3;j++){
//						for(int i = -2;i < 3;i++){
//							if( x+i < 0 || x+i >= width || y+j<0 || y+j>=height){
//								grey_sum2 += (grey.at<uchar>(y,x) - grey_mean) * (grey.at<uchar>(y,x) - grey_mean);
//								grey_sum3 += (grey.at<uchar>(y,x) - grey_mean) * (grey.at<uchar>(y,x) - grey_mean) * (grey.at<uchar>(y,x) - grey_mean);
//							}
//							else{
//								grey_sum2 += (grey.at<uchar>(y+j,x+i) - grey_mean) * (grey.at<uchar>(y+j,x+i) - grey_mean);
//								grey_sum3 += (grey.at<uchar>(y+j,x+i) - grey_mean) * (grey.at<uchar>(y+j,x+i) - grey_mean) * (grey.at<uchar>(y+j,x+i) - grey_mean);
//							}
//						}
//					}
//					double grey_sd = sqrt(grey_sum2/25);
//					double grey_sm = 1.0 - (1.0/(1.0+(grey_sd*grey_sd)));
//					double grey_third = grey_sum3/25;
//					train_temp.at<float>((y*width) + x,3) = grey_mean;
//					train_temp.at<float>((y*width) + x,4) = grey_sd;
//					train_temp.at<float>((y*width) + x,5) = grey_sm;
//					train_temp.at<float>((y*width) + x,6) = grey_third;*/
//					//printf("%f,%f,%f,%f,%f,%f,%f\n",train_temp.at<float>((y*width) + x,0),train_temp.at<float>((y*width) + x,1),train_temp.at<float>((y*width) + x,2),train_temp.at<float>((y*width) + x,3),train_temp.at<float>((y*width) + x,4),train_temp.at<float>((y*width) + x,5),train_temp.at<float>((y*width) + x,6));
//					if(readInt == 0){ label_temp.at<int>((y*width) + x,0) = 1; /*img.at<Vec3b>(y,x) = Vec3b(0,0,0);*/}
//					else label_temp.at<int>((y*width) + x,0) = -1;
//					
//				}
//			}
//			count_pixel += width * height;
//			imshow("img",img);
//			cv::waitKey(100);
//			train_data.push_back(train_temp);
//			label.push_back(label_temp);
//		}
//		
//		/*while(true){
//		
//			readChar = waitKey(10);
//			if(readChar == 'g') break;
//		}*/
//	}
//		std::cout << count_pixel << endl;
//		std::cout << count_all << endl;
//		std::cout << train_data.size() << endl;
//		std::cout << label.size() << endl;
//	//cout << train_data.row << "," << train_data.col << endl;
//	//cout << label.row << "," << label.col << endl;
//    svm->setType(SVM::C_SVC);
//	svm->setKernel(SVM::LINEAR);
//    svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 10000, 1e-3));
//	svm->setC(0.30);
//	//Train Data
//		//Ptr<TrainData> traindata =  cv::ml::TrainData::create(train_data,ROW_SAMPLE,label);
//
//	//TRAIN
//	std::cout << "START TRAINING\n";
//	svm->train(train_data,ROW_SAMPLE,label);
//	//svm->trainAuto(traindata,3);
//	svm->save("C:/iccv09Data/svm" + currentDateTime() + ".xml");
//	std::cout << "C:/iccv09Data/svm" + currentDateTime() + ".xml" << endl;
//	//svm->loadFromString("C:");
//	std::cout << "END TRAINING\n";
//	}
//	//PREDICT!!!
//	string imgLink = "C:/iccv09Data/image_selected/6000060.jpg";
//	Mat test = imread(imgLink);
//	Mat grey;
//	height = test.size().height;
//	width = test.size().width;
//	//Mat test2 = imread(imgLink);
//	Mat result(height,width,CV_8UC3,Scalar(255,255,255));
//	//resize(test,test,Size(width,height));
//	cvtColor(test,test,CV_BGR2HLS);
//	cvtColor(test,grey,CV_BGR2GRAY);
//	medianBlur(test,test,31);
//	imshow("Pre-test",test);
//	Vec3b green(0,255,0), blue (255,0,0);
//	
//	for (int y = 0; y < height; ++y){
//		for (int x = 0; x < width; ++x)
//        {
//			Mat sampleMat(1,3,CV_32FC1);
//			sampleMat.at<float>(0,0) = test.at<Vec3b>(y,x)[0];
//			sampleMat.at<float>(0,1) = test.at<Vec3b>(y,x)[1];
//			sampleMat.at<float>(0,2) = test.at<Vec3b>(y,x)[2];
//			//////////////////////////////////////////////////////
//
//			/*double grey_sum = 0;
//					for(int j = -2;j < 3;j++){
//						for(int i = -2;i < 3;i++){
//							if( x+i < 0 || x+i >= width || y+j<0 || y+j>=height){
//								grey_sum += grey.at<uchar>(y,x);
//							}
//							else{
//								grey_sum += grey.at<uchar>(y+j,x+i);
//							}
//						}
//					}
//					double grey_mean = grey_sum/25;
//					double grey_sum2 = 0;
//					double grey_sum3 = 0;
//					for(int j = -2;j < 3;j++){
//						for(int i = -2;i < 3;i++){
//							if( x+i < 0 || x+i >= width || y+j<0 || y+j>=height){
//								grey_sum2 += (grey.at<uchar>(y,x) - grey_mean) * (grey.at<uchar>(y,x) - grey_mean);
//								grey_sum3 += (grey.at<uchar>(y,x) - grey_mean) * (grey.at<uchar>(y,x) - grey_mean) * (grey.at<uchar>(y,x) - grey_mean);
//							}
//							else{
//								grey_sum2 += (grey.at<uchar>(y+j,x+i) - grey_mean) * (grey.at<uchar>(y+j,x+i) - grey_mean);
//								grey_sum3 += (grey.at<uchar>(y+j,x+i) - grey_mean) * (grey.at<uchar>(y+j,x+i) - grey_mean) * (grey.at<uchar>(y+j,x+i) - grey_mean);
//							}
//						}
//					}
//					double grey_sd = sqrt(grey_sum2/25);
//					double grey_sm = 1.0 - (1.0/(1.0+(grey_sd*grey_sd)));
//					double grey_third = grey_sum3/25;
//					sampleMat.at<float>(0,3) = grey_mean;
//					sampleMat.at<float>(0,4) = grey_sd;
//					sampleMat.at<float>(0,5) = grey_sm;
//					sampleMat.at<float>(0,6) = grey_third;*/
//
//			/////////////////////////////////////////////////////////
//			int response = svm -> predict(sampleMat);
//            if (response == 1){
//				// 1 is blue
//				//cout << "hello" << endl;
//                result.at<Vec3b>(y,x)  = blue;
//				//cout << "BLUE" << endl;
//			}
//            else if (response == -1){
//				//cout << "bye" << endl;
//                result.at<Vec3b>(y,x)  = green;
//				//cout << "GREEN" << endl;
//			}
//        }
//	}
//	//imshow("ORIGINAL",test);
//	imshow("SEGMENT",result);
//	readChar = cv::waitKey(100);
//	std::cout << "HELLOOOOOO";
//	cv::waitKey(0);
//	//while(true);
//	return 0;
//}