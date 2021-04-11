#pragma once
#ifndef NOISE
#define NOISE

#include "opencv2/highgui.hpp"

void gaussian_noise(cv::Mat& img);
void saltpepper_noise(cv::Mat& img);

#endif // !NOISE
