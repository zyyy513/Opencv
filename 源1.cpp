#include<opencv2/opencv.hpp
#include<iostream>
#include<math,h>
using namespace cv;

int main(int argc,char** argv)    //char** ˵��argv�Ƕ���ָ�룿
{
	Mat src, dst;           //��ʼͼ��src�ʹ�����ͼ��dst
	src = imread("D:/aaaa.png");
	if (!src.data)                 //����㣺����empty(),��dataҲ���ж��Ƿ��ȡ�ɹ�   ��ѧһЩapi!
	{
		cout << "ͼ���ȡʧ�ܣ�" << endl;
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input immage", src);
	//��������˶���ļ�������ʾ

	//����Ĥ������ʵ��ͼ��Աȶ���ǿ
	int cols = (src.cols-1) * src.channels();         //���  Ҫ����ͨ����  ��RGB����ͨ����
	int offsetx = src.channels;      //ͨ����
	int rows = src.rows;              //�߶�
	dst = Mat::zeros(src.size(), src.type());     //�����ͼ����г�ʼ��  zeros�������������ͼ����ԭʼ����ͼ��Ĵ�С�����Ͷ�һ��

	for (int row = 1; row < rows - 1; row++)
	{
		const uchar* current = src.ptr<uchar>(row-1);
		const uchar* previous = src.ptr<uchar>(row);
		const uchar* next = src.ptr<uchar>(row+1);           //��������������ָ�����ͼ������
		uchar* output = dst.ptr<uchar>(row);
		for (int col = offsetx; col < cols; col++)
			{
				output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + previous[col] + next[vol]));
				//һ��Ҫ�����api���Ǵ������ط�Χ�ĺ���saturate_cast   ����������ȷ��RGB��ȡֵ��0��255֮�䡣С��0�ķ���0������255�ķ���255��
			}
	}

	//����ʾ��ģ������ͼ��
	namedWindow("contrast image demo", CV_WINDOW_AUTOSIZE);
	imshow("contrast image demo", dst);

	

	//����19��40�еķ�������api : filter2D Ҳ��ʵ��ͨ�����Ĳ����� ֻ�����У���    ��Ȼ�������ã�ֻ������  ����ҲҪ���������һ�ַ�����ԭ����Ҫ����API
	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);    //������Ĥ
	filter2D(src, dst, src.depth(), kernel);

	waitkey(0);
	return 0;
}