#include <opencv2/core/core_c.h>
#include <opencv2/core/core.hpp>
#include <opencv2/flann/miniflann.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/photo/photo.hpp>
#include <opencv2/video/video.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/ml/ml.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/highgui/highgui.hpp>
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

string VIDEO_PLAYER = "VIDEO PLAYER";
string TRACK_BAR = "TRACK_BAR";
int g_slider_position = 0;
int g_run = 1;
int g_dont_set = 0;
VideoCapture g_cap;

void onTrackbadSlide(int pos, void *){
	g_cap.set(CAP_PROP_POS_MSEC, pos);
	// if( !g_dont_set )
	// 	g_run = 1;
	// g_dont_set = 0;
}


int main(int argc, char **argv){

	g_cap.open(argv[1]);
	if(!g_cap.isOpened()){
		cout << "can not open the video ";
		return -1;
	}

	double fps = g_cap.get(CAP_PROP_FPS);
	int frames = (int) g_cap.get(CAP_PROP_FRAME_COUNT);
	int frameW = (int) g_cap.get(CAP_PROP_FRAME_WIDTH);
	int frameH = (int) g_cap.get(CAP_PROP_FRAME_HEIGHT);

	cout << "Video has " << frames << " frames of dimensions ("<< frameW << ", " << frameH << ")." << endl;
	cout << "Frame per seconds :" << fps << endl;

	namedWindow(VIDEO_PLAYER, WINDOW_AUTOSIZE);
	createTrackbar(TRACK_BAR, VIDEO_PLAYER, &g_slider_position, frames, onTrackbadSlide);
	
	Mat frame;
	while(true){

		if(g_run != 0){
			cout << "Playing the video" << endl;

			bool isFrameRead = g_cap.read(frame);
			if(!isFrameRead){
				cout << "found the end of the video";
				break;
			}
			int position = g_cap.get(CAP_PROP_POS_FRAMES);
			// setTrackbarPos(TRACK_BAR, VIDEO_PLAYER, position);
			cout << position << endl;

			imshow(VIDEO_PLAYER, frame);
		}

		char c = (char) waitKey(15);
		//Single step
		if(c == 's'){
			g_run = 1;
			cout << "Single step, run = " << g_run << endl;
		}
		//Run mode
		if(c == 'r'){
			g_run = -1;
			cout << "Run mode, run = " << g_run << endl;
		}
		if( c == 27){
			cout << "ESC is pressed by user. Stopping the video" << endl;
			break;
		}
	}
	return 0;
}
