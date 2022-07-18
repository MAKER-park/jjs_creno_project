#include <opencv2/imgcodecs.hpp>	// 이미지가 필요
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// 이미지처리
#include <iostream>					// 입력 및 출력 스트림

using namespace cv;
using namespace std;

/////////////////////////     Images      ////////////////////////////

//void main() {
//	string path = "Resources/test.png";	// 경로 정의, 가져올 이미지의 주소를 입력.
//	Mat img = imread(path);		// Mat 클래스는 Matrix의 약자로 행렬을 표현하기 위한 데이터 형식, 여기서는 이미지의 데이터 유형을 매트로 정의
//	imshow("Image", img);		// read한 이미지 객체 img를 화면에 나타내기 위한 함수
//	waitKey(0);					// 닫기 버튼을 누를 떄 까지 종료하지 말란 함수
//}

/////////////////////////     Video      ////////////////////////////

//void main() {
//	string path = "Resources/test_video.mp4";	// 가져올 비디오 파일 
//	VideoCapture cap(path);	// 캡처 객체 cap에 저장
//	Mat img;	// Mat 클래스의 객체 img 생성
//
//
//	while (true) {
//
//		cap.read(img);
//		
//		imshow("Image", img);
//		waitKey(1);				// 1ms 로 작동, 속도를 늦추고 싶다면 (20) 입력
//	}
//}


/////////////////////////     Wepcam      ////////////////////////////

void main() {
	
	VideoCapture cap(0); // 웹캠 같은 경우 카메라의 id 번호를 넣어야 함, 하나만 있을 경우 0 으로 가능
	Mat img;	// Mat 클래스의 객체 img 생성


	while (true) {

		cap.read(img);

		imshow("Image", img);
		waitKey(1);				// 너무 느리지 않도록 1ms 로 작동
	}
}
