#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

int thresh_h_down = 0;
int thresh_h_up = 180;
int thresh_s_down = 0;
int thresh_s_up = 255;
int thresh_v_down = 132;
int thresh_v_up = 255;
RNG rng(12345);
vector<Point2f> center_track;
vector<int> flag_track;
vector<int> count_track;

double cal_dis(double x1,double y1, double x2, double y2){
	double dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	return dis;
}

void match_center(vector<Point2f>& src_center,Mat &src){
	double min; int min_index;
	if(center_track.empty()){
		for(int i = 0;i < src_center.size();i++){
			center_track.push_back(src_center[i]);
			flag_track.push_back(1);
			count_track.push_back(1);
		}
		return;
	}
	bool first_time = true;
	vector<Point2f> for_add;
	vector<Point2f> center_match(center_track.size());
	vector<double> dis_match(center_track.size());
	for(int i = 0;i < src_center.size();i++){
		for(int j = 0;j < center_track.size();j++){
			if(flag_track[j] == 0) continue;
			double temp = cal_dis(src_center[i].x,src_center[i].y,center_track[j].x,center_track[j].y);
			if(first_time){
				min = temp; min_index = j; first_time = false;
			}
			else if(temp < min){
				min = temp; min_index = j;
			}
		}
		first_time = true;
		if(min > 50){
			for_add.push_back(src_center[i]);
			continue;
		}
		if(min < dis_match[min_index] || dis_match[min_index] == 0){
			center_match[min_index] = src_center[i];
			dis_match[min_index] = min;
		}
	}

	/////update center_track
	for(int i = 0;i < dis_match.size();i++){
		if(dis_match[i] == 0) { cout << "skip\n"; continue; }
		//cout << "change center from " << center_track[i] << " to " << center_match[i] << " with dis: " << dis_match[i] << endl;
		center_track[i] = center_match[i];
		count_track[i]++;
	}
	for(int i = 0;i < for_add.size();i++){
		//cout << "add new center\n";
		center_track.push_back(for_add[i]);
		flag_track.push_back(1);
		count_track.push_back(1);
	}
}

void track_center(Mat &src){
	cvtColor(src,src,CV_BGR2HSV);
	inRange(src,Vec3b(thresh_h_down,thresh_s_down,thresh_v_down),Vec3b(thresh_h_up,thresh_s_up,thresh_v_up),src);
	imshow("src",src);
	vector<vector<Point> > src_contours;
	vector<Vec4i> src_hierarchy;
	findContours( src, src_contours, src_hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
	Mat src_drawing = Mat::zeros( src.size(), CV_8UC3 );
	////fit rotate Rect///////
	vector<RotatedRect> src_minRect( src_contours.size() );
    for( int i = 0; i < src_contours.size(); i++ )
		{ src_minRect[i] = minAreaRect( Mat(src_contours[i]) ); }
	////Get the moments
	vector<Moments> src_mu(src_contours.size() );
	for( int i = 0; i < src_contours.size(); i++ )
		{src_mu[i] = moments( src_contours[i], false ); }
	////Get the mass centers:
	vector<Point2f> src_mc( src_contours.size() );
	for( int i = 0; i < src_contours.size(); i++ )
		{src_mc[i] = Point2f( src_mu[i].m10/src_mu[i].m00 , src_mu[i].m01/src_mu[i].m00 ); }
	cout << "all " << src_mc.size() << endl;
	for( int i = src_contours.size()-1; i>= 0; i-- ){
		 if(src_mu[i].m00 < 30) {
			 src_contours.erase(src_contours.begin()+i);
			 src_mc.erase(src_mc.begin()+i);
			 src_mu.erase(src_mu.begin()+i);
			 src_minRect.erase(src_minRect.begin()+i);
			 continue;
		 }
		 Point2f src_rect_points[4]; src_minRect[i].points( src_rect_points );
		 ////Calculate width,height,ration of Rect/////////
		 double rect_width = sqrt((src_rect_points[0].x - src_rect_points[1].x)*(src_rect_points[0].x - src_rect_points[1].x) + (src_rect_points[0].y - src_rect_points[1].y)*(src_rect_points[0].y - src_rect_points[1].y));
		 double rect_height = sqrt((src_rect_points[2].x - src_rect_points[1].x)*(src_rect_points[2].x - src_rect_points[1].x) + (src_rect_points[2].y - src_rect_points[1].y)*(src_rect_points[2].y - src_rect_points[1].y)) ;
		 double ratio;
		 if(rect_width > rect_height) ratio = rect_width/rect_height;
		 else  ratio = rect_height/rect_width;
		 //////////////////////////////////////////////////
		 if(ratio > 2.5){
			 src_contours.erase(src_contours.begin() + i);
			 src_mc.erase(src_mc.begin()+i);
			 src_mu.erase(src_mu.begin()+i);
			 src_minRect.erase(src_minRect.begin()+i);
			 continue;
		 }
		 //cout << "src_contour[" << i << "] width = " << rect_width << " height = " << rect_height << endl; 
		 //cout << "ratio " << ratio << endl; 
		Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
		drawContours( src_drawing, src_contours, i, color, CV_FILLED );
	    circle( src_drawing, src_mc[i], 4, Scalar(255,255,255), -1, 8, 0 );
		//////Draw Rotated rectangle////////////
		for( int j = 0; j < 4; j++ ) line( src_drawing, src_rect_points[j], src_rect_points[(j+1)%4], Scalar(255,255,255), 1, 8 );
		putText(src_drawing,to_string(i),src_mc[i],FONT_HERSHEY_SIMPLEX,1,Scalar(0,255,0));
	}
	cout << "erase " << src_mc.size() << endl;
	match_center(src_mc,src_drawing);
	imshow("src_draw",src_drawing);
	waitKey(50);
}

void draw_track(Size & s){
	Mat show = Mat::zeros( s, CV_8UC3 );
	for(int i = 0;i < center_track.size();i++){
		if(count_track[i] <= 10) continue;
		circle( show, center_track[i], 4, Scalar(255,255,255), -1, 8, 0 );
	}
	imshow("show_track",show);
	waitKey(1);
}

int main(){
	Mat src;
	for(int i = 0;i < 386;i++){
		src = imread("C:/bouy/bouy" + to_string(i) + ".png");
		track_center(src);
		cout << center_track.size() << endl;
		draw_track(src.size());
	}
	for(int i = 0;i < center_track.size();i++){
		cout << center_track[i] << " count: " << count_track[i] << endl;
	}
	waitKey(0);
	return 0;
}