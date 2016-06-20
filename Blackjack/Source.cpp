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

double srodekKameryX, srodekKameryY;

struct Karta
{
	string symbol;
	Mat obraz;
};

int StringDoPunkty(string x)
{
	if (x == "2")
		return 2;
	else if (x == "3")
		return 3;
	else if (x == "4")
		return 4;
	else if (x == "5")
		return 5;
	else if (x == "6")
		return 6;
	else if (x == "7")
		return 7;
	else if (x == "8")
		return 8;
	else if (x == "9")
		return 9;
	else if (x == "10")
		return 10;
	else if (x == "A")
		return 1;
	else if (x == "J")
		return 11;
	else if (x == "Q")
		return 12;
	else if (x == "K")
		return 13;
}

int main(int argc, char* argv[])
{
	vector<Karta> karty;

	karty.push_back({ "A", imread("karty2/A.jpg", CV_LOAD_IMAGE_COLOR) });
	karty.push_back({ "2", imread("karty2/2.jpg", CV_LOAD_IMAGE_COLOR) });
	karty.push_back({ "3", imread("karty2/3.jpg", CV_LOAD_IMAGE_COLOR) });
	karty.push_back({ "4", imread("karty2/4.jpg", CV_LOAD_IMAGE_COLOR) });
	karty.push_back({ "5", imread("karty2/5.jpg", CV_LOAD_IMAGE_COLOR) });
	karty.push_back({ "6", imread("karty2/6.jpg", CV_LOAD_IMAGE_COLOR) });
	karty.push_back({ "7", imread("karty2/7.jpg", CV_LOAD_IMAGE_COLOR) });
	karty.push_back({ "8", imread("karty2/8.jpg", CV_LOAD_IMAGE_COLOR) });
	karty.push_back({ "9", imread("karty2/9.jpg", CV_LOAD_IMAGE_COLOR) });
	karty.push_back({ "10", imread("karty2/10.jpg", CV_LOAD_IMAGE_COLOR) });
	karty.push_back({ "J", imread("karty2/J.jpg", CV_LOAD_IMAGE_COLOR) });
	karty.push_back({ "Q", imread("karty2/Q.jpg", CV_LOAD_IMAGE_COLOR) });
	karty.push_back({ "K", imread("karty2/K.jpg", CV_LOAD_IMAGE_COLOR) });

	VideoCapture cap(0);

	if (!cap.isOpened())
	{
		cout << "Brak kamery!" << endl;
		return -1;
	}

	double szerokoscOkna = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double wysokoscOkna = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

	srodekKameryX = szerokoscOkna / 2.0;
	srodekKameryY = wysokoscOkna / 2.0;

	int punkty = 0, klatka = 0;
	bool rozpoznawanie = false;
	namedWindow("Blackjack", CV_WINDOW_AUTOSIZE);

	while (true)
	{
		Mat frame;
		cap.retrieve(frame);
		cap.read(frame);

		rectangle(frame, Point(srodekKameryX - 30, srodekKameryY - 40), Point(srodekKameryX + 30, srodekKameryY + 40), Scalar(0, 255, 0), 2);

		imshow("Blackjack", frame);

		if (rozpoznawanie && klatka % 3 == 0)
		{

		}

		int key = waitKey(30);
		if (key == 27) // Esc
		{
			break;
		}
		else if (key == 'w' && rozpoznawanie == false && punkty < 21)
		{
			rozpoznawanie = true;
		}
		else if (key == 'n' && rozpoznawanie == false)
		{
			punkty = 0;
		}
		else if (key == 'p' && rozpoznawanie == true)
		{
			rozpoznawanie = false;
		}

		klatka++;
	}
	return 0;
}