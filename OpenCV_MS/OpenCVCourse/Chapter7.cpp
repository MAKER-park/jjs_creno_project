#include <opencv2/imgcodecs.hpp>	// �̹����� �ʿ�
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// �̹���ó��
#include <iostream>					// �Է� �� ��� ��Ʈ��

using namespace cv;
using namespace std;

/////////////////////////     Images      ////////////////////////////

Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;	// Mat Ŭ������ ��ü imgGray ����

void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;	// ���(����������) -> ������ ������ �� ���ͷ� ����
	vector<Vec4i> hierarchy;		// ��������

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);	// ��ó���� ���̳ʸ� �̹����� ���� ��� ������ ã��
	// ã�� ��( �Է� ����(������ ������� ������ ���̳ʸ� �̹���), ����� �ܰ��� ��ǥ ������ ����, ����� �ܰ����� ���� ������ ����, ���� �˻� ���(�̹��� ���� �ٱ��ʸ� ����), ��� �ٻ��(�� ���鸸 ���ؼ� �̾��ֱ�) )
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);	// ��� �������� �׸���
	//�׸� ��(contours ��Ÿ�� ��� �̹���, img�� �׸� find�� ���� ��, ������ ��� �ܰ��� �׸���, RGB �� ����, �β�)

	vector<vector<Point>> conPoly(contours.size());
	
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]); // �������(i��° ����)
		cout << area << endl;

		if (area > 1000) 
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);	// ��� �������� �׸���
		}
	}

}

void main() {
	string path = "Resources/shapes.png";	// ��� ����, ������ �̹����� �ּҸ� �Է�.
	Mat img = imread(path);		// Mat Ŭ������ Matrix�� ���ڷ� ����� ǥ���ϱ� ���� ������ ����, ���⼭�� �̹����� ������ ������ ��Ʈ�� ����

	//------------ Preprocessing : �ؿ� �ִ� �͵��� �⺻������ '�̹��� ��ó��' ��� ��-----
	cvtColor(img, imgGray, COLOR_BGR2GRAY);		// cvtColor�� �̹��� �÷� ���� ��ȯ, img�� BGR �������� gray-scale�� ��ȯ
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);	// ���ڴ� Ȧ���� ��� ��
	// (�Է�, ���, ����þ� Ŀ�� ũ��(), sigma x, sigmay, �����ڸ� �ȼ� Ȯ�� ���)
	Canny(imgBlur, imgCanny, 25, 75);	// ������ 50~150 ����
	
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));		// ������ ��� ���(���_�簢��, ũ��)
	dilate(imgCanny, imgDil, kernel);		// ��â, �ν��� ���� �� �� �ְ� �β��� �β��� ����
	//--------------------------------------------------------------------------------------

	getContours(imgDil, img);

	imshow("Image", img);		// read�� �̹��� ��ü img�� ȭ�鿡 ��Ÿ���� ���� �Լ�
	//imshow("Image Gray", imgGray);
	//imshow("Image Blur", imgBlur);
	//imshow("Image Canny", imgCanny);
	//imshow("Image Dil", imgDil);

	waitKey(0);					// �ݱ� ��ư�� ���� �� ���� �������� ���� �Լ�
}