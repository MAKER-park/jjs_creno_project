#include <opencv2/imgcodecs.hpp>	// �̹����� �ʿ�
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// �̹���ó��
#include <iostream>					// �Է� �� ��� ��Ʈ��

using namespace cv;
using namespace std;

/////////////////////////     Images      ////////////////////////////

//void main() {
//	string path = "Resources/test.png";	// ��� ����, ������ �̹����� �ּҸ� �Է�.
//	Mat img = imread(path);		// Mat Ŭ������ Matrix�� ���ڷ� ����� ǥ���ϱ� ���� ������ ����, ���⼭�� �̹����� ������ ������ ��Ʈ�� ����
//	imshow("Image", img);		// read�� �̹��� ��ü img�� ȭ�鿡 ��Ÿ���� ���� �Լ�
//	waitKey(0);					// �ݱ� ��ư�� ���� �� ���� �������� ���� �Լ�
//}

/////////////////////////     Video      ////////////////////////////

//void main() {
//	string path = "Resources/test_video.mp4";	// ������ ���� ���� 
//	VideoCapture cap(path);	// ĸó ��ü cap�� ����
//	Mat img;	// Mat Ŭ������ ��ü img ����
//
//
//	while (true) {
//
//		cap.read(img);
//		
//		imshow("Image", img);
//		waitKey(1);				// 1ms �� �۵�, �ӵ��� ���߰� �ʹٸ� (20) �Է�
//	}
//}


/////////////////////////     Wepcam      ////////////////////////////

void main() {
	
	VideoCapture cap(0); // ��ķ ���� ��� ī�޶��� id ��ȣ�� �־�� ��, �ϳ��� ���� ��� 0 ���� ����
	Mat img;	// Mat Ŭ������ ��ü img ����


	while (true) {

		cap.read(img);

		imshow("Image", img);
		waitKey(1);				// �ʹ� ������ �ʵ��� 1ms �� �۵�
	}
}
