//���Ľ������Ի�ϲ��������ۣ����������API��addweighted

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
	Mat src1, src2, dst;              //����ԭʼͼ��ϳ�dst
	src1 = imread("D:/vcprojects/images/LinuxLogo.jpg");
	src2 = imread("D:/vcprojects/images/win7logo.jpg");
	if (!src1.data) {
		cout << "could not load image Linux Logo..." << endl;
		return -1;
	}
	if (!src2.data) {
		cout << "could not load image WIN7 Logo..." << endl;
		return -1;
	}                             //��������ͼ�񣬲�����Ƿ��ȡ�ɹ�               

	double alpha = 0.5;              //����Ȩ��
	if (src1.rows == src2.rows && src1.cols == src2.cols && src1.type() == src2.type()) {                //����ͼ��Ĵ�С�����Ͷ�Ҫһ��
		 addWeighted(src1, alpha, src2, (1.0 - alpha), 0.0, dst);            //addweighted API��ע������Ĳ���
		// multiply(src1, src2, dst, 1.0);     //���䣺��˲���

		imshow("linuxlogo", src1);
		imshow("win7logo", src2);
		namedWindow("blend demo", CV_WINDOW_AUTOSIZE);
		imshow("blend demo", dst);                    //�����ʾ������ͼ��ע��src1 src2��û��namedwindow����Ϊ��дҲ���ԣ�ϵͳ��Ĭ�ϴ�������
	}
	else {                     //��������ͼ��һ�£��޷����Ի��
		printf("could not blend images , the size of images is not same...\n");
		return -1;
	}

	waitKey(0);
	return 0;
}