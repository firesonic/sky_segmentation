//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <iostream>
//#include <stdio.h>
//
//using namespace cv;
//using namespace std;
//
//int main(  )
//{
//  Mat src, dst;
//
//  char* source_window = "Source image";
//  char* equalized_window = "Equalized Image";
//
//  /// Load image
//  for(int i = 0;i < 380;i += 5){
//	  src = imread( "C:/bouy/bouy" + to_string(i) + ".png", 1 );
//
//  if( !src.data )
//    { cout<<"Usage: ./Histogram_Demo <path_to_image>"<<endl;
//      return -1;}
//
//  /// Convert to grayscale
//  cvtColor( src, src, CV_BGR2GRAY );
//
//  /// Apply Histogram Equalization
//  equalizeHist( src, dst );
//
//  /// Display results
//  namedWindow( source_window, CV_WINDOW_AUTOSIZE );
//  namedWindow( equalized_window, CV_WINDOW_AUTOSIZE );
//
//  imshow( source_window, src );
//  imshow( equalized_window, dst );
//  //imwrite("C:/bouy/test_eq.png",dst);
//  /// Wait until user exits the program
//  waitKey(0);
//  }
//  return 0;
//}