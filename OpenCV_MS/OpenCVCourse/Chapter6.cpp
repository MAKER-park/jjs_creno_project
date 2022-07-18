#include <opencv2/imgcodecs.hpp>	// �̹����� �ʿ�
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// �̹���ó��
#include <iostream>					// �Է� �� ��� ��Ʈ��

using namespace cv;
using namespace std;

/////////////////////////    Color Detection      ////////////////////////////

Mat imgHSV, mask;
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

void main() {
	string path = "Resources/lambo.png";	// ��� ����, ������ �̹����� �ּҸ� �Է�.
	Mat img = imread(path);		// Mat Ŭ������ Matrix�� ���ڷ� ����� ǥ���ϱ� ���� ������ ����, ���⼭�� �̹����� ������ ������ ��Ʈ�� ����

	cvtColor(img, imgHSV, COLOR_BGR2HSV);		// cvtColor�� �̹��� �÷� ���� ��ȯ, img�� BGR �������� HSV�� ��ȯ

	namedWindow("Trackbars", (640, 200));		// ������â ���� �Լ�(�̸�, ũ��)
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);		// (Ʈ���� �̸�, �� ������ â, ������ ���� ������ �ּ�, �ִ밪)
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);		// Hue�� �ִ� ���� 180�̰�, Sat, Val �ִ� ���� 256
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {

		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);	// (�Է� ���, ���� �� ��� �Ǵ� ��Į��, ���� �� ��� �Ǵ� ��Į��, �Է� ����� ���� ũ���� ����ũ ����.)

		imshow("Image", img);		// read�� �̹��� ��ü img�� ȭ�鿡 ��Ÿ���� ���� �Լ�
		imshow("Image HSV", imgHSV);
		imshow("Image Mask", mask);
		waitKey(1);					// �ݱ� ��ư�� ���� �� ���� �������� ���� �Լ�
	}


}