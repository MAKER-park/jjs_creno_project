#include <opencv2/imgcodecs.hpp>	// �̹����� �ʿ�
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// �̹���ó���� ����� �� �ʿ�
#include <iostream>					// �Է� �� ��� ��Ʈ��

using namespace cv;
using namespace std;

/////////////////////////     Basic Functions     ////////////////////////////

void main() {
	string path = "Resources/test.png";		// ��� ����, ������ �̹����� �ּҸ� �Է�.
	Mat img = imread(path);		// Mat Ŭ������ Matrix�� ���ڷ� ����� ǥ���ϱ� ���� ������ ����, ���⼭�� �̹����� ������ ������ ��Ʈ�� ����
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;	// Mat Ŭ������ ��ü imgGray ����, imgBlur, imgCanny �߰� ����

	cvtColor(img, imgGray, COLOR_BGR2GRAY);		// cvtColor�� �̹��� �÷� ���� ��ȯ, img�� BGR �������� gray-scale�� ��ȯ
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);	// ���ڴ� Ȧ���� ��� ��
	// (�Է�, ���, ����þ� Ŀ�� ũ��(), sigma x, sigmay, �����ڸ� �ȼ� Ȯ�� ���)
	Canny(imgBlur, imgCanny, 25, 75);	// ������ 50~150 ����
		
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));		// ������ ��� ���(���_�簢��, ũ��)
	dilate(imgCanny, imgDil, kernel);		// ��â, �ν��� ���� �� �� �ְ� �β��� �β��� ����
	erode(imgDil, imgErode, kernel);		// ħ��, ���� ��â �� ħ���� �� Ŭ��¡������

	imshow("Image", img);	// read�� �̹��� ��ü img�� ȭ�鿡 ��Ÿ���� ���� �Լ�
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilataion", imgDil);
	imshow("Image Erode", imgErode);
	waitKey(0);		// �ݱ� ��ư�� ���� �� ���� �������� ���� �Լ�
}


