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
//Mat src; Mat src_gray;
//int thresh = 100;
//int max_thresh = 255;
//RNG rng(12345);
//
///// Function header
//void thresh_callback(int, void* );
//
//int main()
//{
//  /// Load source image and convert it to gray
//for(int    i = 0;i < 385;i += 5){
//  src = imread( "C:/bouy/bouy" + to_string(i) + ".png", 1 );
//  cvtColor(src,src,CV_BGR2HSV);
//  //---enhance image---//
//  Mat channel[3];
//  split(src,channel);
//  //---delete channel---//
//  //channel[2]=Mat::zeros(src.rows, src.cols, CV_8UC1); //Set blue channel to 0
//  for(int i = 0;i < channel[0].size().height;i++){
//	  for(int j = 0;j < channel[0].size().width;j++){
//		//enhance blue//
//		int temp = channel[0].at<uchar>(i,j) * 1.45; //best 1.5
//		if(temp > 255) temp = 255;
//		channel[0].at<uchar>(i,j) = temp;
//		//enhance green//
//		temp = channel[1].at<uchar>(i,j) * 1.0; //best 0.8
//		if(temp > 255) temp = 255;
//		channel[1].at<uchar>(i,j) = temp;
//		//enhance red//
//		//temp = channel[2].at<uchar>(i,j) * 1.5;
//		temp = 127;
//		if(temp > 255) temp = 255;
//		channel[2].at<uchar>(i,j) = temp;
//		//---end---//
//	   }
//  }
//  merge(channel,3,src);
//  cvtColor(src,src,CV_HSV2BGR);
//  imshow("Enhance Src",src);
//  /// Convert image to gray and blur it 
//  cvtColor( src, src_gray, COLOR_BGR2GRAY );
//  //---Add more contrast---///
//  //equalizeHist( src_gray, src_gray );
//  //---Blur src---//
//  //medianBlur( src_gray, src_gray, 9);
//  GaussianBlur(src_gray, src_gray, Size(5,5), 2,2);
//  imshow("Contrast_src",src_gray);
//
//  /// Create Window
//  char* source_window = "Source";
//  namedWindow( source_window, WINDOW_AUTOSIZE );
//  imshow( source_window, src );
//
//  createTrackbar( " Canny thresh:", "Source", &thresh, max_thresh, thresh_callback );
//  thresh_callback( 0, 0 );
//
//  waitKey(0);
//	}
//  return(0);
//}
//
//
//void thresh_callback(int, void* )
//{
//  Mat canny_output;
//  vector<vector<Point> > contours;
//  vector<Vec4i> hierarchy;
//
//  /// Detect edges using canny
//  Canny( src_gray, canny_output, thresh, thresh*2, 3 );
//  /// Find contours
//  findContours( canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
//
//  		/// Get the moments
//  vector<Moments> mu(contours.size() );
//  for( int i = 0; i < contours.size(); i++ )
//     { mu[i] = moments( contours[i], false ); }
//
//  ///  Get the mass centers:
//  vector<Point2f> mc( contours.size() );
//  for( int i = 0; i < contours.size(); i++ )
//     { mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 ); }
//
//  /// Draw contours
//  Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
//  for( int i = 0; i< contours.size(); i++ )
//     {
//       //Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
//		 Scalar color = Scalar(255,255,255);
//	   //drawContours( drawing, contours, i, color, CV_FILLED );
//	   circle( drawing, mc[i], 4, color, -1, 8, 0 );
//     }
//
//  /// Show in a window
//  namedWindow( "Contours", WINDOW_AUTOSIZE );
//  imshow( "Contours", drawing );
//}