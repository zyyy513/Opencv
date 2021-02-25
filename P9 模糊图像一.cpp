//�������ݾ��Ƕ�����ͼ��ֱ���о�ֵģ���͸�˹ģ�����ٷֱ������ʾ
//������ֻ��API  Ҫ���������ģ����ԭ��

#include <opencv2/opencv.hpp> 
#include <iostream> 
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("D:/vcprojects/images/test.png");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	char input_title[] = "input image";
	char output_title[] = "blur image";
	namedWindow(input_title, CV_WINDOW_AUTOSIZE);
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	imshow(input_title, src);

	blur(src, dst, Size(11, 11), Point(-1, -1));    //size���ڴ�С�ǵ���ģ���̶ȵ� �����Կ�������x or y��ģ��
	imshow(output_title, dst);

	Mat gblur;                        //��Ūһ��ͼ��   ��������ͼ���һ��������Ա�ֱ��
	GaussianBlur(src, gblur, Size(11, 11), 11, 11);
	imshow("gaussian blur", gblur);         //ûnamedwindow ϵͳ���Լ�����

	waitKey(0);
	return 0;
}