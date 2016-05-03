//#include "stdafx.h"
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include "opencv2/imgcodecs.hpp"
//#include <opencv2/highgui.hpp>
//#include <opencv2/opencv.hpp>
//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <time.h>
//#include <math.h> 
//#include <stdlib.h> 
//
//using namespace cv;
//using namespace std;
// 
//double blue_x = 500;
//double blue_y = 250;
//
//float cal_dis(int x,int y){
//	return sqrt(pow(x-blue_x,2) + pow(y-blue_y,2));
//}
//float cal_normal(float r, float mean,float sd){
//	//cout << "dis = "<< r << "\n";
//	float a =  (1.0/(sd*(sqrt(2.0*3.14))));
//	float b =  pow( 2.71828 , (-(pow(r-mean,2.0))/(2.0*pow(sd,3))));
//	//cout << a << "," << b << "\n";
//	return a * b;
////	return (1/(sd*(sqrt(2*3.14)))) * exp(-(pow(r-mean,2))/(2*pow(sd,2)));
//}
//int main(){
//	srand (time(NULL));
//	Mat sensor_model(500,1000,CV_32FC1);
//	Mat particle(500,1000,CV_8UC1,1);
//	int particle_x[100];
//	int particle_y[100];
//	for(int i = 0;i < 100;i++){
//		int x = rand()%1000;
//		int y = rand()%500;
//		particle_x[i] = x;
//		particle_y[i] = y;
//		//particle.at<uchar>(y,x) = 255;
//		circle(particle,Point(x,y),5,Scalar(255),-1);
//	}
//	float pdf[100];
//	for(int i = 0;i < 100;i++){
//		pdf[i] = 10 * cal_normal(cal_dis(particle_x[i],particle_y[i]),100,20);
//	
//	}
//	float max = pdf[99];
//	for(int i = 0;i < 100;i++){
//		
//	
//	}
//
//	for(int y = 0;y < 500;y++){
//		for(int x = 0;x < 1000;x++){
//			sensor_model.at<float>(y,x) = 10 * cal_normal(cal_dis(x,y),100,20);
//			//cout << particle.at<float>(y,x) << "\n";
//		}
//	}
//	cout << "fin";
//	imshow("sensor_model",sensor_model);
//	imshow("particle",particle);
//	waitKey(0);
//	while(true);
//	return 0;
//}