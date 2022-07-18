#include <opencv2/imgcodecs.hpp>	// 이미지가 필요
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// 이미지처리
#include <iostream>					// 입력 및 출력 스트림

using namespace cv;
using namespace std;

/////////////////////////    Color Detection      ////////////////////////////

Mat imgHSV, mask;
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

void main() {
	string path = "Resources/lambo.png";	// 경로 정의, 가져올 이미지의 주소를 입력.
	Mat img = imread(path);		// Mat 클래스는 Matrix의 약자로 행렬을 표현하기 위한 데이터 형식, 여기서는 이미지의 데이터 유형을 매트로 정의

	cvtColor(img, imgHSV, COLOR_BGR2HSV);		// cvtColor는 이미지 컬러 공간 변환, img의 BGR 색공간을 HSV로 변환

	namedWindow("Trackbars", (640, 200));		// 윈도우창 생성 함수(이름, 크기)
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);		// (트랙바 이름, 들어갈 윈도우 창, 변경할 값을 저장할 주소, 최대값)
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);		// Hue는 최대 값이 180이고, Sat, Val 최대 값은 256
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackbars", &smax, 255);
	createTrackbar("Val Min", "Trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {

		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);	// (입력 행렬, 하한 값 행렬 또는 스칼라, 상한 값 행렬 또는 스칼라, 입력 영상과 같은 크기의 마스크 영상.)

		imshow("Image", img);		// read한 이미지 객체 img를 화면에 나타내기 위한 함수
		imshow("Image HSV", imgHSV);
		imshow("Image Mask", mask);
		waitKey(1);					// 닫기 버튼을 누를 떄 까지 종료하지 말란 함수
	}


}