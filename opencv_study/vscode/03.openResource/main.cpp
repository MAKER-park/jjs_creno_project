#include <iostream>
//add heaeder
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    string path = "Resources/test.png";
    Mat img = imread(path);
    cout << img << endl;
    imshow("Image", img);
    waitKey(0);
    return 0;
}