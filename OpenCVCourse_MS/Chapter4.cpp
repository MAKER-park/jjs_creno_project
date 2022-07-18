#include <opencv2/imgcodecs.hpp>	// 이미지가 필요
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// 이미지처리를 사용할 때 필요
#include <iostream>					// 입력 및 출력 스트림

using namespace cv;
using namespace std;

/////////////////////////     Draw Shapes and Text     ////////////////////////////

void main() {

	//Blank Image
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255)); // (width, height, 8비트 unsigned 3채널, BGR)

	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);	// 원(이미지, 중심점(위 창의 절반 값), 원 크기, BGR, 두께)
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED); 
	//사각형 (이미지, (왼쪽 위 모서리 x값, Y값), (오른쪽 아래 모서리 x값, Y값), RGB, 두께)
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);
	//라인 (이미지, (왼쪽 x값, Y값), (오른쪽 x값, Y값), RGB, 두께) -> Y값을 변경하면 사선으로 그릴 수 있다

	putText(img, "MoonSeok's Workshop", Point(132, 262), FONT_HERSHEY_DUPLEX, 0.7, Scalar(0, 69, 255), 2);

	imshow("Image", img);	// read한 이미지 객체 img를 화면에 나타내기 위한 함수


	waitKey(0);		// 닫기 버튼을 누를 떄 까지 종료하지 말란 함수
}


