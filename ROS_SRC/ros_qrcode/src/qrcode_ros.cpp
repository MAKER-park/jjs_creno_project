//--- ROS ---------------------
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Empty.h"
#include <cv_bridge/cv_bridge.h>

//--- OpenCV ------------------
#include <opencv2/opencv.hpp>
#include <iostream>

#include <unistd.h>

using namespace cv;
using namespace std;

//--- ROS ----------------------------------------------------------------
void alarm_qr_callback(const std_msgs::String& input);

class alarm_topic_qr
{
public:
    alarm_topic_qr()
    {
        alarm_pub1 = alarm_n.advertise<std_msgs::String>("/QR_Code",100);
        alarm_pub2 = alarm_n.advertise<std_msgs::String>("/QR_Signal",100);
    }

    void alarm_qr_callback1(const std_msgs::String& input) {
        alarm_pub1.publish(input);
    }
    void alarm_qr_callback2(const std_msgs::String& input) {
        alarm_pub2.publish(input);
    }
    ros::NodeHandle alarm_n;
    ros::Publisher alarm_pub1;
    ros::Publisher alarm_pub2;

};
//--------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    //--- ROS ---------------------------------------------------
    ros::init(argc, argv, "qrcode");
    alarm_topic_qr qrcode;
    std_msgs::String send_info;
    std_msgs::String send_signal;
    
    //--- OpenCV -------------------------------------------------
    VideoCapture cap("http://10.10.141.250:8081/?action=stream");
    
    QRCodeDetector detector;

    Mat frame, gray;

    while (true)
    { 
	    ros::spinOnce();
		cap.read(frame);
        if (frame.empty()) {
            cerr << "frame load failed!" << endl;
            return -1;
        }
		
        cvtColor(frame, gray, COLOR_BGR2GRAY);
		
        vector<Point> points;

	        if (detector.detect(gray, points)){ {
	        polylines(frame, points, true, Scalar(0, 255, 255), 2);
		}
            String signal = "0";

			String info = detector.decode(gray, points);
            if (!info.empty()) {
                polylines(frame, points, true, Scalar(0, 0, 255), 2);
                cout << "Decoded Data : " << info << endl;
                send_info.data = info;
                qrcode.alarm_qr_callback1(send_info);
				signal = "1";
            }
				send_signal.data = signal;
				qrcode.alarm_qr_callback2(send_signal);
        }

        imshow("frame", frame);
		waitKey(1);
        if (waitKey(1) == 27)
            break;
 }
    return 0;
}
