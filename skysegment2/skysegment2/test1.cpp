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
//
//int main(){
//	int width = 320;
//	int height= 240;
//	int numFile = 9;
//	int readInt;
//	int readInt2;
//	int count_pixel = 0;
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
//		svm = Algorithm::load<SVM>("C:/iccv09Data/svm2016-05-15-13-24-21.xml");	
//	} 
//	else{
//		for(int a = 0;a < 8;a++){
//			string readnum = to_string(a+1);
//			String read_link = "C:/iccv09Data/make/" +  readnum + ".jpg";
//			Mat load_train =  imread(read_link);
//			Mat train_temp(320*240,3,CV_32FC1);
//			Mat label_temp(320*240,1,CV_32SC1);
//			resize(load_train,load_train,Size(320,240));
//			imshow("input",load_train);
//			waitKey(0);
//			for(int yy = 0;yy < 240;yy++){
//				for(int xx = 0;xx < 320;xx++){
//					train_temp.at<float>((yy*320) + xx,0) = load_train.at<Vec3b>(yy,xx)[0];
//					train_temp.at<float>((yy*320) + xx,1) = load_train.at<Vec3b>(yy,xx)[1];
//					train_temp.at<float>((yy*320) + xx,2) = load_train.at<Vec3b>(yy,xx)[2];
//					if(load_train.at<Vec3b>(yy,xx)[0] > 150){
//						label_temp.at<int>((yy*320) + xx,0) = 1;
//					}
//					else{
//						label_temp.at<int>((yy*320) + xx,0) = 2;
//					}
//				}
//			}
//			cout << load_train.at<Vec3b>(0,0) << endl;
//			train_data.push_back(train_temp);
//			cout << label_temp.at<int>(0,0) << endl;
//			label.push_back(label_temp);
//		}
//	//cout << train_data.row << "," << train_data.col << endl;
//	//cout << label.row << "," << label.col << endl;
//    //svm->setType(SVM::C_SVC);
//	//svm->setKernel(SVM::RBF);
//    //svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6));
//
//	//Train Data
//	Ptr<TrainData> traindata =  cv::ml::TrainData::create(train_data,ROW_SAMPLE,label);
//
//	//TRAIN
//	cout << "START TRAINING\n";
//	//svm->train(train_data,ROW_SAMPLE,label);
//	svm->trainAuto(traindata,3);
//	svm->save("C:/iccv09Data/svm" + currentDateTime() + ".xml");
//	cout << "C:/iccv09Data/svm" + currentDateTime() + ".xml" << endl;
//	//svm->loadFromString("C:");
//	cout << "END TRAINING\n";
//	}
//
//
//
//	//PREDICT!!!
//	string imgLink = "C:/iccv09Data/make/1.jpg";
//	Mat test = imread(imgLink);
//	Mat grey;
//
//	//Mat test2 = imread(imgLink);
//	Mat result(height,width,CV_8UC3,Scalar(255,255,255));
//	resize(test,test,Size(width,height));
//	//cvtColor(test,test,CV_BGR2HSV);
//	//cvtColor(test,grey,CV_BGR2GRAY);
//	imshow("Pre-test",test);
//	waitKey(100);
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
//			int response = svm -> predict(sampleMat);
//            if (response == 1){
//				// 1 is blue
//				//cout << "hello" << endl;
//                result.at<Vec3b>(y,x)  = blue;
//				//cout << "BLUE" << endl;
//			}
//            else if (response == 2){
//				//cout << "bye" << endl;
//                result.at<Vec3b>(y,x)  = green;
//				//cout << "GREEN" << endl;
//			}
//        }
//	}
//	imshow("SEGMENT",result);
//	readChar = waitKey(100);
//	cout << "HELLOOOOOO";
//	waitKey(0);
//	while(true);
//	return 0;
//}