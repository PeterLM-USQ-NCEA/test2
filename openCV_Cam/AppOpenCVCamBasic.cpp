#include <opencv\cv.h>
#include <opencv\cxcore.h>
#include <opencv\highgui.h>
#include "windows.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
//using namespace cv;

int main() {
//VideoCapture stream1(0);   //0 is the id of video device.0 if you have only one camera.
CvCapture *cam1 = 0;
IplImage* frame;
IplImage* resized = cvCreateImage(cvSize(640,480),8,3);
cam1 = cvCaptureFromCAM(0);
printf("Return: %d",cam1);
frame = cvQueryFrame(cam1);
printf("Frame: %d",frame);
int key = 0;
int delayTime = 33;
//Mat cameraFrame;


//if (!stream1.isOpened()) { //check if video device has been initialised
//cout << "cannot open camera";
//}

//unconditional loop
while (true) {
//key=cvWaitKey( delayTime );
//if( key=='e' ){
//printf("Manual Close");
//cvWaitKey(250);
//break;
//}
frame = cvQueryFrame(cam1);
cvResize(frame,resized,1);
cvShowImage("cam1",resized);
cvWaitKey(33);
//stream1.read(cameraFrame);
//imshow("cam1", cameraFrame);
}
return 0;
}