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

int main(int argc, char **argv){

	VideoCapture cap(0);
	if(!cap.isOpened()){
		cout << "Error while reading a video ";
		return -1;
	}
	
	Mat frame, edges;
	namedWindow("VIDEO", WINDOW_AUTOSIZE);

	for(;;){
		cap >> frame;
		cvtColor(frame, edges, COLOR_BGR2GRAY);
		GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
		Canny(edges, edges, 0, 30, 3);
		imshow("edges", edges);
		if(waitKey(30) >= 0) break;
	}
	
	// destroyWindow("VIDEO");
	return 0;
}
