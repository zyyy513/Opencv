//���ڽ�����ֵ�˲���˫���˲�
//Ҫѧ�����ã�ѧ����Ϊ��ʹ�õ�  ���ʵ������Ҫ֪���������˲�������


#include <opencv2/opencv.hpp> 
#include <iostream> 
using namespace cv;

int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("D:/vcprojects/images/cvtest.png");    //����һ���н���������ͼ��
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);

	
	medianBlur(src, dst, 3);               //��ֵ�˲�
	namedWindow("median Filter Result", CV_WINDOW_AUTOSIZE);
	imshow("median Filter Result", dst);                           //������־�����ֵ�˲���ԭͼ��������������
	
	bilateralFilter(src, dst, 15, 100, 5);       //˫���˲�
	namedWindow("BiBlur Filter Result", CV_WINDOW_AUTOSIZE);
	imshow("BiBlur Filter Result", dst);

	Mat gblur;                        //�����˹�˲����Ա�
	GaussianBlur(src, gblur, Size(15, 15), 3, 3);
	imshow("gaussian blur", gblur);

	//˫�˲��͸�˹�˲��ĶԱȿ��Է��֣���˹�˲�ȫ��ģ���ģ���˫���˲�������������Ч���ܺÿ�

	Mat resultImg;
	Mat kernel = (Mat_<int>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);         //֮ǰ����Ĥ��������߶Աȶ�
	filter2D(dst, resultImg, -1, kernel, Point(-1, -1), 0);
	imshow("Final Result", resultImg);           //��������˫���˲��Ļ����Ͻ�����Ĥ���Աȶ�����ˣ�Ч���ǳ��ã���

	waitKey(0);
	return 0;

}