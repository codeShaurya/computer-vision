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

using namespace cv;
using namespace std;

string VIDEO = "VIDEO in PLAYING";

int main(int argc, char **argv){

	VideoCapture cap(argv[1]);

	if(!cap.isOpened()){
		cout << "can not open the video ";
		return -1;
	}

	//This will start the video from the middle
	//cap.set(CAP_PROP_POS_MSEC, 300); 

	//get the frames rate of the video
	// There is no need of frame ration in playing video
	double fps = cap.get(CAP_PROP_FPS);  //CAP_PROP_FPS - Frame rate of the video will be get
	cout << "Frames per seconds : " << fps << endl;
	
	namedWindow(VIDEO, WINDOW_AUTOSIZE);


	while(true){
		Mat frame;

		bool isFrameRead = cap.read(frame);
		if(!isFrameRead){
			cout << "found the end of the video";
			break;
		}

		imshow(VIDEO, frame);

		if( waitKey(20) == 27) {
			cout << "ESC is pressed by user. Stopping the video";
			break;
		}

	}
	return 0;
}
