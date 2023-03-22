//Filter library Include file
//Author: HRITHIK KANOJE
//CLASS: CS5330 Pattern Recog & computer vision
//Prof: Bruce maxwell
//Project 1:Real-time filtering

//function for calculating greyscale
int greyscale(cv::Mat &src, cv::Mat &dst);

//function for calculating gaussian blur
int blur5x5(cv::Mat& src, cv::Mat& dst);

//function for calculating sobel x 
int sobelX3x3(cv::Mat &src, cv::Mat &dst);

//function for calculating sobel y
int sobelY3x3(cv::Mat &src, cv::Mat &dst);

//function for calculating magnitude gradiant
int magnitude(cv::Mat &sx,cv::Mat &sy, cv::Mat &dst);

//function for calculating blur/quantize 
int blurQuantize(cv::Mat &src, cv::Mat &dst, int levels);

//function for calculating cartoon filter
int cartoon(cv::Mat &src, cv::Mat &dst, int levels, int magThreshold);

//function for  negative filter
int invert(cv::Mat &src, cv::Mat &dst)