#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
	Mat output1;
	Mat output2;
	Mat output3;
	vector<vector<Point>>contours;
	Mat input = imread("C:/Users/hp/Desktop/7.jpg", 0);
	threshold(input, output1, 130, 255, THRESH_BINARY);
	bitwise_not(output1, output2);

	morphologyEx(output2, output3, MORPH_ELLIPSE, kernel);
	findContours(output3, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);
	Mat draw = input.clone();
	for (int i = 0; i < contours.size(); i++)
	{
		RotatedRect rbox = minAreaRect(contours[i]);
		float area = rbox.size.area();
		if (area > 43 * 43 && area < 90 * 90)
		{
			drawContours(draw, contours, i, Scalar(255, 255, 0), -1);
		}
	}
	imshow("output5", draw);
	imshow("output1", output1);
	imshow("output3", output3);

	waitKey();
	return 0;
}