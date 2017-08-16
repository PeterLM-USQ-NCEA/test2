#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\highgui\highgui_c.h>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\imgproc\imgproc_c.h>
#include "windows.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
using namespace cv;

int main() {
VideoCapture stream1(0);   //0 is the id of video device.0 if you have only one camera.
int key = 0;
int delayTime = 60000;
time_t rawtime;
Mat cameraFrame;

if (!stream1.isOpened()) { //check if video device has been initialised
cout << "cannot open camera";
}
STARTUPINFO si = { sizeof(STARTUPINFO) };
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_SHOW;
    PROCESS_INFORMATION pi;
    CreateProcess("C:\\Users\\reesst\\Documents\\Peter_CameraTesting\\CameraToolMod\\usbCameraParallelv5\\CameraTool\\bin\\Release\\CameraTool.exe", NULL , NULL, NULL, FALSE, CREATE_NEW_CONSOLE , NULL, NULL, &si, &pi);
 
//unconditional loop
while (true) {
time (&rawtime);
struct tm  *timeinfo = localtime (&rawtime);
strftime(array, sizeof(array)-1, "%d.%m.%y_%H:%M:%S", timeinfo);
stream1.read(cameraFrame);
imshow("cam", cameraFrame);
imwrite(timeinfo,cameraFrame);
key=cvWaitKey( delayTime );
if( key=='e' ){
printf("Manual Close");
cvWaitKey(500);
break;
}
return 0;
}