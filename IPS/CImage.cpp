/*************************************\
CImage is the basic representation of our image.
In order to manage the memory, we implement CImage based on cv::Mat, 
which means OpenCV is needed in our software.

Implemented by Kealen @2017.9.27
\*************************************/

#include "CImage.h"

CImage::CImage()
{

}

CImage::CImage(const cv::Mat &srcMat)
{
	m_image = srcMat.clone();
}

CImage::CImage(const int &numRow, const int &numCol, const int &numChannel, unsigned char *pData)
{
	if (pData == NULL)
		return;
	if (numChannel == 1)
		m_image = cv::Mat(numRow, numCol, CV_8UC1,pData);
	if (numChannel == 3)
		m_image = cv::Mat(numRow, numCol, CV_8UC3,pData);
	else
		return;
}

CImage::CImage(const CImage &srcImg)
{
	m_image = srcImg.m_image;
}

CImage::~CImage()
{
}



double CImage::getMean()
{
	return m_mean;
}

double CImage::getStd(){
	return m_std;
}

cv::Mat CImage::getMat(){
	return m_image;
}