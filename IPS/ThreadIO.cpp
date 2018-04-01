#include "ThreadIO.h"
#include <qimage.h>
#include <cv.hpp>

ThreadIO::ThreadIO()
{
	
	m_CImgVec.clear();
}

ThreadIO::~ThreadIO()
{
}


void ThreadIO::toDoOpenFile(QString imgPath)
{
	QMutexLocker locker(&m_mutex);
	m_flag = Todo_openFile;
	m_imgPath = imgPath;

	start();
}

void ThreadIO::toDoSaveFile(QString imgPath)
{
	QMutexLocker locker(&m_mutex);
	m_flag = Todo_saveFile;
	m_imgPath = imgPath;

	start();
}


void ThreadIO::run()
{
	emit signal_threadBegin();

	switch (m_flag)
	{
	case Todo_openFile:
		doOpenFile();
		break;
	case Todo_saveFile:
		doSaveFile();
		break;
	default:
		break;
	}

	emit signal_threadEnd();
}


void ThreadIO::doOpenFile()
{
	std::string imgPath = m_imgPath.toStdString();
	cv::Mat srcMat = cv::imread(imgPath);
	if (srcMat.empty())
		return;

	CImage *srcCImg = new CImage(srcMat);
	
	m_CImgVec.push_back(srcCImg);
}

void ThreadIO::doSaveFile()
{

}

QVector<CImage*> ThreadIO::getImage()
{
	return m_CImgVec;
}