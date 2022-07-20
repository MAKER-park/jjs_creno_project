//--- ROS ---------------------
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Empty.h"
#include <cv_bridge/cv_bridge.h>

//--- OpenCV ------------------
#include "opencv2/opencv.hpp"
#include <iostream>


using namespace cv;
using namespace std;

//--- ROS ----------------------------------------------------------------
void alarm_callback(const std_msgs::String& input);

class alarm_topic
{
public:
    alarm_topic()
    {
        alarm_pub = alarm_n.advertise<std_msgs::String>("/alarm", 100);
    }

    void alarm_callback(const std_msgs::String& input) {
        alarm_pub.publish(input);
    }

    ros::NodeHandle alarm_n;
    ros::Publisher alarm_pub;
};
//--------------------------------------------------------------------------

int main(void)
{
    //--- ROS ---------------------------------------------------
    ros::init(argc, argv, "alarm");
    alarm_topic alarm;
    std_msgs::String send_info;
    
    
    
    //--- OpenCV -------------------------------------------------
    VideoCapture cap("http://10.10.141.250:8081/?action=stream");
    
    QRCodeDetector detector;

    Mat frame, gray;

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
                send_info.data = info;
                alarm.alarm_callback(send_info);
            }
        }

        imshow("frame", frame);
        if (waitKey(1) == 27)
            break;
        ros::spinOnce();
    }
    return 0;
}