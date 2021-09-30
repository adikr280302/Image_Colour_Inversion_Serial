#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat readImage(string input_path,unsigned char** data,long long int* rows,long long int* columns,long long int* channels) {
	//Reading the image throguh opencv and the entered path
	Mat img = imread(input_path);

	//Handling the case where image is missing
	if (!img.data) {
		cout << "Error: image missing\n";
		exit(-1);
	}

	//Assigning the read values
	*data = img.data;
	*rows = img.rows;
	*columns = img.cols;
	*channels = img.channels();
	return img;
}

void Display_Image(string window_name, Mat *img) {
	namedWindow(window_name, WINDOW_NORMAL);
	imshow(window_name, (*img));
}

void Save_Image(string name, Mat *img) {
	imwrite(name, *img);
}