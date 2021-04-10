#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main(int argc, char** argv)
{
	Mat img = imread(argv[1], -1);//IMREAD_UNCHANED = -1 ���ذ���alphaͨ���ļ���ͼ��
	if (img.empty()) return -1;

	namedWindow("Example1", cv::WINDOW_AUTOSIZE);//���ڴ�С��ԭͼһ�£��ɵ�����ͼƬ��������
	namedWindow("Example2", 0);//ͼƬ��С���봰�ڴ�Сһ��
	imshow("Example1", img);
	
	waitKey(0);
	imshow("Example2", img);
	waitKey(0);
	//destroyWindow("Example1");
	destroyAllWindows();
}