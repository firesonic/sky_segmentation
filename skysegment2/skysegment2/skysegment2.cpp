//#include "stdafx.h"
//#include <opencv2/core.hpp>
//#include <opencv2/imgproc.hpp>
//#include "opencv2/imgcodecs.hpp"
//#include <opencv2/highgui.hpp>
//#include <opencv2/ml.hpp>
//#include <stdio.h>
//// reading a text file
//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//
//
//using namespace cv;
//using namespace cv::ml;
//using namespace std;
//
//double x_1;
//double y_1;
//double x_2;
//double y_2;
//
//void CallBackFunc(int event, int x, int y, int flags, void* userdata)
//{
//     if  ( event == EVENT_LBUTTONDOWN )
//     {
//          cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
//		  x_1 = x;
//		  y_1 = y;
//     }
//     else if  ( event == EVENT_RBUTTONDOWN )
//     {
//          cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
//		  x_2 = x;
//		  y_2 = y;
//     }
//}
//
//
//int main()
//{
//	
//  //string line;
//  //Mat example = imread("C:/iccv09Data/images/0000047.jpg");
//  ifstream myMain ("C:/iccv09Data/horizons.txt");
//  //ifstream mytext ("C:/iccv09Data/labels/0000047.regions.txt");
//  //imshow("example",example);
//  //waitKey(100);
//  char readChar;
//  int readInt;
//  double readDouble;
//  string readString;
//  /*if (myMain.is_open()){
//	for(int j = 0;j < 715;j++){
//	myMain >> fgh;
//	cout << fgh << endl;
//	for(int i = 0;i < 2;i++)
//    {
//	  myMain >> abc;
//      cout << abc << '\n';
//	  //cin >> eee;
//    }
//	myMain >> dce;
//	cout << dce << endl;
//	}
//    myMain.close();
//  for(int i = 0; i < 240;i++){
//	  for(int j = 0;j < 320;j++){
//			mytext >> abc;
//			if(abc == 0) example.at<Vec3b>(i,j) = Vec3b(0,0,0);
//	  }
//  }
//  imshow("example",example);
//  waitKey(100);
//  }*/
//  //else cout << "Unable to open file"; 
//
//  //waitKey(0);
//
//	String imgHome = "C:/Landscape/S";
//	String imgLink;
//	int numFile = 8;
//	char kb;
//	int height = 240;
//	int width = 320;
//	Mat train_data2(width*height*numFile,3,CV_32FC1);
//	Mat label2(width*height*numFile,1,CV_32SC1);
//	Ptr<SVM> svm = SVM::create();
//    svm->setType(SVM::C_SVC);
//    svm->setKernel(SVM::LINEAR);
//    svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6));
//	Ptr<SVM> svm2 = SVM::create();
//    svm2->setType(SVM::C_SVC);
//    svm2->setKernel(SVM::LINEAR);
//    svm2->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6));
//	/*for(int i = 0;i < 715;i++){
//		myMain >> readString;
//		myMain >> readInt;
//		if(readInt != )
//	
//	}*/
//	for(int i = 1; i <= numFile; i++){
//		Mat train_data(width*height,3,CV_32FC1);
//		Mat label (width*height,1,CV_32SC1);
//		x_1 = 0; x_2 = 0; y_1 = 0; y_2 = 0;
//		stringstream ss;
//		ss << i;
//		imgLink = imgHome + ss.str() + ".jpg";
//		Mat landscape = imread(imgLink);
//		resize(landscape,landscape,Size(width,height));
//		cvtColor(landscape,landscape, CV_BGR2YCrCb);
//		Mat clone = landscape.clone();
//		/*for(int y = 0;y < height;y++){
//			for(int x = 0;x < width;x++){
//				if(y > height/2) landscape.at<Vec3b>(y,x) = Vec3b(0,0,0);
//				else landscape.at<Vec3b>(y,x) = Vec3b(255,255,255);
//			
//			}
//		}*/
//		cout << "first: " << landscape.at<Vec3b>(0,0) << endl;
//		namedWindow("Landscape", WINDOW_AUTOSIZE );
//		namedWindow("clone",WINDOW_AUTOSIZE);
//		setMouseCallback("clone", CallBackFunc, NULL);
//		imshow("Landscape",landscape);
//		//cout << "RGB?BGR: " << landscape.at<Vec3b>(100,100) << endl;
//		//for set horizon line
//		
//		while(true){
//			clone = landscape.clone();
//			cv::line(clone, cv::Point(x_1, y_1), cv::Point(x_2, y_2), CV_RGB(255, 0, 0), 2);
//			imshow("clone",clone);
//			kb = waitKey(100);
//			if(kb == 'g') break;
//		}
//		//set data to train data
//		for(int y = 0; y < height; y++)
//			for(int x = 0; x < width; x++){
//				train_data2.at<float>(x + (y*width) + (width * height * (i-1)),0) = landscape.at<Vec3b>(y,x)[0];
//				train_data2.at<float>(x + (y*width) + (width * height * (i-1)),1) = landscape.at<Vec3b>(y,x)[1];
//				train_data2.at<float>(x + (y*width) + (width * height * (i-1)),2) = landscape.at<Vec3b>(y,x)[2];
//				train_data.at<float>(x + (y*width),0) = landscape.at<Vec3b>(y,x)[0];
//				train_data.at<float>(x + (y*width),1) = landscape.at<Vec3b>(y,x)[1];
//				train_data.at<float>(x + (y*width),2) = landscape.at<Vec3b>(y,x)[2];
//				//cout << train_data.at<float>(x + (y*640) + (640 * 480 * (i-1)),0) << endl;
//				//cout << (int)landscape.at<Vec3b>(y,x)[0] << endl;
//		}
//
//		//set data to label
//		double slope = (y_1 - y_2) / (x_1 - x_2);
//		double con = y_1 - (slope * x_1);
//		cout << "S: " << slope << "," << con << endl;
//		for(int y = 0; y < height; y++)
//			for(int x = 0; x < width; x++){
//				if(y - (slope * x) <= con) { label.at<int>(x + (y*width),0) = 1; label2.at<int>(x + (y*width) + (width * height * (i-1)),0) = 1; }
//				else { label.at<int>(x + (y*width),0) = -1; label2.at<int>(x + (y*width) + (width * height * (i-1)),0) = -1;}
//				//cout << train_data.at<float>(x + (y*640) + (640 * 480 * (i-1)),0) << endl;
//				//cout << (int)landscape.at<Vec3b>(y,x)[0] << endl;
//		}
//		/*cout << train_data.at<float>(0,0) << "," << train_data.at<float>(0,1) << train_data.at<float>(0,2);
//		cout << " || " << label.at<float>(0,0) << endl;
//		cout << train_data.at<float>(639,0);
//		cout << " || " << label.at<float>(639,0) << endl;
//		cout << train_data.at<float>(439 * 640,0);
//		cout << " || " << label.at<float>(439 * 640,0) << endl;
//		cout << train_data.at<float>(439 * 640 + 639,0);
//		cout << " || " << label.at<float>(439 * 640 + 639,0) << endl;*/
//		Mat show_label(height,width,CV_8UC3,Scalar(0,0,0));
//		Mat show_label2(height,width,CV_8UC3,Scalar(0,0,0));
//		Mat show_train(height,width,CV_8UC3,Scalar(0,0,0));
//		Mat show_train2(height,width,CV_8UC3,Scalar(0,0,0));
//		Vec3b green(0,255,0), blue (255,0,0);
//		for(int y = 0;y < height;y++){
//			for(int x = 0;x < width;x++){
//				if(label.at<int>(x + (y*width),0) == -1)  { show_label.at<Vec3b>(y,x) = green;}
//				else if(label.at<int>(x + (y*width),0) == 1) show_label.at<Vec3b>(y,x) = blue;
//				if(label2.at<int>(x + (y*width)+ ((i-1)*width * height),0) == -1 )  { show_label2.at<Vec3b>(y,x) = green;}
//				else if(label2.at<int>(x + (y*width)+ ((i-1)*width * height),0) == 1) show_label2.at<Vec3b>(y,x) = blue;
//				show_train.at<Vec3b>(y,x)[0] = train_data.at<float>(x + (y*width),0);
//				show_train.at<Vec3b>(y,x)[1] = train_data.at<float>(x + (y*width),1);
//				show_train.at<Vec3b>(y,x)[2] = train_data.at<float>(x + (y*width),2);
//				show_train2.at<Vec3b>(y,x)[0] = train_data2.at<float>(x + (y*width) + ((i-1)*width * height),0);
//				show_train2.at<Vec3b>(y,x)[1] = train_data2.at<float>(x + (y*width) + ((i-1)*width * height),1);
//				show_train2.at<Vec3b>(y,x)[2] = train_data2.at<float>(x + (y*width) + ((i-1)*width * height),2);
//				//imshow("Show_Test",show_train); 		
//			}
//			//waitKey(1);
//		}
//		imshow("Show_Label",show_label);
//		imshow("Show Label2",show_label2);
//		imshow("Show_Train",show_train);
//		imshow("Show_Train2",show_train2);
//		waitKey(0);
//		bool result_train = svm->train(train_data, ROW_SAMPLE, label);
//		cout << result_train << endl;
//	}
//	Mat train_data3 (width*height,3,CV_32FC1);
//	Mat label3(width*height,1,CV_32SC1);
//	for(int i = 0;i < 240;i++){
//		for(int j = 0;j < 320;j++){
//			train_data3.at<float>((i*width) + j,0) = train_data2.at<float>((i*width) + j +(7*width*height),0);
//			train_data3.at<float>((i*width) + j,1) = train_data2.at<float>((i*width) + j +(7*width*height),1);
//			train_data3.at<float>((i*width) + j,2) = train_data2.at<float>((i*width) + j +(7*width*height),2);
//			label3.at<int>(i*width + j) = label2.at<int>(i*width + j + (7*width*height));
//		
//		}
//	}
//	bool result_train = svm2->train(train_data3, ROW_SAMPLE, label3);
//	cout << result_train << endl;
//	
//
//	//cout << "result: " << train_result << endl; 
//	//cout << "End Training" << endl;
//	//cout << "COUNT: " << SVM.get_support_vector_count() << endl;
//	//for(int i = 0;i < SVM.get_support_vector_count();i++){
//	//	cout << i << " : " << *(SVM.get_support_vector(i)) << endl;
//	//}
//	//cout << "var count: " << SVM.get_var_count() << endl;
//
//	//PREDICT!!!
//	imgLink = "C:/Landscape/S1.jpg";
//	Mat test = imread(imgLink);
//	//Mat test2 = imread(imgLink);
//	Mat result(height,width,CV_8UC3,Scalar(255,255,255));
//	Mat result2(height,width,CV_8UC3,Scalar(255,255,255));
//	resize(test,test,Size(width,height));
//	cvtColor(test,test,CV_BGR2YCrCb);
//	/*for(int y = 0;y < height;y++){
//		for(int x = 0;x < width;x++){
//				if(y > height/2) test.at<Vec3b>(y,x) = Vec3b(0,0,0);
//				else test.at<Vec3b>(y,x) = Vec3b(255,255,255);
//			
//			}
//	}*/
//	imshow("Pre-test",test);
//	Vec3b green(0,255,0), blue (255,0,0);
//	
//	for (int y = 0; y < height; ++y){
//		for (int x = 0; x < width; ++x)
//        {
//			Mat sampleMat(1,3,CV_32FC1);
//			//cout << i << "," << j << endl;
//			sampleMat.at<float>(0,0) = test.at<Vec3b>(y,x)[0];
//			sampleMat.at<float>(0,1) = test.at<Vec3b>(y,x)[1];
//			sampleMat.at<float>(0,2) = test.at<Vec3b>(y,x)[2];
//			//sampleMat.at<float>(0,0) = train.at<float>(j + (i*640),0);
//			//sampleMat.at<float>(0,1) = train.at<float>(j + (i*640),1);
//			//sampleMat.at<float>(0,2) = train.at<float>(j + (i*640),2);
//			int response = svm -> predict(sampleMat);
//			int response2 = svm2 -> predict(sampleMat);
//			//cout << response << endl;
//			//waitKey(0);
//			//cout << i << "," << j << endl;
//            if (response == 1){
//				//cout << "hello" << endl;
//                result.at<Vec3b>(y,x)  = blue;
//				//cout << "BLUE" << endl;
//			}
//            else if (response == -1){
//				//cout << "bye" << endl;
//                result.at<Vec3b>(y,x)  = green;
//				//cout << "GREEN" << endl;
//			}
//			if (response2 == 1){
//				//cout << "hello" << endl;
//                result2.at<Vec3b>(y,x)  = blue;
//				//cout << "BLUE" << endl;
//			}
//            else if (response2 == -1){
//				//cout << "bye" << endl;
//                result2.at<Vec3b>(y,x)  = green;
//				//cout << "GREEN" << endl;
//			}
//        }
//	}
//	imshow("ORIGINAL",test);
//	imshow("SEGMENT",result);
//	imshow("SEGMENT2",result2);
//	waitKey(0);
//	return 0;
//}
