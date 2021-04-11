#include "noise.h"
#include "opencv2/core.hpp"

using namespace cv;

void saltpepper_noise(Mat& img) {
	RNG rng(233);
	int h = img.rows;
	int w = img.cols;
	int nums = 2000;
	for (int i = 0; i < nums; i++) {
		int x = rng.uniform(0, w);
		int y = rng.uniform(0, h);
		if (i % 2 == 1) {
			img.at<Vec3b>(y, x) = Vec3b(255, 255, 255);
		}
		else {
			img.at<Vec3b>(y, x) = Vec3b(0, 0, 0);
		}
	}
	imshow("salt pepper", img);
}

void gaussian_noise(Mat& img) {
	Mat noise = Mat::zeros(img.size(), img.type());
	randn(noise, (10, 10, 10), (40, 40, 40));
	Mat dst;
	add(img, noise, dst);
	imshow("gaussian noise", dst);
}
