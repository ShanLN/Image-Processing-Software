#ifndef CIMAGE_H
#define CIMAGE_H

#include <cv.h>

class CImage
{
public:
	CImage();
	CImage(const cv::Mat &srcMat);
	CImage(const int &numRow, const int &numCol, const int &numChannel, unsigned char *pData);
	CImage(const CImage &srcImg);
	~CImage();

	double getMean();
	double getStd();
	cv::Mat getMat();

private:
	cv::Mat m_image;
	double m_mean;
	double m_std;
};




#endif // !CIMAGE_H

