#include <opencv2/imgcodecs.hpp>	// �̹����� �ʿ�
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// �̹���ó���� ����� �� �ʿ�
#include <iostream>					// �Է� �� ��� ��Ʈ��

using namespace cv;
using namespace std;

/////////////////////////     Resize and Crop     ////////////////////////////

void main() {
	string path = "Resources/test.png";		// ��� ����, ������ �̹����� �ּҸ� �Է�.
	Mat img = imread(path);		// Mat Ŭ������ Matrix�� ���ڷ� ����� ǥ���ϱ� ���� ������ ����, ���⼭�� �̹����� ������ ������ ��Ʈ�� ����
	Mat imgResize, impCrop;	// Mat Ŭ���� ��ü imgResize ����, impCrop �߰� ����

	//cout << img.size() << endl;
	resize(img, imgResize, Size(640, 480));	// resize �Լ��� �̿��Ͽ� VGA ������� ����
	//resize(img, imgResize, Size(), 0.5, 0.5); x��� y���� �̿��Ͽ� ���� �� �ִ�

	Rect roi(100, 100, 300, 250); // �簢�� ���ɿ��� (x, y, width, heigt)
	impCrop = img(roi);

	imshow("Image", img);	// read�� �̹��� ��ü img�� ȭ�鿡 ��Ÿ���� ���� �Լ�
	imshow("imageResize", imgResize);
	imshow("imageCrop", impCrop);

	waitKey(0);		// �ݱ� ��ư�� ���� �� ���� �������� ���� �Լ�
}


