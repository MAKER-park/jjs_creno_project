#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;



int threshold1 = 30;

Vec3b lower_blue1, upper_blue1, lower_blue2, upper_blue2, lower_blue3, upper_blue3;
Mat img_color;

void mouse_callback(int event, int x, int y, int flags, void *param)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		Vec3b color_pixel = img_color.at<Vec3b>(y, x);

		Mat bgr_color = Mat(1, 1, CV_8UC3, color_pixel);


		Mat hsv_color;
		cvtColor(bgr_color, hsv_color, COLOR_BGR2HSV);

		int hue = hsv_color.at<Vec3b>(0, 0)[0];
		int saturation = hsv_color.at<Vec3b>(0, 0)[1];
		int value = hsv_color.at<Vec3b>(0, 0)[2];

		cout << "hue = " << hue << endl;
		cout << "saturation = " << saturation << endl;
		cout << "value = " << value << endl;


		if (hue < 10)
		{
			cout << "case 1" << endl;
			lower_blue1 = Vec3b(hue - 10 + 180, threshold1, threshold1);
			upper_blue1 = Vec3b(180, 255, 255);
			lower_blue2 = Vec3b(0, threshold1, threshold1);
			upper_blue2 = Vec3b(hue, 255, 255);
			lower_blue3 = Vec3b(hue, threshold1, threshold1);
			upper_blue3 = Vec3b(hue+10, 255, 255);
		}
		else if (hue > 170)
		{
			cout << "case 2" << endl;
			lower_blue1 = Vec3b(hue, threshold1, threshold1);
			upper_blue1 = Vec3b(180, 255, 255);
			lower_blue2 = Vec3b(0, threshold1, threshold1);
			upper_blue2 = Vec3b(hue + 10 - 180, 255, 255);
			lower_blue3 = Vec3b(hue - 10, threshold1, threshold1);
			upper_blue3 = Vec3b(hue, 255, 255);
		}
		else
		{
			cout << "case 3" << endl;
			lower_blue1 = Vec3b(hue, threshold1, threshold1);
			upper_blue1 = Vec3b(hue + 10, 255, 255);
			lower_blue2 = Vec3b(hue - 10, threshold1, threshold1);
			upper_blue2 = Vec3b(hue, 255, 255);
			lower_blue3 = Vec3b(hue - 10, threshold1, threshold1);
			upper_blue3 = Vec3b(hue, 255, 255);
		}

		cout << "hue = " << hue << endl;
		cout << "#1 = " << lower_blue1 << "~" << upper_blue1 << endl;
		cout << "#2 = " << lower_blue2 << "~" << upper_blue2 << endl;
		cout << "#3 = " << lower_blue3 << "~" << upper_blue3 << endl;
	}
}



int main()
{
	namedWindow("img_color");
	setMouseCallback("img_color", mouse_callback);
	

	Mat img_hsv;

	VideoCapture cap("http://10.10.141.101:8080/?action=stream");
	if (!cap.isOpened()) {

		cout << "카메라를 열 수 없습니다." << endl;
		return -1;
	}


	while(1)
	{
		cap.read(img_color);

		cvtColor(img_color, img_hsv, COLOR_BGR2HSV);

		Mat img_mask1, img_mask2, img_mask3, img_mask;
		inRange(img_hsv, lower_blue1, upper_blue1, img_mask1);
		inRange(img_hsv, lower_blue2, upper_blue2, img_mask2);
		inRange(img_hsv, lower_blue3, upper_blue3, img_mask3);
		img_mask = img_mask1 | img_mask2 | img_mask3;

		
		Mat img_result;
		bitwise_and(img_color, img_color, img_result, img_mask);

		imshow("img_color", img_color);
		imshow("img_mask", img_mask);
		imshow("img_result", img_result);

		if (waitKey(1)>0)
			break;
	}


	return 0;
}