#include <opencv2/imgcodecs.hpp>	// 이미지가 필요
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// 이미지처리
#include <iostream>					// 입력 및 출력 스트림

using namespace cv;
using namespace std;

Rect r1;
Rect r2;
Rect r3;

vector<vector<int>> myColors{ {85,127,113,179,255,255}, // blue
							  {0,0,234,77,255,255} }; // Yellow
//vector<Scalar> myColorValues{ {0, 0, 255}, {255,255,0} }; // blue, Yellow
Mat img, imgDil;	// Mat 클래스의 객체 img 생성

void getContours(Mat imgDil) {

	vector<vector<Point>> contours;	// 등고선(윤곽데이터) -> 감지된 윤곽을 점 벡터로 저장
	vector<Vec4i> hierarchy;		// 계층구조

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);	// 전처리된 바이너리 이미지를 통해 모든 윤곽선 찾기
	// 찾는 선( 입력 영상(검정과 흰색으로 구성된 바이너리 이미지), 윤곽 점 벡터로 저장, 선택적 출력 벡터, 윤곽 검색 모드(이미지 가장 바깥쪽만 추출), 등고선 근사법(끝 점들만 취해서 이어주기) )
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 5);	// 모든 프로파일 그리기
	//그릴 선(contours 나타낼 대상 이미지, img에 그릴 find의 리턴 값, 음수는 모든 외각선 그리기, RGB 색 조정, 두께)

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		//cout << area << endl;
		

		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size()); // 초록색 네모

		if ((area > 300) || (5000 < area))
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			//cout << conPoly[i].size() << endl;

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);	// 모든 프로파일 그리기
			//line(img, conPoly[i][0], conPoly[i][3], Scalar(255, 255, 0), 5);
			
			boundRect[i] = boundingRect(conPoly[i]); //  윤곽선의 경계면을 둘러싸는 사각형을 계산(conPoly[i]로 최소 크기 사각형) -> 경계 사각형 함수는 Rect 구조체를 반환
			//rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
		}

		if (area < 1000)
		{
			rectangle(img, Point(boundRect[i].tl().x, boundRect[i].tl().y), Point(boundRect[i].br().x, boundRect[i].br().y), Scalar(255, 255, 0), 5);
			r1 = Rect(Point(boundRect[i].tl().x, boundRect[i].tl().y), Point(boundRect[i].br().x, boundRect[i].br().y));
		}

		if (area > 1500)
		{	
			//---경고, 위험 사각 생성
			rectangle(img, Point(boundRect[i].tl().x - 50, boundRect[i].tl().y - 50), Point(boundRect[i].br().x + 50, boundRect[i].br().y + 50), Scalar(0, 000, 255), 5); // 경고
			r2 = Rect(Point(boundRect[i].tl().x - 50, boundRect[i].tl().y - 50), Point(boundRect[i].br().x + 50, boundRect[i].br().y + 50));

			rectangle(img, Point(boundRect[i].tl().x - 100, boundRect[i].tl().y - 100), Point(boundRect[i].br().x + 100, boundRect[i].br().y + 100), Scalar(0, 255, 255), 5); // 위험
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
	//VideoCapture cap(0);  // 웹캠 같은 경우 카메라의 id 번호를 넣어야 함, 하나만 있을 경우 0 으로 가능


	while (true) {

		cap.read(img);
		findColor(img);

		imshow("Image", img);

		waitKey(1);				// 너무 느리지 않도록 1ms 로 작동
	}
}