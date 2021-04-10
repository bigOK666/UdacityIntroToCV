#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main(int argc, char** argv)
{
	Mat img = imread(argv[1], -1);//IMREAD_UNCHANED = -1 返回包含alpha通道的加载图像
	if (img.empty()) return -1;

	namedWindow("Example1", cv::WINDOW_AUTOSIZE);//窗口大小与原图一致，可调，但图片不会缩放
	namedWindow("Example2", 0);//图片大小会与窗口大小一致
	imshow("Example1", img);
	
	waitKey(0);
	imshow("Example2", img);
	waitKey(0);
	//destroyWindow("Example1");
	destroyAllWindows();
}