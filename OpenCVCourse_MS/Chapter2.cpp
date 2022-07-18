#include <opencv2/imgcodecs.hpp>	// 이미지가 필요
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// 이미지처리를 사용할 때 필요
#include <iostream>					// 입력 및 출력 스트림

using namespace cv;
using namespace std;

/////////////////////////     Basic Functions     ////////////////////////////

void main() {
	string path = "Resources/test.png";		// 경로 정의, 가져올 이미지의 주소를 입력.
	Mat img = imread(path);		// Mat 클래스는 Matrix의 약자로 행렬을 표현하기 위한 데이터 형식, 여기서는 이미지의 데이터 유형을 매트로 정의
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;	// Mat 클래스의 객체 imgGray 생성, imgBlur, imgCanny 추가 생성

	cvtColor(img, imgGray, COLOR_BGR2GRAY);		// cvtColor는 이미지 컬러 공간 변환, img의 BGR 색공간을 gray-scale로 변환
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);	// 숫자는 홀수만 써야 함
	// (입력, 출력, 가우시안 커널 크기(), sigma x, sigmay, 가장자리 픽셀 확장 방식)
	Canny(imgBlur, imgCanny, 25, 75);	// 강도가 50~150 에지
		
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));		// 구조적 요소 얻기(모양_사각형, 크기)
	dilate(imgCanny, imgDil, kernel);		// 팽창, 인식을 쉽게 할 수 있게 두께를 두껍게 증가
	erode(imgDil, imgErode, kernel);		// 침식, 현재 팽창 후 침식이 들어가 클로징연산임

	imshow("Image", img);	// read한 이미지 객체 img를 화면에 나타내기 위한 함수
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilataion", imgDil);
	imshow("Image Erode", imgErode);
	waitKey(0);		// 닫기 버튼을 누를 떄 까지 종료하지 말란 함수
}


