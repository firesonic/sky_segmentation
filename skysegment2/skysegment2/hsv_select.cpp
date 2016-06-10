//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/video/tracking.hpp"
//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//
//using namespace cv;
//using namespace std;
//
//int thresh_h_down = 0;
//int thresh_h_up = 180;
//int max_thresh_h = 180;
//int thresh_s_down = 0;
//int thresh_s_up = 255;
//int max_thresh_s = 255;
//int thresh_v_down = 132;
//int thresh_v_up = 255;
//int max_thresh_v = 255;
//RNG rng(12345);
//Mat src,hsv_src;
//String windowName = "test";
//void thresh_callback(int, void* )
//{
//	for(int i = 0;i < 386;i+=1){
//		src = imread("C:/bouy/bouy" + to_string(i) + ".png");
//		cvtColor(src,hsv_src,CV_BGR2HSV);
//		Mat show,src_gray,canny_output;
//		inRange(hsv_src,Vec3b(thresh_h_down,thresh_s_down,thresh_v_down),Vec3b(thresh_h_up,thresh_s_up,thresh_v_up),show);
//		cvtColor(src,src_gray,CV_BGR2GRAY);
//		int thresh = 80;
//		//Canny( src_gray, canny_output, thresh, thresh*2, 3 );
//		//imshow("Canny",canny_output);
//		imshow("inRange",show);
//		vector<vector<Point> > contours;
//		vector<Vec4i> hierarchy;
//		findContours( show, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
//		Mat drawing = Mat::zeros( show.size(), CV_8UC3 );
//		/// Get the moments
//  vector<Moments> mu(contours.size() );
//  for( int i = 0; i < contours.size(); i++ )
//     { mu[i] = moments( contours[i], false ); }
//
//  ///  Get the mass centers:
//  vector<Point2f> mc( contours.size() );
//  for( int i = 0; i < contours.size(); i++ )
//     { mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 ); }
//  for( int i = 0; i< contours.size(); i++ )
//     {
//		 if(mu[i].m00 < 30) continue;
//		  //approxPolyDP(contours[i], approxShape, arcLength(Mat(contours[i]), true)*0.04, true);
//       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
//	   drawContours( drawing, contours, i, color, CV_FILLED );
//	   circle( drawing, mc[i], 4, color, -1, 8, 0 );
//     }
//
//  /// Show in a window
//  namedWindow( "Contours", WINDOW_AUTOSIZE );
//  imshow( "Contours", drawing );
//		waitKey(10);
//	}
//}
//
//int main(){
//	src = imread("C:/bouy/bouy200.png");
//	cvtColor(src,hsv_src,CV_BGR2HSV);
//	namedWindow( windowName, WINDOW_AUTOSIZE );
//	createTrackbar( " h max:", windowName, &thresh_h_up, max_thresh_h, thresh_callback );
//	createTrackbar( " h min:", windowName, &thresh_h_down, max_thresh_h, thresh_callback );
//	createTrackbar( " s max:", windowName, &thresh_s_up, max_thresh_s, thresh_callback );
//	createTrackbar( " s min:", windowName, &thresh_s_down, max_thresh_s, thresh_callback );
//	createTrackbar( " v max:", windowName, &thresh_v_up, max_thresh_v, thresh_callback );
//	createTrackbar( " v min:", windowName, &thresh_v_down, max_thresh_v, thresh_callback );
//	thresh_callback(0,0);
//	waitKey(0);
//	return 0;
//}