#include <opencv2/imgcodecs.hpp>	// �̹����� �ʿ�
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// �̹���ó��
#include <iostream>					// �Է� �� ��� ��Ʈ��

using namespace cv;
using namespace std;

vector<vector<int>> myColors{ {85,127,113,179,255,255}, // blue
							  {15,83,139,43,255,255} }; // Yellow
//vector<Scalar> myColorValues{ {0, 0, 255}, {255,255,0} }; // blue, Yellow

Mat img, imgDil;	// Mat Ŭ������ ��ü img ����

void getContours(Mat imgDil) {

	vector<vector<Point>> contours;	// ���(����������) -> ������ ������ �� ���ͷ� ����
	vector<Vec4i> hierarchy;		// ��������

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);	// ��ó���� ���̳ʸ� �̹����� ���� ��� ������ ã��
	// ã�� ��( �Է� ����(������ ������� ������ ���̳ʸ� �̹���), ���� �� ���ͷ� ����, ������ ��� ����, ���� �˻� ���(�̹��� ���� �ٱ��ʸ� ����), ��� �ٻ��(�� ���鸸 ���ؼ� �̾��ֱ�) )
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 5);	// ��� �������� �׸���
	//�׸� ��(contours ��Ÿ�� ��� �̹���, img�� �׸� find�� ���� ��, ������ ��� �ܰ��� �׸���, RGB �� ����, �β�)

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		//cout << area << endl;

		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size()); // �ʷϻ� �׸�

		if ((area > 300) || (5000 < area))
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			//cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]); //  �������� ������ �ѷ��δ� �簢���� ���(conPoly[i]�� �ּ� ũ�� �簢��) -> ��� �簢�� �Լ��� Rect ����ü�� ��ȯ

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);	// ��� �������� �׸���

			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
		}
		if (area > 3000)
		{
			//-- x ���弱
			line(img, boundRect[i].tl(), Point(0, boundRect[i].tl().y), Scalar(255, 255, 0), 5);
			line(img, boundRect[i].tl(), Point(720, boundRect[i].tl().y), Scalar(255, 255, 0), 5);
			line(img, boundRect[i].br(), Point(0, boundRect[i].br().y), Scalar(255, 255, 0), 5);
			line(img, boundRect[i].br(), Point(720, boundRect[i].br().y), Scalar(255, 255, 0), 5);

			//-- y ���弱
			line(img, boundRect[i].tl(), Point(boundRect[i].tl().x, 0), Scalar(255, 255, 0), 5);
			line(img, boundRect[i].tl(), Point(boundRect[i].tl().x, 480), Scalar(255, 255, 0), 5);
			line(img, boundRect[i].br(), Point(boundRect[i].br().x, 0), Scalar(255, 255, 0), 5);
			line(img, boundRect[i].br(), Point(boundRect[i].br().x, 480), Scalar(255, 255, 0), 5);

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

void main() {

	//VideoCapture cap("http://cloud.park-cloud.co19.kr:8091/?action=stream");
	//VideoCapture cap("http://10.10.141.250:8080/?action=stream");
	VideoCapture cap(0);  // ��ķ ���� ��� ī�޶��� id ��ȣ�� �־�� ��, �ϳ��� ���� ��� 0 ���� ����


	while (true) {

		cap.read(img);
		findColor(img);

		imshow("Image", img);

		waitKey(1);				// �ʹ� ������ �ʵ��� 1ms �� �۵�
	}
}