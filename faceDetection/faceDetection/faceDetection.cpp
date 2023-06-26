
#include <iostream>
#include<stdlib.h>
#include<opencv2/objdetect/objdetect.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int main()
{
	
	
	CascadeClassifier faceDetection;
	if (!faceDetection.load("C:\\Users\\SUDIPTA DAS\\Downloads\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml"))
	{
		cout << "\n File is not loaded poperly" << endl;
		exit(0);
	}
	char path[100];
	cout << "\n Enter the path to image for face detection: " << endl;
	cin.getline(path, 100);

	Mat img = imread(path, IMREAD_UNCHANGED);
	if (img.empty())
	{
		cout << "\n Image is not found" << endl;

	}
	else
	{
		cout << "\n Image is found!" << endl;
		cout << "Processing..." << endl;


		vector<Rect>faces;
		faceDetection.detectMultiScale(img, faces);

		for (int i = 0; i < faces.size(); i++)
		{
			Point pt1(faces[i].x, faces[i].y);
			Point pt2((faces[i].x + faces[i].height), (faces[i].y + faces[i].width));

			rectangle(img, pt1, pt2, Scalar(0, 255, 255), 2, 8, 0);

		}

		imwrite("C:\\gs\\output.jpg", img);
		cout << "\n Face Detection is now completed" << endl;
	}





	
	
	
	
	return 0;

}
