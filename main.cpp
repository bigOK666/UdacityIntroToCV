#include "opencv2/highgui/highgui.hpp"
#include<iostream>
using namespace cv;

int main(int argc, char** argv)
{
	Mat img = imread(argv[1], -1);//IMREAD_UNCHANED = -1 ���ذ���alphaͨ���ļ���ͼ��
	if (img.empty()) return -1;
	/* ��ʾ���ص�ͼƬ
	namedWindow("Example1", cv::WINDOW_AUTOSIZE);//���ڴ�С��ԭͼһ�£��ɵ�����ͼƬ��������
	namedWindow("Example2", 0);//ͼƬ��С���봰�ڴ�Сһ��
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
	/*��ʾͨ��ͼƬ
	namedWindow("blue", 0);
	imshow("blue", channels[0]);
	namedWindow("blue1", 0);
	imshow("blue1", channels[0]);
	*/
	/* ����ͨ����ͼƬ
	imwrite("blue.jpg", channels[0]);
	imwrite("green.jpg", channels[1]);
	imwrite("red.jpg", channels[2]);
	*/
	waitKey(0);

	destroyAllWindows();
}