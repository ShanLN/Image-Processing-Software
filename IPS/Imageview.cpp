#include "Imageview.h"

Imageview::Imageview(QWidget *parent)
	:BasicImageview(parent)
{
	
}

Imageview::~Imageview()
{
}

void Imageview::setImage(CImage *srcImg)
{
	cv::Mat srcMat = srcImg->getMat();
	QImage *tempQImg = 0;
	if (srcMat.type() == CV_8UC1)
		tempQImg = new QImage(srcMat.data, srcMat.cols, srcMat.rows, QImage::Format_Grayscale8);
	else if (srcMat.type() == CV_8UC3)
		tempQImg = new QImage(srcMat.data, srcMat.cols, srcMat.rows, QImage::Format_BGR30);
	else
		return;

	setQImage(tempQImg);
}