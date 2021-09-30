#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat readImage(string input_path, unsigned char** data,long long int* rows,long long int* columns,long long int* channels);
void Display_Image(string window_name, Mat *img);
void Save_Image(string name, Mat *img);