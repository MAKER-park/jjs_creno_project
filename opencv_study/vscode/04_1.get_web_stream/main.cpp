#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
 
  using namespace cv;
  using namespace std;
 
  ///////////////// Webcam ////////////////////// not test yet!
 
int main() {
    // VideoCapture cap("http://cloud.park-cloud.co19.kr:8002/");
    // VideoCapture cap(1);//0:mac webcam 1: usb webcam
    // VideoCapture cap("http://10.10.141.101:8080/?action=snapshot");//0:mac webcam 1: usb webcam snapshot = > 정지 영상
    VideoCapture cap("http://10.10.141.101:8080/?action=stream");//0:mac webcam 1: usb webcam stream = > 실시간 영상
    Mat img;
    while (true) {
    cap.read(img);
    imshow("Image_for_web", img);
    waitKey(1);
    }
    return 0;
}