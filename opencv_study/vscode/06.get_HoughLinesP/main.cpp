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
    VideoCapture cap("http://10.10.141.250:8080/?action=stream");//0:mac webcam 1: usb webcam stream = > 실시간 영상

    //track bar
    namedWindow("Canny", WINDOW_AUTOSIZE);
    createTrackbar("Low Threshold", "Canny", 0, 500);
	createTrackbar("High Threshold", "Canny", 0, 500);
    setTrackbarPos("Low Threshold", "Canny", 25);
	setTrackbarPos("High Threshold", "Canny", 40);
    //--------------tack bar init ---------------------

    Mat img;
    cout << "test" << endl;
    while (true) {
    cap.read(img);
    Mat img_gray;
	cvtColor(img, img_gray, COLOR_BGR2GRAY);
    Mat img_canny;

    //test ------------------------------------
    vector<Vec4i> linesP_canny;
    int Low = getTrackbarPos("Low Threshold", "Canny");
	int High = getTrackbarPos("High Threshold", "Canny");
	Canny(img_gray, img_canny, Low, High);//150,255
    imshow("img_canny", img_canny);
    //test ------------------------------------

    vector<Vec4i> linesP;
	HoughLinesP(img_canny, linesP, 1, (CV_PI / 180), 70, 3, 5);
    Mat img_houghP;
	img.copyTo(img_houghP);
    Mat img_lane;
	threshold(img_canny, img_lane, 80, 200, THRESH_MASK);//150,255

    for (size_t i = 0; i < linesP.size(); i++)
	{
		Vec4i l = linesP[i];
		line(img_houghP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2, 8);
		line(img_lane, Point(l[0], l[1]), Point(l[2], l[3]), Scalar::all(255), 1, 8);
        putText(img_houghP,"test",Point(l[0], l[1]), FONT_HERSHEY_PLAIN, 1,Scalar(0,255,0),2);
	}

    // imshow("Image_for_web", img);
    imshow("img_houghP", img_houghP);
	imshow("img_lane", img_lane);

    waitKey(1);
    }
    return 0;
}