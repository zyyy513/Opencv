//ע�⺯�����������������á�������ʵ�ֵĲ���


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat bgImage;           //�ڱ���ͼbackgroundimage�ϻ�����״
const char* drawdemo_win = "draw shapes and text demo";             //������ô��⣿C++������
void MyLines();              //������   ����ֱ�ߵĺ���
void MyRectangle();          //���ƾ���
void MyEllipse();              //������Բ
void MyCircle();            //����Բ
void MyPolygon();            //���ƶ����
void RandomLineDemo();       //�������ֱ�ߣ����ȡ�λ�á���ɫ�������

int main(int argc, char** argv) {
	bgImage = imread("D:/vcprojects/images/test1.png");
	if (!bgImage.data) {
		printf("could not load image...\n");
		return -1;
	}
	//��������
	Mylines();              
	Myrectangle();
	Myellipse();
	Mycircle();
	Mypolygon();

	putText(bgImage, "Hello OpenCV", Point(300, 300), CV_FONT_HERSHEY_COMPLEX, 1.0, Scalar(12, 23, 200), 3, 8);
	//������ͼ���ϻ������ֲ�������������Ϊ"Hello OpenCV"    1.0�����ֳߴ�   CV_FONT_HERSHEY_COMPLEX�����壬���Ը���

	namedWindow(drawdemo_win, CV_WINDOW_AUTOSIZE);
	imshow(drawdemo_win, bgImage);

	RandomLineDemo();    

	waitKey(0);
	return 0;
}

void MyLines() {                             //�������ֱ�ߺ���
	Point p1 = Point(20, 30);
	Point p2;
	p2.x = 400;
	p2.y = 400;                                    //����p1p2������   ���ֶ��巽ʽ
	Scalar color = Scalar(0, 0, 255);            //��ɫΪ��ɫ
	line(bgImage, p1, p2, color, 1, LINE_AA);      //ע�������еĲ���   1�����߿�  line aa�Ƿ����    line_type��Ϊ4 8 ��AA
}

void MyRectangle() {                 
	Rect rect = Rect(200, 100, 300, 300);        //���ƾ������ĸ����� 200��100����ʼλ�� 300��300�ǿ��
	Scalar color = Scalar(255, 0, 0);            //��ɫΪ��ɫ
	rectangle(bgImage, rect, color, 2, LINE_8);     //�߿�Ϊ2
}

void MyEllipse() {
	Scalar color = Scalar(0, 255, 0);     //��ɫ
	ellipse(bgImage, Point(bgImage.cols / 2, bgImage.rows / 2), Size(bgImage.cols / 4, bgImage.rows / 8), 90, 0, 360, color, 2, LINE_8);    
	//point()����Բ����  size()�ǳ�����    90 ������Բ  0��360��
}

void MyCircle() {
	Scalar color = Scalar(0, 255, 255);               //��ɫ�Ӻ�ɫ=��ɫ
	Point center = Point(bgImage.cols / 2, bgImage.rows / 2);    //Բ��
	circle(bgImage, center, 150, color, 2, 8);     //150�ǰ뾶
}

void MyPolygon() {
	Point pts[1][5];                   //һ�����е����飬����һ������Σ��ֱ����ÿ���������
	pts[0][0] = Point(100, 100);
	pts[0][1] = Point(100, 200);
	pts[0][2] = Point(200, 200);
	pts[0][3] = Point(200, 100);
	pts[0][4] = Point(100, 100);

	const Point* ppts[] = { pts[0] };         //����ʲô��
	int npt[] = { 5 };                       // npt�Ƕ���ζ�����Ŀ

	Scalar color = Scalar(255, 12, 255);
	fillPoly(bgImage, ppts, npt, 1, color, 8);    //fillpoly����color��ɫ�����ö���� 
}

void RandomLineDemo() {
	RNG rng(12345);            //�������  rng= random number generater
	Point pt1;
	Point pt2;         //����������
	Mat bgimage2 = Mat::zeros(bgImage.size(), bgImage.type());    //��������һ��ͼ����bgimage��С���Ͷ�һ��   ��ɫ�Ǻڵ�
	namedWindow("random line demo", CV_WINDOW_AUTOSIZE);               //�������ֱ�������������Ҫ������ĸ���ע�͵�   �������ںڱ����ϻ�
	
	for (int i = 0; i < 100000; i++) {      //��Ϊ���ܶ��ߣ�������ѭ��
		pt1.x = rng.uniform(0, bgImage.cols);        //�������е���˼���������λ�ö���Ҫ������Χ
		pt2.x = rng.uniform(0, bgImage.cols);          //uniform��������̬�ֲ������
		pt1.y = rng.uniform(0, bgImage.rows);
		pt2.y = rng.uniform(0, bgImage.rows);
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));    //������ɫҲ�������
		if (waitKey(50) > 0) {           //��һ��ֹͣ����
			break;
		}
		line(bgimage2, pt1, pt2, color, 1, 8);       //��ʼ��
		imshow("random line demo", bgimage2);
	}
}
