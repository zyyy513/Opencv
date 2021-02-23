//ǰ���Ѿ��˽⵽��дͼ���API:
//imread ����ָ������Ϊ�ҶȻ���RGBͼ��
//imwrite ����ͼ���ļ�����������չ������

//����� ���£��Ǵ���ģ��
/*
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main(int argc,char** argv)
{
	Mat src;
	src = imread("D:aaaa.png");
	if (src.empty())
	{
		cout << "ͼ���ȡʧ�ܣ�coule not load image..." << endl;
		return -1;
	}
	namedwindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	waitkey(0);
	return 0;
}
*/

//������ܶ�д���صĲ���
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat src,gray_src;                       //��ԭͼ��RGBתΪ�Ҷ�ͼ��
	src = imread("D:aaaa.png");
	if (src.empty())
	{
		cout << "ͼ���ȡʧ�ܣ�coule not load image..." << endl;
		return -1;
	}
	namedwindow("input", CV_WINDOW_AUTOSIZE);
	imshow("input", src);

	cvt(src, gray_src, CV_BGR2GRAY);
	namedwindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", gray_src);                         //��ʾ�Ҷ�ͼ��
	int height = image.rows;         //���Ǹ߶�row
	int width = image.cols;          //���ǿ��col
	   
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {         //������������
			int gray = gray_src.at<uchar>(row, col);     //��ȡ����Ҷ�ͼ���ÿ������
			gray_src.at<uchar>(row, col) = 255 - gray;        //�������
		}
	}

	//53��58���ǵ�ͨ����������չ����ͨ�������
	Mat dst;
	dst.create(src.size(), src.type());
	height = src.rows;
	width = src.cols;
	int nc = src.channels();   //ͨ����
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {         //������������
			if (nc == 1)             //����ǵ�ͨ����ͬ��
			{
				int gray = gray_src.at<uchar>(row, col);     //��ȡ����Ҷ�ͼ���ÿ������
				gray_src.at<uchar>(row, col) = 255 - gray;        //�������
			}
			else if (nc == 3)       //�������ͨ��
			{
				int b = dst.at<Vec3b>(row, col)[0];
				int g = dst.at<Vec3b>(row, col)[1];
				int r = dst.at<Vec3b>(row, col)[2];        //�������Ƕ�д���ز���
				dst.at<Vec3b>(row, col)[0] = 255 - b;
				dst.at<Vec3b>(row, col)[1] = 255 - g;
				dst.at<Vec3b>(row, col)[2] = 255 - r;
			}
		}
	}

	//���䣺��������һ�п��Դﵽ��66��83����ͬ��Ч��
	bitwise_not(src, dst);

	imshow("gray invert", gray_src/*(����dst)*/);       //��ʾ����ͼ��  ��ע�⣬û�д������ڣ���ϵͳ���Զ�����һ�����ڣ�
	waitkey(0);
	return 0;
}

