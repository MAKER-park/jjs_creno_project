#include <opencv2/imgcodecs.hpp>	// �̹����� �ʿ�
#include <opencv2/highgui.hpp>		// GUI
#include <opencv2/imgproc.hpp>		// �̹���ó��
#include <iostream>					// �Է� �� ��� ��Ʈ��

using namespace cv;
using namespace std;

/////////////////////////     Warp Images      ////////////////////////////

float w = 250, h = 350;
Mat matrix, imgWarp;

void main() {

	string path = "Resources/cards.jpg";	// ��� ����, ������ �̹����� �ּҸ� �Է�.
	Mat img = imread(path);		// Mat Ŭ������ Matrix�� ���ڷ� ����� ǥ���ϱ� ���� ������ ����, ���⼭�� �̹����� ������ ������ ��Ʈ�� ����

	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} }; // (ù��° ���� �� ), (�ι�° ���� x��, Y��), (����° ���� x��, Y��), (�׹�°)

	matrix = getPerspectiveTransform(src, dst);		// ���� ��ȯ ���(�ʱ� ��ǥ �迭, ��� ��ǥ �迭)
	warpPerspective(img, imgWarp, matrix, Point(w, h)); // (��ǲ, �ƿ�ǲ , �� �Լ����� ��ȯ�� ���, ũ��)
	
	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);	// ��(�̹���, �߽���(�� â�� ���� ��), �� ũ��, BGR, �β�)
	}

	imshow("Image", img);		// read�� �̹��� ��ü img��	ȭ�鿡 ��Ÿ���� ���� �Լ�
	imshow("Image warp", imgWarp);
	waitKey(0);					// �ݱ� ��ư�� ���� �� ���� �������� ���� �Լ�
}

