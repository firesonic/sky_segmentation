//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//
//
//using namespace cv;
//using namespace std;
//
//double pi = 3.14;
//double h_sum = 0, h_sum_sq = 0, h_mean = 0, h_sd = 0, h_ss, h_mean_sq;
//double s_sum = 0, s_sum_sq = 0, s_mean = 0, s_sd = 0, s_ss, s_mean_sq;
//double hs_mul = 0,hs_mean;
//double cov;
//
//
//double cal_p(double h, double s){
//	double h_part = (h - h_mean)*(h - h_mean) / (h_sd * h_sd);
//	double s_part = (s - s_mean)*(s - s_mean) / (s_sd * s_sd);
//	double cov_part = 2 * cov * (h - h_mean) * (s - s_mean) / (h_sd * s_sd);
//	double exp_part = - (h_part + s_part - cov_part) / 2 * (1 - (cov * cov));
//	double base = exp(exp_part) / (2 * pi * h_sd * s_sd * (sqrt(1 - (cov * cov))));
//	/*cout << h_part << "\n";
//	cout << s_part << "\n";
//	cout << cov_part << "\n";
//	cout << exp_part << "\n";
//	cout << base << "\n";*/
//	return base;
//}
//
///** @function main */
//int main()
//{
//	Mat src, hsv_src;
//	int n = 0;
//	src = imread("C:/bouy/bouy" + to_string(n) + ".png");
//	imshow("BGR",src);
//	cvtColor(src, hsv_src, CV_BGR2HSV);
//	imshow("HSV",hsv_src);
//
//	int width = src.size().width;
//	int height = src.size().height;
//	for(int j = 0;j < height;j++){
//		for(int i = 0;i < width;i++){
//			h_sum += hsv_src.at<Vec3b>(j,i)[0];
//			s_sum += hsv_src.at<Vec3b>(j,i)[1];
//			h_sum_sq += hsv_src.at<Vec3b>(j,i)[0] * hsv_src.at<Vec3b>(j,i)[0];
//			s_sum_sq += hsv_src.at<Vec3b>(j,i)[1] * hsv_src.at<Vec3b>(j,i)[1];
//			hs_mul += hsv_src.at<Vec3b>(j,i)[0] * hsv_src.at<Vec3b>(j,i)[1];
//			hsv_src.at<Vec3b>(j,i)[2] = 127;
//		}
//	}
//	cvtColor(hsv_src,hsv_src,CV_HSV2BGR);
//	imshow("new HSV",hsv_src);
//	double pix = width * height;
//	h_mean = h_sum/pix;
//	s_mean = s_sum/pix;
//	h_mean_sq = h_sum_sq/pix;
//	s_mean_sq = s_sum_sq/pix;
//	hs_mean = hs_mul/pix;
//	h_ss = h_sum_sq - (h_sum * h_sum / pix);
//	s_ss = s_sum_sq - (s_sum * s_sum / pix);
//	h_sd = sqrt(h_ss/pix);
//	s_sd = sqrt(s_ss/pix);
//	cov = (hs_mean - (h_mean * s_mean));
//	cout << cov << "\n";
//	cov = cov/((sqrt(h_mean_sq - (h_mean * h_mean)))*(sqrt(s_mean_sq - (s_mean * s_mean))));
//	cout << "h_mean " << h_mean << " h_sd " << h_sd << "\n"; 
//	cout << "s_mean " << s_mean << " s_sd " << s_sd << "\n";
//	cout << "hs_mul " << hs_mean << " cov" << cov << "\n";
//	cout << h_sum << "\n";
//	for(int j = 0;j < height;j++){
//		for(int i = 0;i < width;i++){
//			double h = hsv_src.at<Vec3b>(j,i)[0];
//			double s = hsv_src.at<Vec3b>(j,i)[1];
//			double prop = cal_p(h,s);
//			//cout << prop << "\n";
//			if(prop < 0.00001) src.at<Vec3b>(j,i) = Vec3b(255,255,255);
//			else src.at<Vec3b>(j,i) = Vec3b(0,0,0);
//		}
//	}
//	imshow("new BGR",src);
//	waitKey(0);
//	
//	return 0;
//}
