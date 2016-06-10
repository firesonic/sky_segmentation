//
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//namespace
//{
//    // windows and trackbars name
//    const std::string windowName = "Hough Circle Detection Demo";
//    const std::string cannyThresholdTrackbarName = "Canny threshold";
//    const std::string accumulatorThresholdTrackbarName = "Accumulator Threshold";
//    const std::string usage = "Usage : tutorial_HoughCircle_Demo <path_to_input_image>\n";
//
//    // initial and max values of the parameters of interests.
//    const int cannyThresholdInitialValue = 98;
//    const int accumulatorThresholdInitialValue = 17;
//    const int maxAccumulatorThreshold = 200;
//    const int maxCannyThreshold = 255;
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
//			cout << "row " << circles[i][1] << "column " << circles[i][0] << endl;
//			cout << src_display.at<Vec3b>(circles[i][1],circles[i][0]) << endl; 
//            // circle center
//            circle( display, center, 3, Scalar(0,255,0), -1, 8, 0 );
//            // circle outline
//            circle( display, center, radius, Scalar(0,0,255), 3, 8, 0 );
//			count++;
//
//        }
//		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
//		
//		imshow( windowName, display);
//		//waitKey(0);
//        
//    }
//}
//
//
//int main(int argc, char** argv)
//{
//    Mat src;
//
//	//for(int i = 0;i < 380;i+=5){
//	for(;;){
//    // Read the image
//		//src = imread( "C:/bouy/bouy" + to_string(i) +".png", 1 );
//		src = imread("C:/bouy/test_en_rgb.png");
//    if( src.empty() )
//    {
//        std::cerr<<"Invalid input image\n";
//        std::cout<<usage;
//        return -1;
//    }
//	imshow("color",src);
//	waitKey(1);
//	Mat src_gray(src.size().height,src.size().width,CV_8UC1);
//    // Convert it to gray
//    cvtColor( src, src_gray, COLOR_BGR2GRAY );
//	equalizeHist( src_gray, src_gray );
//	//for(int i = 0;i < src.size().height;i++){
//	//	for(int j = 0;j < src.size().width;j++){
//	//		//int temp = (((int)src.at<Vec3b>(i,j)[1]) + ((int)src.at<Vec3b>(i,j)[0]))/2;
//	//		int temp = 255 - src_gray.at<uchar>(i,j);
//	//		src_gray.at<uchar>(i,j) = temp;
//	//	}
//	//}
//    // Reduce the noise so we avoid false circle detection
//    GaussianBlur( src_gray, src_gray, Size(15,15), 2, 2 );
//	//medianBlur(src_gray,src_gray,15);
//    //declare and initialize both parameters that are subjects to change
//    int cannyThreshold = cannyThresholdInitialValue;
//    int accumulatorThreshold = accumulatorThresholdInitialValue;
//	imshow("gray_img",src_gray);
//    // create the main window, and attach the trackbars
//    namedWindow( windowName, WINDOW_AUTOSIZE );
//    createTrackbar(cannyThresholdTrackbarName, windowName, &cannyThreshold,maxCannyThreshold);
//    createTrackbar(accumulatorThresholdTrackbarName, windowName, &accumulatorThreshold, maxAccumulatorThreshold);
//
//    // infinite loop to display
//    // and refresh the content of the output image
//    // until the user presses q or Q
//    int key = 0;
//    while(key != 'q' && key != 'Q')
//    {
//        // those paramaters cannot be =0
//        // so we must check here
//        cannyThreshold = std::max(cannyThreshold, 1);
//        accumulatorThreshold = std::max(accumulatorThreshold, 1);
//
//        //runs the detection, and update the display
//        HoughDetection(src_gray, src, cannyThreshold, accumulatorThreshold);
//
//        // get user key
//        key = waitKey(1);
//    }
//	
//	}
//    return 0;
//}