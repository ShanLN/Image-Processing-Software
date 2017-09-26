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
	setWindowTitle("IPS");
	setWindowIcon(QIcon("./Images/Icon/46.png"));
	showMaximized();
	
}

IPSMainwindow::~IPSMainwindow()
{

}

void IPSMainwindow::setup()
{
	openAction = new QAction("open", this);
	openAction->setIcon(QIcon("./Images/Icon/35.png"));
	openAction->setStatusTip("open an image.");
	
	saveAction = new QAction("save", this);
	saveAction->setIcon(QIcon("./Images/Icon/34.png"));
	saveAction->setStatusTip("save an image.");

	saveAsAction = new QAction("save as", this);
	saveAsAction->setIcon(QIcon("./Images/Icon/44.png"));
	saveAsAction->setStatusTip("save as an image.");

	exitAction = new QAction("exit", this);
	exitAction->setIcon(QIcon("./Images/Icon/40.png"));
	exitAction->setStatusTip("exit the software.");
	connect(exitAction, &QAction::triggered, this, &QMainWindow::close);

	aboutAction = new QAction("about", this);
	aboutAction->setIcon(QIcon("./Images/Icon/52.png"));
	aboutAction->setStatusTip("information about the software.");

	//menu
	fileMenu = menuBar()->addMenu("file");
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(saveAsAction);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);

	editMenu = menuBar()->addMenu("edit");

	aboutMenu = menuBar()->addMenu("about");
	aboutMenu->addAction(aboutAction);

	//tool bar
	fileToolBar = addToolBar("file");
	fileToolBar->addAction(openAction);
	fileToolBar->addAction(saveAction);
	fileToolBar->addAction(saveAsAction);
	fileToolBar->addSeparator();
	fileToolBar->addAction(exitAction);

	editToolBar = addToolBar("edit");

}
