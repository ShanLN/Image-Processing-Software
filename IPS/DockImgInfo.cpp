#include "DockImgInfo.h"

DockImgInfo::DockImgInfo(QWidget *parent)
	:QDockWidget(parent)
{
	setup();
	setImgInfo(-1);
}

DockImgInfo::~DockImgInfo()
{

}

QTreeWidgetItem *addHeadItem(QTreeWidget *treeWidget, QString str)
{
	QTreeWidgetItem *headItem = new QTreeWidgetItem(treeWidget);
	headItem->setBackgroundColor(0, QColor(200, 200, 200));
	headItem->setBackgroundColor(1, QColor(200, 200, 200));
	headItem->setBackgroundColor(2, QColor(200, 200, 200));
	headItem->setText(1, str);
	return headItem;
}

QTreeWidgetItem *addItem(QTreeWidgetItem *headItem, QString str)
{
	QTreeWidgetItem *item = new QTreeWidgetItem(headItem);
	item->setText(1, str);
	item->setTextAlignment(1, Qt::AlignRight);
	item->setText(2, QString("-"));
	item->setTextAlignment(2, Qt::AlignLeft);
	return item;
}


void DockImgInfo::setup()
{
	m_treeWidget = new QTreeWidget(this);
	m_treeWidget->setColumnCount(3);
	m_treeWidget->setHeaderHidden(true);
	m_treeWidget->setColumnWidth(0, 30);
	m_treeWidget->setColumnWidth(1, 80);
	m_treeWidget->setColumnWidth(2, 100);

	m_HeadItemGeneral = addHeadItem(m_treeWidget, QString("General"));
	m_ItemImgPath = addItem(m_HeadItemGeneral, QString("path"));
	m_ItemImgName = addItem(m_HeadItemGeneral, QString("name"));

	m_HeadItemImg = addHeadItem(m_treeWidget, QString("Image"));
	m_ItemMean = addItem(m_HeadItemImg, QString("mean"));
	m_ItemStd = addItem(m_HeadItemImg, QString("std"));

	m_treeWidget->expandAll();
	setWidget(m_treeWidget);
}

void DockImgInfo::clearData()
{
	m_ItemImgPath->setText(2, QString("-"));
	m_ItemImgName->setText(2, QString("-"));

	m_ItemMean->setText(2, QString("-"));
	m_ItemStd->setText(2, QString("-"));
}

void DockImgInfo::setGeneralSec(QStringList list)
{
	m_ItemImgPath->setText(2, list.at(0));
	m_ItemImgName->setText(2, list.at(1));
}
void DockImgInfo::setImageSec(double *data)
{
	m_ItemMean->setText(2, QString("%1").arg(data[0]));
	m_ItemStd->setText(2, QString("%1").arg(data[1]));
}


void DockImgInfo::setImgInfo(const int &flag, double *data, QStringList list)
{
	if (flag == -1)
		clearData();

	switch (flag)
	{
	case 1:
		setGeneralSec(list);
		break;
	case 2:
		setImageSec(data);
		break;
	case 0:
		setGeneralSec(list);
		setImageSec(data);
		break;
	}
}