#define _ITERATOR_DEBUG_LEVEL 0

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <map>
#include <vector>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	VideoCapture cap(0);

	if (!cap.isOpened())
	{
		cout << "Brak kamery!" << endl;
		return -1;
	}


	double szerokoscOkna = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double wysokoscOkna = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

	namedWindow("Blackjack", CV_WINDOW_AUTOSIZE);

	while (true)
	{
		Mat frame;
		cap.retrieve(frame);
		cap.read(frame);

		imshow("Blackjack", frame);
	}
	return 0;
}
///asdasda