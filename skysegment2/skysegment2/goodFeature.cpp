//#include <iostream>
//#include "opencv2/opencv.hpp"
//#include <stdio.h>    
//
//using namespace cv;
//using namespace std;
//
//int main(  )
//{
//
//    Mat image,fin_img;
//    image = imread("C:/bouy/bouy200.png", CV_LOAD_IMAGE_COLOR);   // Read the file
//
//    if(! image.data )                              // Check for invalid input
//    {
//        cout <<  "Could not open or find the image" << std::endl ;
//        return -1;
//    }
//
//   namedWindow( "Display window", CV_WINDOW_AUTOSIZE );// Create a window for display.
//                      // Show our image inside it.
//
//    // Create Windows
//    //namedWindow("Red",1);
//   // namedWindow("Green",1);
//    //namedWindow("Blue",1);
//
//    // Create Matrices (make sure there is an image in input!)
//
//    Mat channel[3];
//    imshow( "Original Image", image );
//
//
//    // The actual splitting.
//    split(image, channel);
//	Mat blue[3];
//	split(image, blue);
//	Mat img2;
//	//blue[0]=Mat::zeros(image.rows, image.cols, CV_8UC1);//Set blue channel to 0
//	merge(blue,3,img2);
//	imshow("b_enhan",img2);
//   channel[0]=Mat::zeros(image.rows, image.cols, CV_8UC1);//Set blue channel to 0
//   //channel[1]=Mat::zeros(image.rows, image.cols, CV_8UC1);//Set blue channel to 0
//
//   //blue[1]=Mat::zeros(image.rows, image.cols, CV_8UC1);//Set blue channel to 0
//   for(int i = 0;i < blue[0].size().height;i++){
//	   for(int j = 0;j < blue[0].size().width;j++){
//		int temp = blue[0].at<uchar>(i,j) * 1.1;
//		if(temp > 255) temp = 255;
//		blue[0].at<uchar>(i,j) = temp;
//		temp = blue[2].at<uchar>(i,j) * 1.3;
//		if(temp > 255) temp = 255;
//		blue[2].at<uchar>(i,j) = temp;
//	   }
//   }
//
//    merge(channel,3,image);
//	imshow("MERGE", image);
//	merge(blue,3,image);
//    imshow("with BLUE",image);
//	imwrite("C:/bouy/test_en_rgb.png",image);
//	blue[2]=Mat::zeros(image.rows, image.cols, CV_8UC1);//Set blue channel to 0
//	merge(blue,3,image);
//    imshow("without BLUE",image);
//    //imwrite("dest.jpg",image);
//	imwrite("C:/bouy/test_rg.png",image);
//    waitKey(0);//Wait for a keystroke in the window
//    return 0;
//}