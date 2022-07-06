#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
 
  using namespace cv;
  using namespace std;

  void setLabel(Mat& img, const vector<Point>& pts, const String& label)
{
    Rect rc = boundingRect(pts);
    rectangle(img, rc, Scalar(0,0,255), 1);
    putText(img, label, rc.tl(), FONT_HERSHEY_PLAIN, 1, Scalar(0,0,255));
}

 
int main() {
    // VideoCapture cap("http://cloud.park-cloud.co19.kr:8002/");
    // VideoCapture cap(1);//0:mac webcam 1: usb webcam
    VideoCapture cap("http://cloud.park-cloud.co19.kr:8091/?action=stream");//0:mac webcam 1: usb webcam snapshot = > 정지 영상
    // VideoCapture cap("http://10.10.141.250:8080/?action=stream");//0:mac webcam 1: usb webcam stream = > 실시간 영상

    //track bar - canny
    namedWindow("Canny", WINDOW_AUTOSIZE);
    createTrackbar("Low Threshold", "Canny", 0, 500);
	createTrackbar("High Threshold", "Canny", 0, 500);

    setTrackbarPos("Low Threshold", "Canny", 25);
	setTrackbarPos("High Threshold", "Canny", 40);

    namedWindow("Houghp", WINDOW_AUTOSIZE);
    createTrackbar("radian", "Houghp", 0, 359);
	createTrackbar("threshold", "Houghp", 0, 150);
    createTrackbar("min_line_length", "Houghp", 0, 255);
	createTrackbar("max_line_gap", "Houghp", 0, 255);

    setTrackbarPos("radian", "Houghp", 180);
    setTrackbarPos("threshold", "Houghp", 180);
    setTrackbarPos("min_line_length", "Houghp", 180);
    setTrackbarPos("max_line_gap", "Houghp", 180);
    //--------------tack bar init ---------------------

    Mat img;

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
    double radian = getTrackbarPos("radian", "Houghp");
	int threshold_hough = getTrackbarPos("threshold", "Houghp");
    int min_line_length = getTrackbarPos("min_line_length", "Houghp");
	int max_line_gap = getTrackbarPos("max_line_gap", "Houghp");
	// HoughLinesP(img_canny, linesP, 1, (CV_PI / 180), 70, 3, 5);
    HoughLinesP(img_canny, linesP, 1, (CV_PI / 180), threshold_hough, min_line_length, max_line_gap);
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

    //-----------------outline test--------------------
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    Mat bin;
    threshold(gray, bin, 200, 255, THRESH_BINARY_INV | THRESH_OTSU);

    vector<vector<Point>> contours;
    findContours(bin, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);

    for(vector<Point> pts : contours){
        if(contourArea(pts) < 400) continue;

        vector<Point> approx;
        approxPolyDP(pts, approx, arcLength(pts, true)*0.02, true);

        int vtc = (int)approx.size();

        if(vtc == 3)
            setLabel(img, pts, "TRI");
        else if(vtc == 4)
            setLabel(img, pts, "RECT");
        else{
            double len = arcLength(pts, true);
            double area = contourArea(pts, true);
            double ratio = 4. * CV_PI * area / (len * len);

            if(ratio > 0.85){
                setLabel(img, pts, "CIR");
            }
        }
    }

    imshow("img_result",img);

    waitKey(1);
    }
    return 0;
}