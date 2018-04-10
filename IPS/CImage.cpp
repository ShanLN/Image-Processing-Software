/*************************************\
CImage is the basic representation of our image.
In order to manage the memory, we implement CImage based on cv::Mat, 
which means OpenCV is needed in our software.

Implemented by Kealen @2017.9.27
\*************************************/

#include "CImage.h"

CImage::CImage()
	:m_evaFlag(true)
{

}

CImage::CImage(const cv::Mat &srcMat)
	:m_evaFlag(true)
{
	m_image = srcMat.clone();
}

CImage::CImage(const int &numRow, const int &numCol, const int &numChannel, unsigned char *pData)
	:m_evaFlag(true)
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
	:m_evaFlag(true)
{
	m_image = srcImg.m_image;
}

CImage::~CImage()
{
}



double CImage::getMean() 
{
	if (m_evaFlag) {
		evaluateImg();
		m_evaFlag = false;
	}
		
	return m_mean;
}

double CImage::getStd() 
{
	if (m_evaFlag) {
		evaluateImg();
		m_evaFlag = false;
	}

	return m_std;
}

cv::Mat CImage::getMat() 
{
	return m_image;
}

void CImage::setImgPath(std::string imgPath)
{
	if (!imgPath.empty())
		m_imgPath = imgPath;
	else
		m_imgPath = "./untitle.jpg";
}

std::string CImage::getImgPath()
{
	return m_imgPath;
}

void CImage::evaluateImg()
{
	cv::Scalar meanVal, stdVal;
	cv::meanStdDev(m_image, meanVal, stdVal);

	m_mean = meanVal.val[0];
	m_std = stdVal.val[0];
}