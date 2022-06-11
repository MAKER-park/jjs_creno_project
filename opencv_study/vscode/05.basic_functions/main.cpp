#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
 
using namespace cv;
using namespace std;
 
///////////////  Basic Functions  //////////////////////
 
int main() {
 
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;
 
	cvtColor(img, imgGray, COLOR_BGR2GRAY);//색 변환
	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);//가우시안 흐림 효과 적용
	Canny(imgBlur, imgCanny, 25,75);//엣지 캐넌 
 
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);
 
	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDil);
	imshow("Image Erode", imgErode);
	waitKey(0);

    return 0;
}