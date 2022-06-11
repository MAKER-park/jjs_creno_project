#include <iostream>
//add heaeder
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("lena.bmp");

	if (img.empty()) {
		cerr << "Image laod failed!" << endl;
		return -1;
	}

	namedWindow("image");
	imshow("image", img);
	waitKey();
	destroyAllWindows();
}