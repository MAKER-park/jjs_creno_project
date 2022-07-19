#include <opencv2/imgcodecs.hpp>	// �̹����� �ʿ�
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// �̹���ó��
#include <iostream>					// �Է� �� ��� ��Ʈ��

using namespace cv;
using namespace std;

Rect r1;
Rect r2;
Rect r3;

vector<vector<int>> myColors{ {85,127,113,179,255,255}, // blue
							  {0,0,234,77,255,255} }; // Yellow
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

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);	// ��� �������� �׸���
			//line(img, conPoly[i][0], conPoly[i][3], Scalar(255, 255, 0), 5);
			
			boundRect[i] = boundingRect(conPoly[i]); //  �������� ������ �ѷ��δ� �簢���� ���(conPoly[i]�� �ּ� ũ�� �簢��) -> ��� �簢�� �Լ��� Rect ����ü�� ��ȯ
			//rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
		}

		if (area < 1000)
		{
			rectangle(img, Point(boundRect[i].tl().x, boundRect[i].tl().y), Point(boundRect[i].br().x, boundRect[i].br().y), Scalar(255, 255, 0), 5);
			r1 = Rect(Point(boundRect[i].tl().x, boundRect[i].tl().y), Point(boundRect[i].br().x, boundRect[i].br().y));
		}

		if (area > 1500)
		{	
			//---���, ���� �簢 ����
			rectangle(img, Point(boundRect[i].tl().x - 50, boundRect[i].tl().y - 50), Point(boundRect[i].br().x + 50, boundRect[i].br().y + 50), Scalar(0, 000, 255), 5); // ���
			r2 = Rect(Point(boundRect[i].tl().x - 50, boundRect[i].tl().y - 50), Point(boundRect[i].br().x + 50, boundRect[i].br().y + 50));

			rectangle(img, Point(boundRect[i].tl().x - 100, boundRect[i].tl().y - 100), Point(boundRect[i].br().x + 100, boundRect[i].br().y + 100), Scalar(0, 255, 255), 5); // ����
			r3 = Rect(Point(boundRect[i].tl().x - 100, boundRect[i].tl().y - 100), Point(boundRect[i].br().x + 100, boundRect[i].br().y + 100));
			

		}
		
		Rect warning = r1 & r3;
		Rect danger = r1 & r2;
		/*cout << "r1 : " << r1 << endl;
		cout << "r2 : " << r2 << endl;
		cout << "r3 : " << r3 << endl;
		cout << "r4 : " << warning.area() << endl;*/


		if (warning.area() > 0 && danger.area() == 0)
		{
			cout << "Warning" << endl;
		}
		if (warning.area() > 0 && danger.area() > 0)
		{
			cout << "Danger" << endl;
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
	VideoCapture cap("http://10.10.141.250:8080/?action=stream");
	//VideoCapture cap(0);  // ��ķ ���� ��� ī�޶��� id ��ȣ�� �־�� ��, �ϳ��� ���� ��� 0 ���� ����


	while (true) {

		cap.read(img);
		findColor(img);

		imshow("Image", img);

		waitKey(1);				// �ʹ� ������ �ʵ��� 1ms �� �۵�
	}
}