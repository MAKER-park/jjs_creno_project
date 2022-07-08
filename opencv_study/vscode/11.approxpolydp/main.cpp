#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;


//Contour 영역 내에 텍스트 쓰기 
//https://github.com/bsdnoobz/opencv-code/blob/master/shape-detect.cpp
void setLabel(Mat& image, string str, vector<Point> contour)
{
	int fontface = FONT_HERSHEY_SIMPLEX;
	double scale = 0.5;
	int thickness = 1;
	int baseline = 0;

	Size text = getTextSize(str, fontface, scale, thickness, &baseline);
	Rect r = boundingRect(contour);

	Point pt(r.x + ((r.width - text.width) / 2), r.y + ((r.height + text.height) / 2));
	rectangle(image, pt + Point(0, baseline), pt + Point(text.width, -text.height), CV_RGB(200, 200, 200), FILLED);
	putText(image, str, pt, fontface, scale, CV_RGB(0, 0, 0), thickness, 8);
}

int main(int, char**)
{
    //Mat frame;
    VideoCapture cap;
    // OR advance usage: select any API backend
    int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_V4L2;      // 0 = autodetect default API
    cap.open("http://10.10.141.250:8080/?action=stream");
	// cap.open("http://cloud.park-cloud.co19.kr:8091/?action=stream");
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
	namedWindow("Canny", WINDOW_AUTOSIZE);

	createTrackbar("Low Threshold","Canny",0,500);
	createTrackbar("High Threshold","Canny",0,500);

	setTrackbarPos("Low Threshold","Canny",50);
	setTrackbarPos("High Threshold","Canny",150);

    //--- GRAB AND WRITE LOOP
    cout << "Start grabbing" << endl
        << "Press any key to terminate" << endl;
    for (;;)
    {
		// wait for a new frame from camera and store it into 'frame'
		Mat img_input, img_result, img_gray;
		cap.read(img_input);
		int Low = getTrackbarPos("Low threshold", "Canny");
		int High = getTrackbarPos("High threshold", "Canny");
		
		// check if we succeeded
	    if (img_input.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }

		cvtColor(img_input, img_gray, COLOR_BGR2GRAY);

		Mat binary_image; 
		threshold(img_gray, img_gray, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
		GaussianBlur(img_gray, img_gray, Size(5, 5), 0, 0);   

		//이진화 이미지로 변환
		adaptiveThreshold(img_gray, img_gray,
			255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 
			21, 7);  

		morphologyEx(img_gray, img_gray, MORPH_OPEN, Mat());//morphologyEx close()->fail

		vector<vector<Point> > contours;
	   	findContours(img_gray, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
		
		vector<Point2f> approx;
		img_result = img_input.clone();
		for (size_t i = 0; i < contours.size(); i++)
	   	{
			approxPolyDP(Mat(contours[i]), approx, arcLength(Mat(contours[i]), true)*0.02, true);

			if (fabs(contourArea(Mat(approx))) > 100){
				int size = approx.size();
                const char *name[]= { "none", "none", "none", "container", "container", "container", "container", "container", "none", "none", "none"  };
                // cout << "size : " << size << endl;
                if(size > 4 && size < 9){//5개 이상일때 
				if (size % 2 == 0)
			   	{ 
					line(img_result, approx[0], approx[approx.size() - 1], Scalar(0, 255, 0), 3); 
					for (int k = 0; k < size - 1; k++) 
						line(img_result, approx[k], approx[k + 1], Scalar(0, 255, 0), 3); 
					for (int k = 0; k < size; k++) 
						circle(img_result, approx[k], 3, Scalar(0, 0, 255));
			   	} else { 
					line(img_result, approx[0], approx[approx.size() - 1], Scalar(0, 255, 0), 3); 
					for (int k = 0; k < size - 1; k++) 
						line(img_result, approx[k], approx[k + 1], Scalar(0, 255, 0), 3); 
					for (int k = 0; k < size; k++) 
						circle(img_result, approx[k], 3, Scalar(0, 0, 255));
				}
                setLabel(img_result,name[size], contours[i]);
                }
                
			}
		}

        // show live and wait for a key with timeout long enough to show images
        //rotate(img_canny,img_canny,ROTATE_180);
        // rotate(img_result,img_result,ROTATE_180);
        imshow("gray", img_gray);
        imshow("result", img_result);
        if (waitKey(5) >= 0)
            break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
