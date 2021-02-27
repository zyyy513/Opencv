#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
Mat src, gray_src, dst;        //ԭͼ���м�Ҷ�ͼ�����ͼ
int threshold_value = 127;    //�ȳ�ʼ��һ��������ֵ
int threshold_max = 255;      //����������255          

//�¼ӹ��ܣ���5����ֵ������ţ����û������л�
int type_value = 2;
int type_max = 4;              
const char* output_title = "binary image";
void Threshold_Demo(int, void*);             //����  ��ֵ��������
int main(int argc, char** argv) {
	src = imread("D:/vcprojects/images/test.png");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	namedWindow(output_title, CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	//�����ͼ���д�������������    ע�������еĲ���
	createTrackbar("Threshold Value:", output_title, &threshold_value, threshold_max, Threshold_Demo);
	createTrackbar("Type Value:", output_title, &type_value, type_max, Threshold_Demo);
	
	Threshold_Demo(0, 0);     //����

	waitKey(0);
	return 0;
}

void Threshold_Demo(int, void*) {         //����
	cvtColor(src, gray_src, CV_BGR2GRAY);    //��ԭͼתΪ�Ҷ�ͼ��
	threshold(gray_src, dst, 0, 255, THRESH_TRIANGLE | type_value); 
	//��THRESH_TRIANGLE�㷨������Ѱ����ֵ����ǰ���ǰ�ͨ���ģ�����Ҫ��ԭͼתΪ�Ҷ�ͼ���ٽ�����ֵ����    
	
	//����Լ�����ֵ�Ļ���
	//threshold(gray_src, dst, threshold_value,threshold_max,type_value);
	
	imshow(output_title, dst);
}