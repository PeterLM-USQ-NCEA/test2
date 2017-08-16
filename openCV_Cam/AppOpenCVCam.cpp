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
#include <time.h>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

int main() {
VideoCapture stream1(0);   //0 is the id of video device.0 if you have only one camera.
VideoCapture stream2(1);   //0 is the id of video device.0 if you have only one camera.
int key = 0;
int delayTime = 100;
Mat cameraFrame;
Mat cameraFrame_Small;
Mat cameraFrame2;
Mat cameraFrame2_Small;
Size smallerSize(640,400);
int iterate = 0;
int waitSixty = 0;
string line;
ifstream myfile ("iteration.txt");
ofstream myfile2;

if (myfile.is_open())
{
  getline (myfile,line);
  myfile.close();
}
else cout << "Unable to open file";

istringstream (line) >> iterate;
////char buffer[26];
stringstream ss;
stringstream ss2;
//string fileName;

if (!stream1.isOpened()) { //check if video device has been initialised
cout << "cannot open camera";
}
if (!stream2.isOpened()) { //check if video device has been initialised
cout << "cannot open camera";
}
cout << "e to exit";
//stream1.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
//stream1.set(CV_CAP_PROP_FRAME_HEIGHT, 800);
//stream2.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
//stream2.set(CV_CAP_PROP_FRAME_HEIGHT, 800);
STARTUPINFO si = { sizeof(STARTUPINFO) };
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_SHOW;
    PROCESS_INFORMATION pi;
    CreateProcess("C:\\Users\\reesst\\Documents\\Peter_CameraTesting\\CameraToolMod\\CameraToolMod\\usbCameraParallelv5\\CameraTool\\bin\\Release\\CameraTool.exe", NULL , NULL, NULL, FALSE, DETACHED_PROCESS , NULL, NULL, &si, &pi);
 
//unconditional loop
while (true) {
//time_t rawtime;
//time (&rawtime);
//struct tm  *timeinfo = localtime (&rawtime);
//strftime(buffer, 26, "%d_%m_%y_%H_%M_%S", timeinfo);
//char to string
//ss << buffer << ".bmp";
//ss >> fileName;
//cout << fileName << " ";
waitSixty++;
key=cvWaitKey( delayTime );
if( key=='e' ){
printf("Manual Close");
cvWaitKey(250);
break;
}
stream1.read(cameraFrame);
stream2.read(cameraFrame2);
//cv::resize(cameraFrame,cameraFrame_Small,smallerSize);
//cv::resize(cameraFrame2,cameraFrame2_Small,smallerSize);
imshow("cam1", cameraFrame);
imshow("cam2", cameraFrame2);
//cout << stream1.get(CV_CAP_PROP_EXPOSURE) << "\n";
if (waitSixty > 600){
//cout << waitSixty << "\n";
waitSixty = 0;
iterate++;
//clear stringstream
ss.str(std::string());
//ss2.str(std::string());
//add current image number
ss << "images//" << iterate << "_cam1.bmp";
//ss2 << "images//" << iterate << "_cam2.bmp";
//convert to string
line = ss.str();
//imwrite(line,cameraFrame);
//line = ss2.str();
//imwrite(line,cameraFrame2);
cout << "Images Captured";
}
}
myfile2.open("iteration.txt");
myfile2 << (int)iterate;
myfile2.close();
return 0;
}