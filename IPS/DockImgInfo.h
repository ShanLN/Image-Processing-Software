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

	void setImgInfo(const int &flag, double *data =NULL, QStringList list = QStringList(QString()));

private:
	void setup();
	void clearData();
	void setGeneralSec(QStringList list);
	void setImageSec(double *data);

	QTreeWidget *m_treeWidget;
	QTreeWidgetItem *m_HeadItemGeneral;
	QTreeWidgetItem *m_ItemImgPath;
	QTreeWidgetItem *m_ItemImgName;

	QTreeWidgetItem *m_HeadItemImg;
	QTreeWidgetItem *m_ItemMean;
	QTreeWidgetItem *m_ItemStd;

};



#endif //!SRC_DOCKIMGINFO_H
