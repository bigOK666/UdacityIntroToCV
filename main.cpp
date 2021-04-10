#include "opencv2/highgui/highgui.hpp"
#include<iostream>
using namespace cv;

int main(int argc, char** argv)
{
	Mat img = imread(argv[1], -1);//IMREAD_UNCHANED = -1 返回包含alpha通道的加载图像
	if (img.empty()) return -1;
	/* 显示加载的图片
	namedWindow("Example1", cv::WINDOW_AUTOSIZE);//窗口大小与原图一致，可调，但图片不会缩放
	namedWindow("Example2", 0);//图片大小会与窗口大小一致
	imshow("Example1", img);
	
	waitKey(0);
	imshow("Example2", img);
	waitKey(0);
	//destroyWindow("Example1");
	destroyAllWindows();
	*/
	Mat img2 = img.clone();
	Mat cha1, cha2, cha3;
	std::vector<Mat> chs{ cha1,cha2,cha3 };

	std::cout << img2.channels() << std::endl;

	split(img2, chs);
	std::cout << chs[0].channels() << " " << chs[0].size() << std::endl;

	Mat B = chs[0](Range(1, 3), Range(1, 10));
	std::cout << B.channels() << " " << B.size() << std::endl;
	//std::cout << channels[0];
	/*显示通道图片
	namedWindow("blue", 0);
	imshow("blue", channels[0]);
	namedWindow("blue1", 0);
	imshow("blue1", channels[0]);
	*/
	/* 保存通道到图片
	imwrite("blue.jpg", channels[0]);
	imwrite("green.jpg", channels[1]);
	imwrite("red.jpg", channels[2]);
	*/
	waitKey(0);

	destroyAllWindows();
}