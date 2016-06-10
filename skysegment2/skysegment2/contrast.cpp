//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <iostream>
//
//using namespace cv;
//
//double alpha = 1.3; /**< Simple contrast control */
//int beta = 0;  /**< Simple brightness control */
//
//int main()
//{
// /// Read image given by user
// Mat image = imread("C:/bouy/test_rg.png");
// Mat new_image = Mat::zeros( image.size(), image.type() );
//
// /// Initialize values
// //std::cout<<" Basic Linear Transforms "<<std::endl;
// //std::cout<<"-------------------------"<<std::endl;
// //std::cout<<"* Enter the alpha value [1.0-3.0]: ";std::cin>>alpha;
// //std::cout<<"* Enter the beta value [0-100]: "; std::cin>>beta;
//
// /// Do the operation new_image(i,j) = alpha*image(i,j) + beta
// for( int y = 0; y < image.rows; y++ )
//    { for( int x = 0; x < image.cols; x++ )
//         { for( int c = 0; c < 3; c++ )
//              {
//      new_image.at<Vec3b>(y,x)[c] =
//         saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta );
//             }
//    }
//    }
//
// /// Create Windows
// namedWindow("Original Image", 1);
// namedWindow("New Image", 1);
// medianBlur(new_image,new_image,9);
// imwrite("C:/bouy/test_con_gb.png",new_image);
// /// Show stuff
// imshow("Original Image", image);
// imshow("New Image", new_image);
//
// /// Wait until user press some key
// waitKey();
// return 0;
//}