#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Empty.h"
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void alarm_callback(const std_msgs::String &input);

class alarm_topic
{
public:
	alarm_topic()
	{
		alarm_pub = alarm_n.advertise<std_msgs::String>("/alarm", 100);	
	}
	
	void alarm_callback(const std_msgs::String &input) {
		alarm_pub.publish(input);
	}
	
	ros::NodeHandle alarm_n; 
	ros::Publisher alarm_pub;
};


Rect r1;
Rect r2;
Rect r3;

vector<vector<int>> myColors{ {83,188,208,130,255,255}, // blue
							  {22,88,153,32,255,255} }; // Yellow
//vector<Scalar> myColorValues{ {0, 0, 255}, {255,255,0} }; // blue, Yellow
Mat img, imgDil;

void getContours(Mat imgDil) {
	
	alarm_topic alarm;
	//std_msgs::String send_warning;
	std_msgs::String send_danger;
	std_msgs::String send_Safe;
	//send_warning.data = "Warning";
	send_danger.data = "Danger";
	send_Safe.data = "Safe";

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		//cout << area << endl;


		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());

		if ((area > 300) || (5000 < area))
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			//cout << conPoly[i].size() << endl;

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			//line(img, conPoly[i][0], conPoly[i][3], Scalar(255, 255, 0), 5);

			boundRect[i] = boundingRect(conPoly[i]);
			//rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
		}

		if (area < 1000)
		{
			rectangle(img, Point(boundRect[i].tl().x, boundRect[i].tl().y), Point(boundRect[i].br().x, boundRect[i].br().y), Scalar(255, 255, 0), 5);
			r1 = Rect(Point(boundRect[i].tl().x, boundRect[i].tl().y), Point(boundRect[i].br().x, boundRect[i].br().y));
		}

		if (area > 1500)
		{
			rectangle(img, Point(boundRect[i].tl().x - 50, boundRect[i].tl().y - 50), Point(boundRect[i].br().x + 50, boundRect[i].br().y + 50), Scalar(0, 000, 255), 5); // °æ°í
			r2 = Rect(Point(boundRect[i].tl().x - 50, boundRect[i].tl().y - 50), Point(boundRect[i].br().x + 50, boundRect[i].br().y + 50));

			rectangle(img, Point(boundRect[i].tl().x - 100, boundRect[i].tl().y - 100), Point(boundRect[i].br().x + 100, boundRect[i].br().y + 100), Scalar(0, 255, 255), 5); // À§Çè
			r3 = Rect(Point(boundRect[i].tl().x - 100, boundRect[i].tl().y - 100), Point(boundRect[i].br().x + 100, boundRect[i].br().y + 100));

		}

		Rect warning = r1 & r3;
		Rect danger = r1 & r2;
		/*cout << "r1 : " << r1 << endl;
		cout << "r2 : " << r2 << endl;
		cout << "r3 : " << r3 << endl;
		cout << "r4 : " << warning.area() << endl;*/

		/*
		if (warning.area() > 0 && danger.area() == 0)
		{
			cout << "Warning" << endl;
			alarm.alarm_callback(send_warning);
		}
		*/
		if (warning.area() > 0 && danger.area() > 0)
		{
			cout << "Danger" << endl;
			alarm.alarm_callback(send_danger);
		} else {
			cout << "Safe" << endl;
			alarm.alarm_callback(send_Safe);
		}
	}
}

void findColor(Mat img)
{
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	for (int i = 0; i < myColors.size(); i++)
	{
		Scalar lower(myColors[i][0], myColors[i][1], myColors[i][2]);
		Scalar upper(myColors[i][3], myColors[i][4], myColors[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);
		getContours(mask);
	}
}

int main(int argc, char* argv[]) {

	ros::init(argc, argv, "alarm");
	alarm_topic alarm;
	//VideoCapture cap("http://cloud.park-cloud.co19.kr:8091/?action=stream");
	VideoCapture cap("http://10.10.141.250:8080/?action=stream");
	//VideoCapture cap(0);
	

	while (true) {
		
		ros::spinOnce();
		cap.read(img);
		findColor(img);
		
		imshow("Image", img);
		
		waitKey(1);
		if(waitKey(1) == 27)
				break;
	}
	return 0;
}
