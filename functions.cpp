
/////////////////////////////////////////////////
// function.cpp
/////////////////////////////////////////////////

void doWork(IplImage* tmpl, IplImage* img, CvPoint& minloc, CvPoint& maxloc, double& minval, double& maxval) {
	
	int img_width, img_height;
	int tpl_width, tpl_height;
	int res_width, res_height;
	
	/* get image's properties */
	img_width = img->width;
	img_height = img->height;
	tpl_width = tpl->width;
	tpl_height = tpl->height;
	res_width = img_width - tpl_width + 1;
	res_height = img_height - tpl_height + 1;
	
	/* create new image for template matching computation */
	res1 = cvCreateImage( cvSize( res_width, res_height ), IPL_DEPTH_32F, 1 );
	
	/* choose template matching method to be used */
	cvMatchTemplate( img, tpl, res1, CV_TM_SQDIFF );
	
	cvMinMaxLoc( res1, &minval, &maxval, &minloc, &maxloc, 0 );
	
	cvReleaseImage( &res1 );
}
