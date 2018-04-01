#ifndef SRC_THREADIO_H
#define SRC_THREADIO_H

#include <qthread.h>
#include <qvector.h>
#include <qmutex.h>

#include "CImage.h"

enum FLAG_IO
{
	Todo_openFile,
	Todo_saveFile
};

class ThreadIO: public QThread
{
	Q_OBJECT
public:
	ThreadIO();
	~ThreadIO();

	void toDoOpenFile(QString imgPath);
	void toDoSaveFile(QString imgPath);

	QVector<CImage*> getImage();
	
protected:
	void run();

private:
	void doOpenFile();
	void doSaveFile();

	QMutex m_mutex;
	FLAG_IO m_flag;
	QString m_imgPath;
	QVector<CImage*> m_CImgVec;

signals:
	void signal_threadBegin();
	void signal_threadEnd();

};


#endif //! SRC_THREADIO_H
