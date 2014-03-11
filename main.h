
/////////////////////////////////////////////////
// main.h
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace cv;
using namespace std;

#include "function.h"

int main(int argc, char *argv[]);

#define GRAPHIC_OUTPUT 1

#if GRAPHIC_OUTPUT
void graphic_output(IplImage* tmpl, IplImage* img, CvPoint& minloc, CvPoint& maxloc, double& minval, double& maxval);
#else
void terminal_output(IplImage* tmpl, IplImage* img, CvPoint& minloc, CvPoint& maxloc, double& minval, double& maxval);
#endif

/////////////////////////////////////////////////
