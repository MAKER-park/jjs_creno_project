#include <opencv2/imgcodecs.hpp>	// 이미지가 필요
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// 이미지처리를 사용할 때 필요
#include <iostream>					// 입력 및 출력 스트림

using namespace cv;
using namespace std;

/////////////////////////     Resize and Crop     ////////////////////////////

void main() {
	string path = "Resources/test.png";		// 경로 정의, 가져올 이미지의 주소를 입력.
	Mat img = imread(path);		// Mat 클래스는 Matrix의 약자로 행렬을 표현하기 위한 데이터 형식, 여기서는 이미지의 데이터 유형을 매트로 정의
	Mat imgResize, impCrop;	// Mat 클래스 객체 imgResize 생성, impCrop 추가 생성

	//cout << img.size() << endl;
	resize(img, imgResize, Size(640, 480));	// resize 함수를 이용하여 VGA 사이즈로 변경
	//resize(img, imgResize, Size(), 0.5, 0.5); x축과 y축을 이용하여 줄일 수 있다

	Rect roi(100, 100, 300, 250); // 사각형 관심영역 (x, y, width, heigt)
	impCrop = img(roi);

	imshow("Image", img);	// read한 이미지 객체 img를 화면에 나타내기 위한 함수
	imshow("imageResize", imgResize);
	imshow("imageCrop", impCrop);

	waitKey(0);		// 닫기 버튼을 누를 떄 까지 종료하지 말란 함수
}


