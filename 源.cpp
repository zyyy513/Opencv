#include<opencv2\opencv.hpp>    //ͷ�ļ����԰�����Ҫ�ĸ�ģ���ͷ�ļ�����highgui.hpp  �����ܵ�ͷ�ļ�oopencv.hpp �Ƚ�ʡ�ģ���Ȼ����ʱ��ϳ�
#include<iostream>
#include<math.h>

using namespace cv;   //�����ռ�cv   ����ȥ��ÿ������ǰ�ټ�cv::

int main(int argc, char** argv)   //�β��б����Ҳ���Բ���������
{
	Mat src = imread("D:/aaaaa.jpg");        //mat�ฺ��ͼ�����ݵĴ洢�������Զ������ڴ���Զ��ͷţ������Ϊ����ָ��
                                      //imread�Ƕ�ȡͼ��D:/aaaaa��ͼ������λ��
	if (src.empty())             //��ȡ����empty() ���ж��Ƿ��ȡ�ɹ�
	{
		cout << "�޷�����ͼ��could not load image!" << endl;
		return -1;
	}

	namedwindow("test opencv setup", CV_WINDOW_AUTOSIZE);    //��������ͼ����ʾ�Ĵ��� autosize���������Զ�����ͼ���С����ʾ���ڴ�С
	imshow("test opencv setup"��src);     //imshow������ʾ  ����֮��һ��Ҫ��waitkey(

	waitkey(0);
	return 0;
}


//���������imread namedwindow imshow ����api
//������ܼ��أ��޸ģ�������� imread cvtcolor �� imwrite
#include<opencv2\opencv.hpp>   
#include<iostream>
#include<math.h>

using namespace cv;   

int main(int argc, char** argv)   
{
	//�� ����ͼ��
	Mat src = imread("D:/aaaaa.jpg",IMREAD_GRAYSCALE);        //����һ�������Ǽ��ص�ͼ������ �лҶ�ͼ��RGBͼ��ȵ�				
	if (src.empty())             
	{
		cout << "�޷�����ͼ��could not load image!" << endl;
		return -1;
	}

	//�� ��ʾͼ��
	namedwindow("test opencv setup", CV_WINDOW_AUTOSIZE);
	imshow("test opencv setup"��src);     

	//�� �޸�ͼ��  �ǰ�ͼ���һ��ɫ�ʿռ�ת������һ��ɫ�ʿռ䣬����������    ����Ҫ��namedwindow��������ʾ�޸ĺ��ͼ��
	namedwindow("output window", CV_WINDOW_AUTOSIZE);   
	Mat output_image;
	cvtcolor(src, output_image, CV_BGR2GRAY);        //�����ǳ�ʼͼ��srcͨ��CV_BGR2GRAYת���ɻҶ�ͼ��output_image
	imshow("output window"��output_image);

	//�� ����ͼ��
	imwrite("D:/bbbb.png", output_image);    //���浽D:/bbbb��������Ϊpng��ʽ  Ҳ������jpg,tif��

	waitkey(0);
	return 0;
}

