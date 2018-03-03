#ifndef BASICIMAGEVIEW_H
#define BASICIMAGEVIEW_H

#include <qgraphicsitem.h>
#include <qgraphicsview.h>
#include <qgraphicsscene.h>

class BasicImageview: public QGraphicsView
{
	Q_OBJECT
public:
	BasicImageview(QWidget *parent = 0);
	~BasicImageview();

	void setImage(const QImage *QImg);

private:
	QGraphicsScene *m_scene;
	QGraphicsPixmapItem *m_image;

};



#endif  //!BASICIMAGEVIEW_H

