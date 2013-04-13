/*
 * main_2.cpp
 *
 *  Created on: 16/03/2013
 *      Author: jose
 */

#include "ImageVideoDetection.h"
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

int main(int argc, char **argv) {
	ImageVideoDetection* cam = new ImageVideoDetection();
	cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);
	IplImage* img = cvLoadImage("image.jpg");
	cvShowImage("Original", img);
	cout << "Imagen: " << endl;
	cam->matrixImage(img);
	cam->reconstructImage();
	cvWaitKey(100000);
//	cout << "Video: " << endl;
//	cam->videoMatrix(0);
	return 0;
}

