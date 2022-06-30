// simple_camera.cpp
// MIT License
// Copyright (c) 2019-2022 JetsonHacks
// See LICENSE for OpenCV license and additional information
// Using a CSI camera (such as the Raspberry Pi Version 2) connected to a 
// NVIDIA Jetson Nano Developer Kit using OpenCV
// Drivers for the camera and OpenCV are included in the base image

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

std::string gstreamer_pipeline (int sensor_id, int capture_width, int capture_height,  int display_width, int display_height, int framerate, int flip_method)
{
	return "nvarguscamerasrc sensor-id=" + std::to_string(sensor_id) +
		" ! video/x-raw(memory:NVMM), width=(int)" + std::to_string(capture_width) + 
		", height=(int)" + std::to_string(capture_height) +
		", framerate=(fraction)" + std::to_string(framerate) +
		"/1 ! nvvidconv flip-method=" + std::to_string(flip_method) +
		" ! video/x-raw, width=(int)" + std::to_string(display_width) +
		", height=(int)" + std::to_string(display_height) +
		", format=(string)BGRx ! videoconvert ! video/x-raw, format=(string)BGR ! appsink";
}

int main()
{
    int sensor_id = 0;
    int capture_width = 1280 ;
    int capture_height = 720 ;
    int display_width = 1280 ;
    int display_height = 720 ;
    int framerate = 60 ;
    int flip_method = 0 ;
    
    //CSI port0
    std::string pipeline0 = gstreamer_pipeline(sensor_id, capture_width,
	capture_height, display_width, display_height, framerate, flip_method);
    std::cout << "Using pipeline: \n\t" << pipeline0 << endl;

    cv::VideoCapture cap0(pipeline0, cv::CAP_GSTREAMER);
     if(!cap0.isOpened()) {
	    cout<<"Failed to open camera0."<< std::endl;
	    return (-1);
    }
    

    //CSI port1
    sensor_id = 1;
    std::string pipeline1 = gstreamer_pipeline(sensor_id, capture_width,
	capture_height,	display_width, display_height, framerate, flip_method);
    std::cout << "Using pipeline: \n\t" << pipeline1 << std::endl;
 
    cv::VideoCapture cap1(pipeline1, cv::CAP_GSTREAMER);    
    if(!cap1.isOpened()) {
	    std::cout<<"Failed to open camera1."<<std::endl;
	    return (-1);
    }

    cv::namedWindow("CSI Camera_0", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("CSI Camera_1", cv::WINDOW_AUTOSIZE);

    cv::Mat img_0;
    cv::Mat img_1;

    std::cout << "Hit ESC to exit" << "\n" ;
    while(true)
    {
    	if (!cap0.read(img_0)) {
		    std::cout<<"Capture read0 error"<< std::endl;
		    break;
	    }
        if (!cap1.read(img_1)) {
		    std::cout<<"Capture read1 error"<< std::endl;
		    break;
	    }
	
	cv::imshow("CSI Camera_0",img_0);
    cv::imshow("CSI Camera_1",img_1);
	int keycode = cv::waitKey(10) & 0xff ; 
        if (keycode == 27) break ;
    }

    cap0.release();
    cap1.release();
    cv::destroyAllWindows() ;
    return 0;
}


