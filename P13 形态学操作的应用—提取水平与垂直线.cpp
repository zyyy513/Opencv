//����  ��
//����ͼ���ɫͼ�� imread
//ת��Ϊ�Ҷ�ͼ�� �C cvtColor
//ת��Ϊ��ֵͼ�� �C adaptiveThreshold
//����ṹԪ��
//������ ����ʴ + ���ͣ���ȡ ˮƽ�봹ֱ��


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
int main(int argc, char** argv) {
	Mat src, dst;
	src = imread("D:/vcprojects/images/chars.png");        //����ԭ��ɫͼ��
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}

	char INPUT_WIN[] = "input image";
	char OUTPUT_WIN[] = "result image";
	namedWindow(INPUT_WIN, CV_WINDOW_AUTOSIZE);
	imshow(INPUT_WIN, src);

	Mat gray_src;                                  //תΪ�Ҷ�ͼ��
	cvtColor(src, gray_src, CV_BGR2GRAY);
	imshow("gray image", gray_src);

	Mat binImg;                                      //���ɻҶ�ͼ��תΪ��ֵͼ��
	adaptiveThreshold(~gray_src, binImg, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);
	                 //�����ֱ�Ϊ   ��ֵͼ�����ֵ������Ӧ��������ֵ���ͣ����С������c
	imshow("binary image", binImg);

	//����ṹԪ��
	// ˮƽ�ṹԪ��
	Mat hline = getStructuringElement(MORPH_RECT, Size(src.cols / 16, 1), Point(-1, -1));
	// ��ֱ�ṹԪ��
	Mat vline = getStructuringElement(MORPH_RECT, Size(1, src.rows / 16), Point(-1, -1));
	// ���νṹԪ��
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));

	//���п�����
	Mat temp;  //�ȶ���һ���м����
	erode(binImg, temp, hline);    //�ȸ�ʴ
	dilate(temp, dst, hline);      //������
	// morphologyEx(binImg, dst, CV_MOP_OPEN, hline);      //����ֱ���ÿ�����,���һ����
	bitwise_not(dst, dst);         //�ٲ���һ�����ѱ�����Ϊ��ɫ��Ч������
	//blur(dst, dst, Size(3, 3), Point(-1, -1));        //���Ż�Ч�����ý����ʾ�ĸ�Բ��
	imshow("Final Result", dst);                      //��ʾ���ս��,��ȡ����ˮƽ��   �����õ���ֱ�ߣ���45��46�и�Ϊvline

	//��ţ�Ƶ�����kernel  ����ȥ��ͼƬ�и��ŵ����ֵ�б�ߣ�����  ��45��46 ���и�Ϊkernel����

	waitKey(0);
	return 0;
} 