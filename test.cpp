#include<iostream>
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

void ex2() { // 행렬 최소,최대 및 그 위치값 구하기.
	Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);
	double minv, maxv;
	Point minLoc, maxLoc;
	minMaxLoc(img, &minv, &maxv, &minLoc, &maxLoc);  // mask=noArray()  , mask 는 특정영역만 구할 시 사용. noArray()면 전체영역이 타겟임
}
void ex1() {  // 행렬 평균 구하기
	//gray
	Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE);
	double mean1 = mean(img1)[0];
	//bgr
	Mat img2 = imread("lenna.bmp", IMREAD_COLOR);
	Scalar m = mean(img2);
}

void ex3() { //자료형 변환 void Mat::convertTo(OutputArray m, int rtype, double alpha=1, double beta = 0) const; , 주어진 행렬에 연산을 할 수 있는 기능도 지님.
	Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat fimg;
	img.convertTo(fimg, CV_32FC1);

	Mat dst;
	fimg.convertTo(dst, CV_8UC1); //  dst 행렬을 fimg의 grayscale 타입으로 만ㄷ름.
}

void ex4() { // norm (원소값 범위 정규화 하는 옵션 지님)
	//void normalize(InputAraay src, InputOutputArray dst, double alpha = 1, double beta = 0, int norm_type = NORM_L2, int dtype = -1, InputArray mask  noArray());   
	// alpha : 목표 노름값, (NORM_MINMAX인 경우) 최솟값,  beta: NORM_MINMAX 인 경우 최댓값
	// norm_type : 정규화타입, NORM_MINMAX 중 하나를 지정.
	//dtype: 출력행렬 타입설정 가능하며 입력행렬과 출력행렬 타입을 다르게 만들 수 있다.
	//주어진 행렬에서 가장 작은값이 Alpha , 가장큰 값을 beta값이 되도록 설정해서 모든 행렬의 element값 조절하여 dst행렬로 만드는 함수.

	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat dst;
	normalize(src, dst, 0, 255, NORM_MINMAX);  // ex1 에서 최솟값 25, 최댓값 245 값은 각 0, 그리고 255 로 가깝게 하여 전체 픽셀값 변화를 시켜 dst 행렬을 만든다.
	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
}

void ex5() { //void cvtColor(InputArray src, OutputArray dst, int code, int dstCn = 0);
	Mat src = imread("lenna.bmp");
	Mat dst;
	cvtColor(src, dst, COLOR_BGR2GRAY);
	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
}
void split_func() { // void split(const Mat& src, Mat* mvbegin);   ==  void split(InputArray src, OutputArrayOfArrays mv);  src다채널행렬 mvbegin: dst Mat배열주소 , mv :  dst행렬의 벡터
    //다채널행렬 -> 단일채널행렬들로 만들어줌
	Mat src = imread("lenna.bmp");
	vector<Mat>planes;
	split(src, planes);
	imshow("src", src);

	for (int x = 0; x < 3; ++x) {
		string str = format("dst%d", x);
		imshow(str, planes[x]);
	}
	waitKey(0);
}
void merge_func() { //채널 결합.
	//void merge(const Mat* mv, size_t count , OutputArray dst);
	//void merge(InputArrayOfArrays mv, OutputArray dst);   
	//mv: 1채널  Mat 배열 또는 행렬의 벡터   [src]
	//count: (mv가 Mat 타입의 배열인 경우) Mat 배열 크기
	//dst 다채널행렬

	Mat src = imread("lenna.bmp");
	vector<Mat> planes;
	split(src, planes); //3개의 단일채널 영상 형성

	swap(planes[0], planes[2]);  //.B, R 성분 서로 바꿈.
	Mat dst;
	merge(planes, dst);
	imshow("src", src);  // 원래 빨강 픽셀성분이 좀 많았음
	imshow("dst", dst);  //swap으로 빨강과 파랑을 서로 바꿔주었기에 파랑성분이 많아짐. 
	waitKey(0);
}
void ex6() { // 채널 분리와 병합  
	//split_func();
	merge_func();
}
int main(void) {
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	//ex5();
	ex6();
	
}
