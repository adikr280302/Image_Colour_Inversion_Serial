//This is the serial implementation of inversion of image
void Get_Inverse_Image_Serial(unsigned char* data,long long int rows, long long int columns,long long int channels) {
	// loop variable i helps to traverse all the rows of the rgb matrix
	for (long long int i = 0;i < rows;i++) {
		// loop vairable j helps to traverse all the columns of the rgb matrix for each i(row)
		for (long long int j = 0;j < columns;j++) {
			//loop variable k helps to traverse the r,g,b values of element(i,j)
			long long int idx = (i * columns + j) * channels;
			for (long long int k = 0;k < channels;k++) {
				data[idx+k] = 255 - data[idx+k];
			}
		}
	}
}