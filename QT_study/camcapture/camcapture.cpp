#include "camcapture.h"
#include "ui_camcapture.h"

CamCapture::CamCapture(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CamCapture)
{
    ui->setupUi(this);
}

CamCapture::~CamCapture()
{
    delete ui;
}

void CamCapture::put_string(Mat &frame, string text, Point pt, int value){
    text += to_string(value);
    Point shade = pt + Point(2, 2); // shadow
    int font = FONT_HERSHEY_SIMPLEX;
    putText(frame, text, shade, font, 0.7, Scalar(0, 0, 0), 2);		// 그림자 효과
    putText(frame, text, pt, font, 0.7, Scalar(120, 200, 90), 2);// 작성 문자
}

void CamCapture::CamView(){
    int cnt = 0;
    String fname;
    VideoCapture  capture(0); // Camera Object connected to cam, parameter : number of camera
//        if (!capture.isOpened())
//        {
//            cout << "카메라가 연결되지 않았습니다." << endl;
//            exit(1);
//        }
//        /* Set & Get Properties */
//        capture.set(CAP_PROP_FRAME_WIDTH, 640); // set width
//        capture.set(CAP_PROP_FRAME_HEIGHT, 480); // set height
//        //capture.set(CAP_PROP_FPS, 30); // set height
//        cout << "너비 " << capture.get(CAP_PROP_FRAME_WIDTH) << endl;
//        cout << "높이 " << capture.get(CAP_PROP_FRAME_HEIGHT) << endl;
//        cout << "노출 " << capture.get(CAP_PROP_EXPOSURE) << endl;
//        cout << "밝기 " << capture.get(CAP_PROP_BRIGHTNESS) << endl;

//        for (;;) {
//            Mat frame; // Matrix data type
//            capture.read(frame);

//            // Put the text on frame
//            //put_string(frame, "COUNT: ", Point(10, 40), capture.get(CAP_PROP_FPS));

//            put_string(frame, "COUNT: ", Point(10, 40), cnt);
//            fname = "cam_" + to_string(cnt++);
//            fname += ".jpg"; // Save frame file as jpg
//            imshow("카메라 영상보기", frame); // show frame
//            int key = waitKey(33); // Delay for 33ms -> 30 frame / sec
//            if (key == 's') // 115
//            {
//                imwrite(fname, frame);
//            }
//            else if (key == 'b') // 98
//            {
//                cout << "key : " << key << endl;
//                break;
//            }
//            //if (waitKey(1) >= 0) break;
//            //cnt++;
//        }
//        capture.release();
}
