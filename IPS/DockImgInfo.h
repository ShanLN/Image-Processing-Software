#ifndef SRC_DOCKIMGINFO_H
#define SRC_DOCKIMGINFO_H

#include <qdockwidget.h>
#include <qtreewidget.h>

class DockImgInfo: public QDockWidget
{
	Q_OBJECT
public:
	DockImgInfo(QWidget *parent = 0);
	~DockImgInfo();


private:
	void setup();

	QTreeWidget *m_treeWidget;
	QTreeWidgetItem *m_HeadItemGeneral;
	QTreeWidgetItem *m_ItemImgPath;
	QTreeWidgetItem *m_ItemImgName;

	QTreeWidgetItem *m_HeadItemImg;
	QTreeWidgetItem *m_ItemMean;
	QTreeWidgetItem *m_ItemStd;

};



#endif //!SRC_DOCKIMGINFO_H
