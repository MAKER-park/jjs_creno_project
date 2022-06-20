#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
 
  using namespace cv;
  using namespace std;
 
  ///////////////// Webcam ////////////////////// not test yet!
 
// int main() {
//     VideoCapture cap(0);
//     Mat img;
//     while (true) {
//     cap.read(img);
//     imshow("Image", img);
//     waitKey(1);
//     }
//     return 0;
// }
int main() {
    VideoCapture cap("/Users/bagjaewan/Documents/GitHub/jjs_creno_project/opencv_study/vscode/04.access_camera/test.mp4");
    Mat img;
    while (true) {
    cap.read(img); 
    imshow("Image", img);
    waitKey(1);
    }
    return 0;
}