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
//int thresh_h = 10;
//int max_thresh_h = 20;
//int thresh_s = 10;
//int max_thresh_s = 20;
//int thresh_v = 127;
//int max_thresh_v = 255;
//int thresh_b = 2;
//int max_thresh_b = 100;
//int thresh_c = 0;
//int max_thresh_c = 30;
//int H_1 = 7;
//int max_H1 = 200;
//int H_2 = 177;
//int max_H2 = 255;
//RNG rng(12345);
//String windowName = "hello";
///// Function header
//void thresh_callback(int, void* );
//
//    void HoughDetection(const Mat& src_gray, const Mat& src_display, int cannyThreshold, int accumulatorThreshold)
//    {
//        // will hold the results of the detection
//        std::vector<Vec3f> circles;
//        // runs the actual detection
//        HoughCircles( src_gray, circles, HOUGH_GRADIENT, 1, src_gray.rows/8, cannyThreshold, accumulatorThreshold, 0, 0 );
//
//        // clone the colour, input image for displaying purposes
//        Mat display = src_display.clone();
//		int count = 1;
//        for( size_t i = 0; i < circles.size(); i++ )
//        {
//			String temp = to_string(count);
//            Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
//            int radius = cvRound(circles[i][2]);
//			putText(display,temp,center,FONT_HERSHEY_SIMPLEX,1,Scalar(255,255,255));
//			//cout << "row " << circles[i][1] << "column " << circles[i][0] << endl;
//			//cout << src_display.at<Vec3b>(circles[i][1],circles[i][0]) << endl; 
//            // circle center
//            circle( display, center, 3, Scalar(0,255,0), -1, 8, 0 );
//            // circle outline
//            circle( display, center, radius, Scalar(0,0,255), 3, 8, 0 );
//			count++;
//        }
//		
//		imshow( "Hough", display);
//		waitKey(1);
//        
//    }
//
//
//int main()
//{
//  src = imread("C:/bouy/bouy200.png");
//
//  /// Create Window
//  namedWindow( windowName, WINDOW_AUTOSIZE );
//  //imshow(windowName);
//
//  //createTrackbar( " H factor:", windowName, &thresh_h, max_thresh_h, thresh_callback );
// // createTrackbar( " S factor:", windowName, &thresh_s, max_thresh_s, thresh_callback );
//  //createTrackbar( " V value:", windowName, &thresh_v, max_thresh_v, thresh_callback );
//  createTrackbar( " B value:", windowName, &thresh_b, max_thresh_b, thresh_callback );
//  createTrackbar( " C value:", windowName, &thresh_c, max_thresh_c, thresh_callback );
//  //createTrackbar( " H1 value:", windowName, &H_1, max_H1, thresh_callback );
//  //createTrackbar( " H2 value:", windowName, &H_2, max_H2, thresh_callback );
//  //thresh_callback( 0, 0 );
//
//  waitKey(0);
//  return(0);
//}
//
//void thresh_callback(int, void* )
//{
//  Mat hsv_src;
//  for(int a = 0;a < 386; a+= 1){
//  src = imread("C:/bouy/bouy" + to_string(a) + ".png");
//  cvtColor(src,hsv_src,CV_BGR2HSV);
//  Mat channel[3];
//  split(hsv_src,channel);
//    for(int i = 0;i < channel[0].size().height;i++){
//	  for(int j = 0;j < channel[0].size().width;j++){
//		//enhance H//
//		  int temp = channel[0].at<uchar>(i,j) * (thresh_h * 0.1); //best 1.5
//		if(temp > 255) temp = 255;
//		channel[0].at<uchar>(i,j) = temp;
//		//enhance S//
//		temp = channel[1].at<uchar>(i,j) * (thresh_s * 0.1); //best 0.8
//		if(temp > 255) temp = 255;
//		channel[1].at<uchar>(i,j) = temp;
//		//enhance V//
//		//temp = channel[2].at<uchar>(i,j) * 1.5;
//		temp = thresh_v;
//		if(temp > 255) temp = 255;
//		channel[2].at<uchar>(i,j) = temp;
//		//---end---//
//	   }
//  }
//	Mat adt_src,gry_src;
//	merge(channel,3,hsv_src);
//	cvtColor(hsv_src,src,CV_HSV2BGR);
//	cvtColor(src,gry_src,CV_BGR2GRAY);
//	GaussianBlur(gry_src,gry_src,Size(9,9),2,2);
//	equalizeHist( gry_src, gry_src );
//	imshow("gray",gry_src);
//	//medianBlur(src,src,15);
//	adaptiveThreshold(gry_src, adt_src , 255, ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY_INV, 2*thresh_b + 1, thresh_c);
//  imshow( "Enhance", src );
//  imshow( "Threshold", adt_src);
//  
//  vector<vector<Point> > contours;
//  vector<Vec4i> hierarchy;
//  findContours( adt_src, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
//
//   /// Get the moments
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
//  Mat drawing = Mat::zeros( adt_src.size(), CV_8UC3 );
//  for( int i = 0; i< contours.size(); i++ )
//     {
//		if(mu[i].m00 > 800 ) continue;
//		Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
//		drawContours( drawing, contours, i, color,CV_FILLED );
//		 circle( drawing, mc[i], 4, Scalar(255,255,255), -1, 8, 0 );
//
//     }
//
//  /// Show in a window
//  namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
//  imshow( "Contours", drawing );
//
//  waitKey(100);
//  }
//}