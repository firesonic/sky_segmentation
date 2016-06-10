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
//int thresh_h_down = 0;
//int thresh_h_up = 180;
//int thresh_s_down = 0;
//int thresh_s_up = 255;
//int thresh_v_down = 132;
//int thresh_v_up = 255;
//RNG rng(12345);
//
//double cal_dis(double x1,double y1, double x2, double y2){
//	double dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
//	return dis;
//
//}
//
//void match_center(vector<Point2f>& src_center, vector<Point2f>& prv_src_center,Mat &src, Mat &prv_src){
//	double min; int min_index;
//	for(int i = 0;i < src_center.size();i++){
//		for(int j = 0;j < prv_src_center.size();j++){
//			double temp = cal_dis(src_center[i].x,src_center[i].y,prv_src_center[j].x,prv_src_center[j].y);
//			if(j == 0) { min = temp; min_index = j; }
//			else if( temp < min) { min = temp; min_index = j; }
//		}
//		//putText(src,to_string(min_index),src_center[i],FONT_HERSHEY_SIMPLEX,1,Scalar(0,255,0));
//	}
//	for(int i= 0;i < prv_src_center.size();i++){
//		//putText(prv_src,to_string(i),prv_src_center[i],FONT_HERSHEY_SIMPLEX,1,Scalar(0,255,0));
//	}
//}
//
//int main(){
//	Mat src,prv_src;
//	Mat gry_src,gry_prv_src;
//	src = imread("C:/bouy/bouy200.png");
//	prv_src = imread("C:/bouy/bouy199.png");
//	cvtColor(src,src,CV_BGR2HSV);
//	cvtColor(prv_src,prv_src,CV_BGR2HSV);
//	inRange(src,Vec3b(thresh_h_down,thresh_s_down,thresh_v_down),Vec3b(thresh_h_up,thresh_s_up,thresh_v_up),src);
//	inRange(prv_src,Vec3b(thresh_h_down,thresh_s_down,thresh_v_down),Vec3b(thresh_h_up,thresh_s_up,thresh_v_up),prv_src);
//	imshow("src",src);
//	imshow("prv_src",prv_src);
//
//	vector<vector<Point> > src_contours;
//	vector<vector<Point> > prv_src_contours;
//
//		vector<Vec4i> src_hierarchy;
//		vector<Vec4i> prv_src_hierarchy;
//		findContours( src, src_contours, src_hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
//		findContours( prv_src, prv_src_contours, prv_src_hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
//		Mat src_drawing = Mat::zeros( src.size(), CV_8UC3 );
//		Mat prv_src_drawing = Mat::zeros( prv_src.size(), CV_8UC3 );
//		/// Get the moments
//  vector<Moments> src_mu(src_contours.size() );
//  vector<Moments> prv_src_mu(prv_src_contours.size() );
//  vector<RotatedRect> src_minRect( src_contours.size() );
//  vector<RotatedRect> prv_src_minRect( prv_src_contours.size() );
//    for( int i = 0; i < src_contours.size(); i++ )
//     { src_minRect[i] = minAreaRect( Mat(src_contours[i]) );
//     }
//	for( int i = 0; i < prv_src_contours.size(); i++ )
//     { prv_src_minRect[i] = minAreaRect( Mat(prv_src_contours[i]) );
//     }
//  for( int i = 0; i < src_contours.size(); i++ )
//     { src_mu[i] = moments( src_contours[i], false ); }
//  for( int i = 0; i < prv_src_contours.size(); i++ )
//     { prv_src_mu[i] = moments( prv_src_contours[i], false ); }
//  ///  Get the mass centers:
//  vector<Point2f> src_mc( src_contours.size() );
//  vector<Point2f> prv_src_mc( prv_src_contours.size() );
//  for( int i = 0; i < src_contours.size(); i++ )
//     { src_mc[i] = Point2f( src_mu[i].m10/src_mu[i].m00 , src_mu[i].m01/src_mu[i].m00 ); }
//  for( int i = 0; i < prv_src_contours.size(); i++ )
//     { prv_src_mc[i] = Point2f( prv_src_mu[i].m10/prv_src_mu[i].m00 , prv_src_mu[i].m01/prv_src_mu[i].m00 ); }
//  for( int i = src_contours.size()-1; i>= 0; i-- )
//     {
//		 if(src_mu[i].m00 < 30) {
//			 src_contours.erase(src_contours.begin() + i);
//			 src_mc.erase(src_mc.begin()+i);
//			 src_mu.erase(src_mu.begin()+i);
//			 src_minRect.erase(src_minRect.begin()+i);
//			 continue;
//		 }
//		  Point2f src_rect_points[4]; src_minRect[i].points( src_rect_points );
//		  double rect_width = sqrt((src_rect_points[0].x - src_rect_points[1].x)*(src_rect_points[0].x - src_rect_points[1].x) + (src_rect_points[0].y - src_rect_points[1].y)*(src_rect_points[0].y - src_rect_points[1].y));
//		 double rect_height = sqrt((src_rect_points[2].x - src_rect_points[1].x)*(src_rect_points[2].x - src_rect_points[1].x) + (src_rect_points[2].y - src_rect_points[1].y)*(src_rect_points[2].y - src_rect_points[1].y)) ;
//		 double ratio;
//		 if(rect_width > rect_height) ratio = rect_width/rect_height;
//		 else  ratio = rect_height/rect_width;
//		 cout << "src_contour[" << i << "] width = " << rect_width << " height = " << rect_height << endl; 
//		 if(ratio > 3){
//			src_contours.erase(src_contours.begin() + i);
//			 src_mc.erase(src_mc.begin()+i);
//			 src_mu.erase(src_mu.begin()+i);
//			 src_minRect.erase(src_minRect.begin()+i);
//			 continue;
//		 }
//		 
//		 //approxPolyDP(contours[i], approxShape, arcLength(Mat(contours[i]), true)*0.04, true);
//       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
//	   drawContours( src_drawing, src_contours, i, color, CV_FILLED );
//	    circle( src_drawing, src_mc[i], 4, Scalar(255,255,255), -1, 8, 0 );
//       // rotated rectangle
//       for( int j = 0; j < 4; j++ )
//          line( src_drawing, src_rect_points[j], src_rect_points[(j+1)%4], Scalar(255,255,255), 1, 8 );
//	   putText(src_drawing,to_string(i),src_mc[i],FONT_HERSHEY_SIMPLEX,1,Scalar(0,255,0));
//     }
//  for( int i = prv_src_contours.size() - 1; i>=0; i-- )
//     {
//		 if(contourArea(prv_src_contours[i]) < 30) {
//			 prv_src_contours.erase(prv_src_contours.begin() + i);
//			 prv_src_mc.erase(prv_src_mc.begin()+i);
//			 prv_src_mu.erase(prv_src_mu.begin()+i);
//			 prv_src_minRect.erase(prv_src_minRect.begin()+i);
//			 continue;
//		 }
//		 Point2f prv_src_rect_points[4]; prv_src_minRect[i].points( prv_src_rect_points );
//		  double rect_width = sqrt((prv_src_rect_points[0].x - prv_src_rect_points[1].x)*(prv_src_rect_points[0].x - prv_src_rect_points[1].x) + (prv_src_rect_points[0].y - prv_src_rect_points[1].y)*(prv_src_rect_points[0].y - prv_src_rect_points[1].y));
//		 double rect_height = sqrt((prv_src_rect_points[2].x - prv_src_rect_points[1].x)*(prv_src_rect_points[2].x - prv_src_rect_points[1].x) + (prv_src_rect_points[2].y - prv_src_rect_points[1].y)*(prv_src_rect_points[2].y - prv_src_rect_points[1].y)) ;
//		 double ratio;
//		 if(rect_width > rect_height) ratio = rect_width/rect_height;
//		 else  ratio = rect_height/rect_width;
//		 cout << "contour area: " << contourArea(prv_src_contours[i]) << endl;
//		 cout << "prv_src_contour[" << i << "] width = " << rect_width << " height = " << rect_height << endl;
//		 if(ratio > 2.5){
//			 prv_src_contours.erase(prv_src_contours.begin() + i);
//			 prv_src_mc.erase(prv_src_mc.begin()+i);
//			 prv_src_mu.erase(prv_src_mu.begin()+i);
//			 prv_src_minRect.erase(prv_src_minRect.begin()+i);
//			 continue;
//		 }
//		  
//		  //approxPolyDP(contours[i], approxShape, arcLength(Mat(contours[i]), true)*0.04, true);
//       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
//	   drawContours( prv_src_drawing, prv_src_contours, i, color, CV_FILLED );
//	    circle( prv_src_drawing, prv_src_mc[i], 4, Scalar(255,255,255), -1, 8, 0 );
//		for( int j = 0; j < 4; j++ )
//          line( prv_src_drawing, prv_src_rect_points[j], prv_src_rect_points[(j+1)%4], Scalar(255,255,255), 1, 8 );
//		putText(prv_src_drawing,to_string(i),prv_src_mc[i],FONT_HERSHEY_SIMPLEX,1,Scalar(0,255,0));
//     }
//  match_center(src_mc,prv_src_mc,src_drawing,prv_src_drawing);
//  imshow("src_draw",src_drawing);
//  imshow("prv_src_draw",prv_src_drawing);
//	waitKey(0);
//	return 0;
//
//}