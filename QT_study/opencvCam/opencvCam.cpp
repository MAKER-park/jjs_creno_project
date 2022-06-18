#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

// 문자열 출력 함수 - 그림자 효과 
//void put_string(Mat &frame, string text, Point pt, int value)
//{
//	text += to_string(value);
//	Point shade = pt + Point(2, 2);
//	int font = FONT_HERSHEY_SIMPLEX;
//	putText(frame, text, shade, font, 0.7, Scalar(0, 0, 0), 2);		// 그림자 효과
//	putText(frame, text, pt, font, 0.7, Scalar(120, 200, 90), 2);// 작성 문자
//}

int main()
{
	int cnt = 0;
	int key = 0;
	string text;
    VideoCapture capture(0);
//	VideoCapture  capture(0);
//	if (!capture.isOpened())
//	{
//		cout << "카메라가 연결되지 않았습니다." << endl;
//		exit(1);
//	}
//	cout << "너비 " << capture.get(CAP_PROP_FRAME_WIDTH) << endl;
//	cout << "높이 " << capture.get(CAP_PROP_FRAME_HEIGHT) << endl;
//	cout << "노출 " << capture.get(CAP_PROP_EXPOSURE) << endl;
//	cout << "밝기 " << capture.get(CAP_PROP_BRIGHTNESS) << endl;
	
//	for (;;) {
//		Mat frame, gray;
//		capture.read(frame);

////		put_string(frame, "EXPOS: ", Point(10, 40), capture.get(CAP_PROP_EXPOSURE));
//		put_string(frame, "EXPOS: ", Point(10, 40), cnt++);
//        cvtColor(frame, gray, COLOR_RGB2GRAY);//CV_RGB2GRAY
//		imshow("카메라 영상보기", frame);
////		imshow("카메라 영상보기", gray);
////		if (waitKey(33) >= 0) break;
//		text = "cam_" + to_string(cnt);
//		text += ".jpg";
//		key = waitKey(33);
//		if (key == 'c') //0x63
//			imwrite(text, frame);
//		else if(key == 'b')	//0x62
//			break;

//	}
//	capture.release();
//	return 0;
}
