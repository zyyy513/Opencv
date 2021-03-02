//Laplace����

#include<opencv2/highgui/highgui_c.h>
#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace std;
using namespace cv;
int main(int arga, char** argv)
{
	Mat src, dst;
	src = imread("touxiang.jpg");
	if (!src.data)
	{
		cout << "�޷�����ͼ��" << endl;
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	//�ٸ�˹ģ��
	GaussianBlur(src, dst, Size(3, 3), 0, 0);    //3*3�͹�����
	//��תΪ�Ҷ�
	Mat gray_image;
	cvtColor(dst, gray_image, CV_BGR2GRAY);
	//��Laplace����
	Mat edge_image;
	Laplacian(gray_image, edge_image, CV_16S, 3);    //CV_16Sλͼ���  3�Ǿ���˴�С
	//��ȡ����ֵ
	convertScaleAbs(edge_image, edge_image);

	//����ʾ���
	//���䣬�Խ��������Ļ����ټ�����ֵ����
	threshold(edge_image, edge_image, 0, 255, THRESH_OTSU | THRESH_BINARY);
	namedWindow("final result", CV_WINDOW_AUTOSIZE);
	imshow("final result",edge_image );

	waitKey(0);
	return 0;
}
