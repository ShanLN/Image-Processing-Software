#include "DockImgInfo.h"

DockImgInfo::DockImgInfo(QWidget *parent)
	:QDockWidget(parent)
{
	setup();
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