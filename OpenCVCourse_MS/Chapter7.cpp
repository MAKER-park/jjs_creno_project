#include <opencv2/imgcodecs.hpp>	// 이미지가 필요
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// 이미지처리
#include <iostream>					// 입력 및 출력 스트림

using namespace cv;
using namespace std;

/////////////////////////     Images      ////////////////////////////

Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;	// Mat 클래스의 객체 imgGray 생성

void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;	// 등고선(윤곽데이터) -> 감지된 윤곽을 점 벡터로 저장
	vector<Vec4i> hierarchy;		// 계층구조

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);	// 전처리된 바이너리 이미지를 통해 모든 윤곽선 찾기
	// 찾는 선( 입력 영상(검정과 흰색으로 구성된 바이너리 이미지), 검출된 외곽선 좌표 정보가 저장, 검출된 외곽선의 계층 정보가 저장, 윤곽 검색 모드(이미지 가장 바깥쪽만 추출), 등고선 근사법(끝 점들만 취해서 이어주기) )
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);	// 모든 프로파일 그리기
	//그릴 선(contours 나타낼 대상 이미지, img에 그릴 find의 리턴 값, 음수는 모든 외각선 그리기, RGB 색 조정, 두께)

	vector<vector<Point>> conPoly(contours.size());
	
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]); // 등고선면적(i번째 윤곽)
		cout << area << endl;

		if (area > 1000) 
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);	// 모든 프로파일 그리기
		}
	}

}

void main() {
	string path = "Resources/shapes.png";	// 경로 정의, 가져올 이미지의 주소를 입력.
	Mat img = imread(path);		// Mat 클래스는 Matrix의 약자로 행렬을 표현하기 위한 데이터 형식, 여기서는 이미지의 데이터 유형을 매트로 정의

	//------------ Preprocessing : 밑에 있는 것들이 기본적으로 '이미지 전처리' 라고 함-----
	cvtColor(img, imgGray, COLOR_BGR2GRAY);		// cvtColor는 이미지 컬러 공간 변환, img의 BGR 색공간을 gray-scale로 변환
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);	// 숫자는 홀수만 써야 함
	// (입력, 출력, 가우시안 커널 크기(), sigma x, sigmay, 가장자리 픽셀 확장 방식)
	Canny(imgBlur, imgCanny, 25, 75);	// 강도가 50~150 에지
	
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));		// 구조적 요소 얻기(모양_사각형, 크기)
	dilate(imgCanny, imgDil, kernel);		// 팽창, 인식을 쉽게 할 수 있게 두께를 두껍게 증가
	//--------------------------------------------------------------------------------------

	getContours(imgDil, img);

	imshow("Image", img);		// read한 이미지 객체 img를 화면에 나타내기 위한 함수
	//imshow("Image Gray", imgGray);
	//imshow("Image Blur", imgBlur);
	//imshow("Image Canny", imgCanny);
	//imshow("Image Dil", imgDil);

	waitKey(0);					// 닫기 버튼을 누를 떄 까지 종료하지 말란 함수
}