//���վ��ԭ�����־�����ӣ�Kernel��

#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
int main(int argc, char** argv) {
	Mat src, dst;

	src = imread("D:/vcprojects/images/test1.png");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}

	char INPUT_WIN[] = "input image";
	char OUTPUT_WIN[] = "Robert x";
	namedWindow(INPUT_WIN, CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_WIN, CV_WINDOW_AUTOSIZE);

	imshow(INPUT_WIN, src);

	//Robert���� x����
	Mat kernel_x = (Mat_<int>(2, 2)) << (1, 0, 0, -1);     //x�����2*2���� ��135�ȣ�
	filter2D(src, dst, -1, kernel_x, Point(-1, -1), 0.0);      //��filter2D��Ϊ����߶Աȶȣ�
	imshow(OUTPUT_WIN, dst);
	//Robert���� y����
	Mat ying;
	Mat kernel_y = (Mat_<int>(2, 2)) << (0��1, 0, -1);     //y�����2*2����  ��45�ȣ�
	filter2D(src, ying, -1, kernel_y, Point(-1, -1), 0.0);
	imshow("Robert y", ying);

	// Sobel X ����
	// Mat kernel_x = (Mat_<int>(3, 3) << -1, 0, 1, -2,0,2,-1,0,1);   //sobel������3*3����
	// filter2D(src, dst, -1, kernel_x, Point(-1, -1), 0.0);
	// imshow(OUTPUT_WIN, dst);

	// Sobel Y ����
	// Mat yimg;
	// Mat kernel_y = (Mat_<int>(3, 3) << -1, -2, -1, 0,0,0, 1,2,1);
	// filter2D(src, yimg, -1, kernel_y, Point(-1, -1), 0.0);
	// imshow("sobel y", yimg)

	// ������˹����
	//Mat kernel_y = (Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	//filter2D(src, dst, -1, kernel_y, Point(-1, -1), 0.0);
	// imshow(OUTPUT_WIN, dst);
	
	
	//���䣺�Զ�����ģ��
	int c = 0;
	int index = 0;
	int ksize = 0;
	while (true) {
		c = waitKey(500);   //��500���룬�Զ�ģ��
		if ((char)c == 27) {// ��˼�ǰ�ESC���˳�   
			break;
		}
		
		ksize = 5 + (index % 8) * 2;
		//��������
		Mat kernel = Mat::ones(Size(ksize, ksize), CV_32F) / (float)(ksize * ksize);    //ksize*ksizeתΪfloat��
		//����û������   ����߶���ksize��С�ľ���ÿ��Ԫ����1/ksize*ksize���൱�ھ�ֵģ����
		filter2D(src, dst, -1, kernel, Point(-1, -1));
		index++;    //ʱ��Խ����ģ���̶�Խ��
		imshow("�Զ�����ģ��", dst);
	}

	// imshow("Sobel Y", yimg);
	return 0;
}