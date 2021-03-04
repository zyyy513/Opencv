//�Ƚ��б�Ե���  ��Houghֱ�߼��
#include<opencv2/highgui/highgui_c.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;
int main(int argc, char** argv) {
	Mat src, src_gray, dst;
	src = imread("line0.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}

	char INPUT_TITLE[] = "input image";
	char OUTPUT_TITLE[] = "hough-line-detection";
	namedWindow(INPUT_TITLE, CV_WINDOW_AUTOSIZE);
	namedWindow(OUTPUT_TITLE, CV_WINDOW_AUTOSIZE);
	imshow(INPUT_TITLE, src);

	// extract edge canny��Ե��� ��ȡ��Ե 
	Canny(src, src_gray, 150, 200);   //�ߵ���ֵ�ֱ�Ϊ150��200  //src���Ǻڰ׵ģ�����תΪ�Ҷ��� 
	cvtColor(src_gray, dst, CV_GRAY2BGR);      //�Ҷ�ת��ɫ 
	imshow("edge image", src_gray);


	vector<Vec4f> plines;     //��Hough�任�ó����Ľ���ŵ�plines������ 
	HoughLinesP(src_gray, plines, 1, CV_PI / 180.0, 10, 0, 10);   //�˽���Щ����   
	Scalar color = Scalar(0, 0, 255);     //��������ֱ���ú��߱�ʾ 
	for (size_t i = 0; i < plines.size(); i++) {     //��size_t ����int   �������� 
		Vec4f hline = plines[i];
		line(dst, Point(hline[0], hline[1]), Point(hline[2], hline[3]), color, 2, LINE_AA);
		//�߿���2  line_aa�Ƿ���ݵ�line_type 
	}
	imshow(OUTPUT_TITLE, dst);

	/*   ���䣺HoughlinesAPI  һ�㲻��
	vector<Vec2f> lines;
	HoughLines(src_gray, lines, 1, CV_PI / 180, 150, 0, 0);
	for (size_t i = 0; i < lines.size(); i++) {
		float rho = lines[i][0]; // �������е�r����
		float theta = lines[i][1]; // �������еĽǶ�
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a*rho, y0 = b*rho;
		// ת��Ϊƽ��������ĸ���
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		line(dst, pt1, pt2, Scalar(0, 0, 255), 1, CV_AA);
	}
	*/


	waitKey(0);
	return 0;
}
