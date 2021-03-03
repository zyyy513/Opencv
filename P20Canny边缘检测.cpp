#include<opencv2/highgui/highgui_c.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
Mat src, gray_src, dst;
int t1_value = 70;     //����������   ���ʼֵΪ50  
int max_value = 255;    //��Ϊ�Ƕ�ֵͼ������������̾���255 
const char* OUTPUT_TITLE = "Canny Result";    //�������Ϊʲô��ô���壬֮ǰ�Ĵ���Ҳ�� 
void Canny_Demo(int, void*);      //���� 
int main(int argc, char** argv) {
	src = imread("touxiang.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}

	char INPUT_TITLE[] = "input image";
	namedWindow(INPUT_TITLE, CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_TITLE, CV_WINDOW_AUTOSIZE);
	imshow(INPUT_TITLE, src);

	cvtColor(src, gray_src, CV_BGR2GRAY);
	createTrackbar("Threshold Value:", OUTPUT_TITLE, &t1_value, max_value, Canny_Demo);
	//������"Threshold Value"   ������output title   
	Canny_Demo(0, 0);   //���ú���canny demo

	waitKey(0);
	return 0;
}

void Canny_Demo(int, void*) {        //���� 

	blur(gray_src, gray_src, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);   //��ģ������ 
	Mat edge_output;
	Canny(gray_src, edge_output, t1_value, t1_value * 2, 3, false);   //����Ҷ�ͼ�������Ե��ֵͼ�񣨱���Ϊ��ɫ��
	//Ȼ���ǵ���ֵ�͸���ֵ����ֵ��ѡ��Ӱ��������ƽʱ��Ҫע����۾���ֵ��������˴�С����L1��һ������Ӧbool����Ϊfalse�� 


	imshow(OUTPUT_TITLE, edge_output);
	//imshow(OUTPUT_TITLE, ~edge_output);     //��������ñ���Ϊ��ɫ����ȡ�����ñ���Ϊ��ɫ 

	////���������У�����ǲ�ɫ�ı�Ե  
	//dst.create(src.size(), src.type());    
	//src.copyTo(dst, edge_output);
	//imshow(OUTPUT_TITLE, dst);

}
