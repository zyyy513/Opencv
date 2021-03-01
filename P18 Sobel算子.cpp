//sobel���ӵ��Ĳ�����

#include<opencv2/highgui/highgui_c.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include<math.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src, dst;
	src = imread("touxiang.jpg");
	if (src.empty())
	{
		printf("Could not find the image!\n");
		return -1;
	}

	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	//���ȶ�ԭͼ���и�˹ģ����dst
	GaussianBlur(src, dst, Size(3, 3), 0, 0);
	//��תΪ�Ҷ�ͼ��
	Mat gray_src;
	cvtColor(dst, gray_src, CV_BGR2GRAY);
	imshow("gray image", gray_src);
	//��sobel������x y���������ϵ��ݶ�  �����������ͼ��
	Mat xgrad, ygrad;  
	Sobel(gray_src, xgrad, CV_16S, 1, 0, 3);   //CV_16S�����ͼ�����  1 0 ��xΪһ�׵���y����  3�Ǿ���˴�С
	Sobel(gray_src, ygrad, CV_16S, 0, 1, 3);

	//Scharr(gray_src, xgrad, CV_16S, 1, 0, 3);   //������scharr�Ż�
	//Scharr(gray_src, ygrad, CV_16S, 0, 1, 3);

	//������Ϊ�˱�����ָ�����ֵ����scaleabsȡ����ֵ��ȫ�������
	convertScaleAbs(xgrad, xgrad);
	convertScaleAbs(ygrad, ygrad);
	imshow("xgrad", xgrad);
	imshow("ygrad", ygrad);

	//��ͼ���ϣ�������xgrad ygrad���
	Mat xygrad;
	addWeighted(xgrad, 0.5, ygrad, 0.5, 0, xygrad);
	imshow("xygrad", xygrad);
	/*   �����Ǳ����������� ��xgrad ygrad����ֱ����ӣ�������ͼ����   ���ұ�ͼ����Ч��Ҫ�ã�
	Mat xygrad = Mat(xgrad.size(), xgrad.type());
	printf("type : %d\n", xgrad.type());     ����û����
	int width = xgrad.cols;
	int height = ygrad.rows;
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			int xg = xgrad.at<uchar>(row, col);
			int yg = ygrad.at<uchar>(row, col);
			int xy = xg + yg;
			xygrad.at<uchar>(row, col) = saturate_cast<uchar>(xy);
		}
	}
	*/
	waitKey(0);
	return 0;
}
