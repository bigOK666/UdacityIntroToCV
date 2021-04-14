#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc.hpp>
#include "noise/noise.h"
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

	/*
	//draw a line on the img
	Mat img3 = chs[0].clone();
	Point pt1(30, 30), pt2(300, 300);
	line(img3, pt1, pt2, Scalar(255,0,0),5, LINE_8);
	imshow("line", img3);
	*/

	/*获取图片某一行，所有列的值，并画出来*/
	/*
	Mat img3 = chs[0].clone();
	Mat imgRow = img3.row(50);
	imshow("imgRow50", imgRow);
	*/
	/*添加noise
	gaussian_noise(img2);
	saltpepper_noise(img2);
	*/

	//使用blur和gaussianblur
	/*
	Mat blurfirst = Mat::zeros(img2.size(), img2.type());
	Mat boxfirst = Mat::zeros(img2.size(), img2.type());
	GaussianBlur(img2, blurfirst, Size(9, 9), 15.0, 6.0);
	blur(img2, boxfirst, Size(7, 7));
	imshow("gaussian", blurfirst);
	imshow("box", boxfirst);
	*/
	/*
	//用中位数滤波去除salt pepper噪声
	saltpepper_noise(img2);
	//imshow("sp", img2);
	Mat median_blur = Mat::zeros(img2.size(), img2.type());
	medianBlur(img2, median_blur,5);
	imshow("median", median_blur);
	//锐化中位数滤波后的图片
	Mat sharp_img = Mat::zeros(median_blur.size(), median_blur.type());
	//std::cout << median_blur.type() << std::endl;
	Mat kernel_enhance = (Mat_<float>(3, 3) << 0, 0, 0, 0, 2.0, 0, 0, 0, 0);
	
	//Mat kernel_box = (Mat_<float>(3, 3) << 1.0 / 9, 1.0 / 9, 1.0 / 9, 1.0 / 9, 1.0 / 9, 1.0 / 9, 1.0 / 9, 1.0 / 9, 1.0 / 9);
	Mat kernel_box = Mat::ones(kernel_enhance.size(), kernel_enhance.type())/(float)9.0;
	Mat kernel_sharp = kernel_enhance - kernel_box;
	std::cout << kernel_sharp << std::endl;
	std::cout << kernel_sharp.size() << std::endl;
	waitKey(0);
	std::cout << kernel_sharp.at<float>(1, 1) << std::endl;
	//kernel_sharp.at<float>(1, 1) = 2.0;
	waitKey(0);
	//kernel_sharp -= (Mat::ones(3, 3, sharp_img.type()) / (float)9);
	//std::cout << kernel_sharp;
	filter2D(median_blur, sharp_img, -1, kernel_sharp);
	imshow("sharp", sharp_img);
	*/
	//template matching
	/*
	Mat temp = img2(Range(50, 80), Range(20, 40));
	imshow("original", img2);
	imshow("temp", temp);
	Mat result = Mat(img2.rows - temp.rows + 1, img2.cols - temp.cols + 1, CV_32FC1);
	matchTemplate(img2, temp, result, TM_CCORR_NORMED);
	normalize(result, result, 0, 1, NORM_MINMAX);
	double minVal, maxVal;
	Point minLoc, maxLoc;
	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
	imshow("result", result);
	std::cout << maxLoc << std::endl;
	*/

	//Sobel edge detection
	/*
	Mat blurred, blurred_gray;
	GaussianBlur(img2, blurred, Size(3, 3), 0, 0);
	cvtColor(blurred, blurred_gray, COLOR_BGR2GRAY);

	Mat grad_x, grad_y;
	Sobel(blurred_gray, grad_x, -1, 1, 0);
	Sobel(blurred_gray, grad_y, -1, 0, 1);

	imshow("blurred_gray",blurred_gray);
	imshow("grad_x", grad_x);
	imshow("grad_y", grad_y);

	Mat grad;
	addWeighted(grad_x, 0.5, grad_y, 0.5, 0, grad);
	imshow("grad", grad);
	*/

	//Canny Edge detection
	Mat img2_gray,img2_edge;
	cvtColor(img2, img2_gray, COLOR_BGR2GRAY);
	imshow("gray",img2_gray);

	Canny(img2_gray, img2_edge, 100, 300);

	imshow("edge",img2_edge);

	waitKey(0);

	destroyAllWindows();
}