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
	
	Mat img = imread(argv[1], -1);
	if (img.empty()){
		cout << "No image found !";
		return -1;
	}

	namedWindow("Example1", WINDOW_AUTOSIZE);
	imshow("Example1", img);
	waitKey(0);
	
	destroyWindow("Example1");
	return 0;
}
