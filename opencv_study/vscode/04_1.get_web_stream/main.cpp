#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
 
  using namespace cv;
  using namespace std;
 
  ///////////////// Webcam ////////////////////// not test yet!
 
int main() {
    // VideoCapture cap("http://cloud.park-cloud.co19.kr:8002/");
    VideoCapture cap(1);//0:mac webcam 1: usb webcam
    Mat img;
    while (true) {
    cap.read(img);
    imshow("Image", img);
    waitKey(1);
    }
    return 0;
}