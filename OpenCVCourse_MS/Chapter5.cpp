#include <opencv2/imgcodecs.hpp>	// 이미지가 필요
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// 이미지처리
#include <iostream>					// 입력 및 출력 스트림

using namespace cv;
using namespace std;

/////////////////////////     Warp Images      ////////////////////////////

float w = 250, h = 350;
Mat matrix, imgWarp;

void main() {

	string path = "Resources/cards.jpg";	// 경로 정의, 가져올 이미지의 주소를 입력.
	Mat img = imread(path);		// Mat 클래스는 Matrix의 약자로 행렬을 표현하기 위한 데이터 형식, 여기서는 이미지의 데이터 유형을 매트로 정의

	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} }; // (첫번째 시작 점 ), (두번째 점의 x축, Y축), (세번째 점의 x축, Y축), (네번째)

	matrix = getPerspectiveTransform(src, dst);		// 원근 변환 행렬(초기 좌표 배열, 결과 좌표 배열)
	warpPerspective(img, imgWarp, matrix, Point(w, h)); // (인풋, 아웃풋 , 위 함수에서 반환된 행렬, 크기)
	
	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);	// 원(이미지, 중심점(위 창의 절반 값), 원 크기, BGR, 두께)
	}

	imshow("Image", img);		// read한 이미지 객체 img를	화면에 나타내기 위한 함수
	imshow("Image warp", imgWarp);
	waitKey(0);					// 닫기 버튼을 누를 떄 까지 종료하지 말란 함수
}

