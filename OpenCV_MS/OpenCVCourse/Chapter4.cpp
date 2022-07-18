#include <opencv2/imgcodecs.hpp>	// �̹����� �ʿ�
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// �̹���ó���� ����� �� �ʿ�
#include <iostream>					// �Է� �� ��� ��Ʈ��

using namespace cv;
using namespace std;

/////////////////////////     Draw Shapes and Text     ////////////////////////////

void main() {

	//Blank Image
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255)); // (width, height, 8��Ʈ unsigned 3ä��, BGR)

	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);	// ��(�̹���, �߽���(�� â�� ���� ��), �� ũ��, BGR, �β�)
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED); 
	//�簢�� (�̹���, (���� �� �𼭸� x��, Y��), (������ �Ʒ� �𼭸� x��, Y��), RGB, �β�)
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);
	//���� (�̹���, (���� x��, Y��), (������ x��, Y��), RGB, �β�) -> Y���� �����ϸ� �缱���� �׸� �� �ִ�

	putText(img, "MoonSeok's Workshop", Point(132, 262), FONT_HERSHEY_DUPLEX, 0.7, Scalar(0, 69, 255), 2);

	imshow("Image", img);	// read�� �̹��� ��ü img�� ȭ�鿡 ��Ÿ���� ���� �Լ�


	waitKey(0);		// �ݱ� ��ư�� ���� �� ���� �������� ���� �Լ�
}


