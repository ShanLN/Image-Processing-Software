#include "Imageview.h"

Imageview::Imageview(QWidget *parent)
	:BasicImageview(parent)
	,m_CImg(0)
{
	
}

Imageview::~Imageview()
{
}

void Imageview::setImage(CImage *srcImg)
{
	m_CImg = srcImg;
	cv::Mat srcMat = srcImg->getMat();
	QImage *tempQImg = 0;
	if (srcMat.type() == CV_8UC1)
	{
		const uchar *pSrc = (const uchar *)(srcMat.data);
		tempQImg = new QImage(pSrc, srcMat.cols, srcMat.rows, QImage::Format_Grayscale8);
	}
	else if (srcMat.type() == CV_8UC3)
	{
		const uchar *pSrc = (const uchar *)(srcMat.data);
		tempQImg = new QImage(pSrc, srcMat.cols, srcMat.rows, QImage::Format_RGB888);
		*tempQImg = tempQImg->rgbSwapped();      // because QImage uses Implicit Sharing 
	}
	else
		return;

	setQImage(tempQImg);
}

CImage *Imageview::getCImg()
{
	return m_CImg;
}
