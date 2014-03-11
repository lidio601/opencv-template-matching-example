
/////////////////////////////////////////////////
// main.cpp
#include "main.h"
/////////////////////////////////////////////////

int main(int argc, char *argv[]) {
	IplImage *img;
	IplImage *tpl;
	
	CvPoint minloc, maxloc;
	double minval, maxval;
	
	/* check for arguments */
	if( argc < 3 ) {
		printf( "Usage: template_match <reference> <template>\n" );
		return 1;
	}
	
	/* load reference image */
	img = cvLoadImage( argv[1], CV_LOAD_IMAGE_COLOR );
	/* always check */
	
	if( img == 0 ) {
		printf( "Cannot load file %s!\n", argv[1] );
		return 1;
	}
	
	/* load template image */
	tpl = cvLoadImage( argv[2], CV_LOAD_IMAGE_COLOR );
	
	/* always check */
	if( tpl == 0 ) {
		printf("Cannot load file %s!\n", argv[2] );
		return 1;
	}
	
	doWork(tpl, res1, &minval, &maxval, &minloc, &maxloc );
	
#if GRAPHIC_OUTPUT
	graphic_output(tmpl,img,&minloc,&maxloc,&minval,&maxval);
#else
	terminal_output(tmpl,img,&minloc,&maxloc,&minval,&maxval);
#endif
	
	return 0;
}

#if GRAPHIC_OUTPUT
void graphic_output(IplImage* tmpl, IplImage* img, CvPoint& minloc, CvPoint& maxloc, double& minval, double& maxval) {
	
	int tpl_width, tpl_height;
	int res_width, res_height;
	
	/* get image's properties */
	tpl_width = tpl->width;
	tpl_height = tpl->height;
	
	/* draw red rectangle */
	cvRectangle( img,
		cvPoint( minloc.x, minloc.y ),
		cvPoint( minloc.x + tpl_width, minloc.y + tpl_height ),
		cvScalar( 0, 0, 255, 0 ), 1, 0, 0 ); 
	
	/* display images */
	cvNamedWindow( "reference", CV_WINDOW_AUTOSIZE );
	cvNamedWindow( "template", CV_WINDOW_AUTOSIZE );
	cvShowImage( "reference", img );
	cvShowImage( "template", tpl );
	
	/* wait until user press a key to exit */
	cvWaitKey( 0 );
	
	/* free memory */
	cvDestroyWindow( "reference" );
	cvDestroyWindow( "template" );
	
}
#else
void terminal_output(IplImage* tmpl, IplImage* img, CvPoint& minloc, CvPoint& maxloc, double& minval, double& maxval) {
	
	int tpl_width, tpl_height;
	int res_width, res_height;
	
	/* get image's properties */
	tpl_width = tpl->width;
	tpl_height = tpl->height;
	
	cout<<minloc.x<<"\t"<<minloc.y<<"\t"<<(minloc.x + tpl_width)<<"\t"<<(minloc.y + tpl_height)<<endl;
}
#endif
