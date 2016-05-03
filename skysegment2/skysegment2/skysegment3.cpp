#include "stdafx.h"
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace cv;
using namespace cv::ml;
using namespace std;

//void cv::Algorithm ::read(const FileNode &fn) {
	//return 0;
//}

std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d-%H-%M-%S", &tstruct);

    return buf;
}

int main(){
	int width = 320;
	int height= 240;
	int numFile = 715;
	int readInt;
	int readInt2;
	double readDouble;
	char readChar;
	string readString;
	Mat train_data(0,3,CV_32FC1);
	Mat label(0,1,CV_32SC1);
	ifstream horizon("C:/iccv09Data/horizons.txt");
	bool load = true;
	Ptr<SVM> svm = SVM::create();
	//cout << Mat() << endl;
	if(load){
		svm = Algorithm::load<SVM>("C:/iccv09Data/svm2016-04-08-23-07-29.xml");	
	} 
	else{
		for(int a = 0;a < numFile;a++){
		//cout << "a = " << a << "\n";
		horizon >> readString;
		horizon >> width;
		horizon >> height;
		horizon >> readDouble;
		String imglink = "C:/iccv09Data/image_selected/" + readString + ".jpg";
		String labellink = "C:/iccv09Data/labels/" + readString + ".regions.txt";
		ifstream labelin(labellink);
		Mat img = imread(imglink);
		Mat train_temp(width*height,3,CV_32FC1);
		Mat label_temp(width*height,1,CV_32SC1);
		if(img.data){
			
			cvtColor(img,img,CV_BGR2YCrCb);
			medianBlur(img,img,31);
			for(int y = 0;y < height;y++){
				for(int x = 0;x < width;x++){
					labelin >> readInt;
					train_temp.at<float>((y*width) + x,0) = img.at<Vec3b>(y,x)[0];
					train_temp.at<float>((y*width) + x,1) = img.at<Vec3b>(y,x)[1];
					train_temp.at<float>((y*width) + x,2) = img.at<Vec3b>(y,x)[2];
					if(readInt == 0){ label_temp.at<int>((y*width) + x,0) = 1; img.at<Vec3b>(y,x) = Vec3b(0,0,0);}
					else label_temp.at<int>((y*width) + x,0) = -1;
				}
			}
			imshow("img",img);
			waitKey(100);
			train_data.push_back(train_temp);
			label.push_back(label_temp);
		}
		
		/*while(true){
		
			readChar = waitKey(10);
			if(readChar == 'g') break;
		}*/
	}
	//cout << train_data.row << "," << train_data.col << endl;
	//cout << label.row << "," << label.col << endl;
    //svm->setType(SVM::C_SVC);
	//svm->setKernel(SVM::RBF);
    //svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6));

	//Train Data
	Ptr<TrainData> traindata =  cv::ml::TrainData::create(train_data,ROW_SAMPLE,label);

	//TRAIN
	cout << "START TRAINING\n";
	//svm->train(train_data,ROW_SAMPLE,label);
	svm->trainAuto(traindata,10);
	svm->save("C:/iccv09Data/svm" + currentDateTime() + ".xml");
	cout << "C:/iccv09Data/svm" + currentDateTime() + ".xml" << endl;
	//svm->loadFromString("C:");
	cout << "END TRAINING\n";
	}
	//PREDICT!!!
	string imgLink = "C:/Landscape/T5.jpg";
	Mat test = imread(imgLink);
	//Mat test2 = imread(imgLink);
	Mat result(height,width,CV_8UC3,Scalar(255,255,255));
	resize(test,test,Size(width,height));
	cvtColor(test,test,CV_BGR2YCrCb);
	imshow("Pre-test",test);
	waitKey(100);
	Vec3b green(0,255,0), blue (255,0,0);
	
	for (int y = 0; y < height; ++y){
		for (int x = 0; x < width; ++x)
        {
			Mat sampleMat(1,3,CV_32FC1);
			sampleMat.at<float>(0,0) = test.at<Vec3b>(y,x)[0];
			sampleMat.at<float>(0,1) = test.at<Vec3b>(y,x)[1];
			sampleMat.at<float>(0,2) = test.at<Vec3b>(y,x)[2];
			int response = svm -> predict(sampleMat);
            if (response == 1){
				//cout << "hello" << endl;
                result.at<Vec3b>(y,x)  = blue;
				//cout << "BLUE" << endl;
			}
            else if (response == -1){
				//cout << "bye" << endl;
                result.at<Vec3b>(y,x)  = green;
				//cout << "GREEN" << endl;
			}
        }
	}
	imshow("ORIGINAL",test);
	imshow("SEGMENT",result);
	readChar = waitKey(100);
	cout << "HELLOOOOOO";
	while(true);
	return 0;
}