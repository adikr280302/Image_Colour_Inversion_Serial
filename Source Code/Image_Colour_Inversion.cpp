#include <iostream>
#include <chrono>
#include <opencv2/opencv.hpp>
#include "Inverse_Image_Serial.h"
#include "OpenCv_Helpers.h"

using namespace std;
using namespace cv;
using namespace chrono;

int main(int argc,const char** argv){
	
	//Extracting the input image path from command line
	string input_image_path;
	if (argc > 1) {
		input_image_path = argv[1];
	}
	else {
		cout << "ENTER THE INPUT IMAGE PATH LOCATION:-\n";
		cin >> input_image_path;
	}

	//Declaring some variables to store image data
	unsigned char *data;
	long long int rows, columns,channels;

	//Reading image
	Mat img= readImage(input_image_path, &data, &rows, &columns, &channels);
	//Displaying the read image
	Display_Image("INPUT IMAGE", &img);
	auto start = high_resolution_clock::now();
	//Serially inverting the pixels
	Get_Inverse_Image_Serial(data, rows, columns, channels);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Conversion took " << duration.count() << " micro seconds\n";
	//Displaying the inverted image
	Display_Image("OUTPUT IMAGE", &img);

	//Saving the inverted image
	Save_Image(input_image_path.substr(0,input_image_path.size() - 4) + "-inverted.jpg", &img);
	waitKey(0);
	return 0;
}