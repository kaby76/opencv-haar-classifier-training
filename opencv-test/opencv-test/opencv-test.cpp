// opencv-test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main2()
{
	std::cout << "Hello World!\n";
	return 0;
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
		return -1;
	}
	Mat img;
//	img = imread(argv[1]); // Read the file
	img = imread("C:\\Users\\Kenne\\Documents\\opencv\\sources\\samples\\data\\lena.jpg");
	if (img.empty()) // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}
	//namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
	//imshow("Display window", image); // Show our image inside it.
	//waitKey(0); // Wait for a keystroke in the window

	//Load the cascade classifier file
	CascadeClassifier cascadeDetect;
	string cascadeFile = "C:\\Users\\Kenne\\Documents\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml";

	if (!cascadeDetect.load(cascadeFile)) {
		cerr << "Error loading the classifier file" << endl;
		return 0;
	}

	Mat gray, smallImg;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	//cvtColor(image, procFrame, CV_BGR2GRAY);
	//equalizeHist(procFrame, procFrame);
	equalizeHist(gray, gray);

	//Look for matches and store them into our vector
	vector<Rect> detected;
	//cascadeDetect.detectMultiScale(procFrame, detected, 1.1, 2, 0, Size(80, 80));
	
	cascadeDetect.detectMultiScale(gray, detected);

	cout << "The number of faces detected: " << detected.size() << endl;
	
 	waitKey(0); // Wait for a keystroke in the window
	return 0;
}
