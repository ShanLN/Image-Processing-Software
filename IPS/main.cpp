#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include "CImage.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	IPSMainwindow w;

	

	w.show();
	return a.exec();
}
