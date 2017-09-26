#include "mainwindow.h"
#include <qaction.h>
#include <qmenu.h>
#include <qmenubar.h>
#include <qtoolbar.h>
#include <qstatusbar.h>

IPSMainwindow::IPSMainwindow(QWidget *parent)
	: QMainWindow(parent)
{
	setup();
}

IPSMainwindow::~IPSMainwindow()
{

}

void IPSMainwindow::setup()
{
	openAction = new QAction("open", this);
	
	saveAction = new QAction("save", this);

	saveAsAction = new QAction("save as", this);

	exitAction = new QAction("exit", this);


	fileMenu = menuBar()->addMenu("file");
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(saveAsAction);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);

	editMenu = menuBar()->addMenu("edit");
	

}
