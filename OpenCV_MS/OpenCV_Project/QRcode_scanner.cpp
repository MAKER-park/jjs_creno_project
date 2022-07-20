#include "opencv2/opencv.hpp"
#include <iostream>


using namespace cv;
using namespace std;

int main(void)
{
    VideoCapture cap("http://10.10.141.250:8081/?action=stream");
    
    QRCodeDetector detector;

    Mat frame, gray, canny;

    while (true)
    {
        cap.read(frame);
        
        if (frame.empty()) {
            cerr << "frame load failed!" << endl;
            return -1;
        }

        cvtColor(frame, gray, COLOR_BGR2GRAY);

        vector<Point> points;

        if (detector.detect(gray, points)) {
            polylines(frame, points, true, Scalar(0, 255, 255), 2);

            String info = detector.decode(gray, points);
            if (!info.empty()) {
                polylines(frame, points, true, Scalar(0, 0, 255), 2);
                cout << "Decoded Data : " << info << endl;
            }
        }

        imshow("gray", gray);
        imshow("frame", frame);
        if (waitKey(1) == 27)
            break;
    }
    return 0;
}