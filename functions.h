
/////////////////////////////////////////////////
// function.h
/////////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace cv;
using namespace std;

void doWork(IplImage* tmpl, IplImage* img, CvPoint& minloc, CvPoint& maxloc, double& minval, double& maxval);
