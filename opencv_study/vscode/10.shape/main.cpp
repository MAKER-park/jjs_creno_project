#include "opencv2/opencv.hpp" 
#include <iostream>  
#include <string> 


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
	Mat img_input, img_result, img_gray;



	//--- INITIALIZE VIDEOCAPTURE
	VideoCapture cap;
	// open the default camera using default API
	// cap.open(0);
	// OR advance usage: select any API backend
	int deviceID = 0;             // 0 = open default camera
	int apiID = cv::CAP_ANY;      // 0 = autodetect default API
					      // open selected camera using selected API
	cap.open("http://cloud.park-cloud.co19.kr:8091/?action=stream");
	// check if we succeeded
	if (!cap.isOpened()) {
		cerr << "ERROR! Unable to open camera\n";
		return -1;
	}




	for (;;)
	{

		cap.read(img_input);
		// check if we succeeded
		if (img_input.empty()) {
			cerr << "ERROR! blank frame grabbed\n";
			break;
		}

		Mat img_temp;
		//그레이스케일 이미지로 변환  
		cvtColor(img_input, img_temp, COLOR_BGR2GRAY);
		GaussianBlur(img_temp, img_temp, Size(7, 7), 0, 0);   


		//이진화 이미지로 변환
		adaptiveThreshold(img_temp, img_gray,
			255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 
			185, 3);                                  // <-----------------------   parameter 1,  2

		//contour를 찾는다.
		vector<vector<Point> > contours;
		findContours(img_gray, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

		//contour를 근사화한다.
		vector<Point2f> approx;
		img_result = img_input.clone();

		for (size_t i = 0; i < contours.size(); i++)
		{
			approxPolyDP(Mat(contours[i]), approx, arcLength(Mat(contours[i]), true)*0.02, true);

			if (fabs(contourArea(Mat(approx))) > 1000 && fabs(contourArea(Mat(approx)))< 10000)  // <-----------------------   parameter 3
			{

				int size = approx.size();
				const char *name[]= { "none", "none", "none", "triangle", "quadrangle", "pentagon", "hexagon", "heptagon", "octagon", "nonagon", "decagon"  };

                cout << "size : " << size << endl;
				switch (size){

					case 4: case 5:
					case 6: case 10:
                    case 7: case 8:
                    case 9: case 11:
						if (isContourConvex(Mat(approx))) { // convex 인지 검사 

                            cout << "get!!" << endl;
							//Contour를 근사화한 직선을 그린다.
							if (size % 2 == 0) {
								line(img_result, approx[0], approx[approx.size() - 1], Scalar(0, 255, 0), 3);

								for (int k = 0; k < size - 1; k++)
									line(img_result, approx[k], approx[k + 1], Scalar(0, 255, 0), 3);

								for (int k = 0; k < size; k++)
									circle(img_result, approx[k], 3, Scalar(0, 0, 255));
							}
							else {
								line(img_result, approx[0], approx[approx.size() - 1], Scalar(0, 255, 0), 3);

								for (int k = 0; k < size - 1; k++)
									line(img_result, approx[k], approx[k + 1], Scalar(0, 255, 0), 3);

								for (int k = 0; k < size; k++)
									circle(img_result, approx[k], 3, Scalar(0, 0, 255));
							}


							//검출된 도형에 대한 라벨을 출력한다.

							setLabel(img_result, name[size], contours[i]);
						}

						break;
						


					deafult:

						break;
				}


			}



		}


		// show window and wait for a key with timeout long enough to show images
		imshow("result", img_result);
		imshow("binary", img_gray);

		if (waitKey(5) == 27) //ESC 키 누를 때 까지 대기
			break;
		
	}

	return 0;
}