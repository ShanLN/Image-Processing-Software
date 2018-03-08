#ifndef BASICIMAGEVIEW_H
#define BASICIMAGEVIEW_H

#include <qgraphicsitem.h>
#include <qgraphicsview.h>
#include <qgraphicsscene.h>
#include <qevent.h>

class BasicImageview: public QGraphicsView
{
	Q_OBJECT
public:
	BasicImageview(QWidget *parent = 0);
	~BasicImageview();

	void setImage(QImage *QImg);

protected:
	void wheelEvent(QWheelEvent *event);

private:
	void scaleImage();
	QGraphicsScene *m_scene;
	QGraphicsPixmapItem *m_pixmapItem;
	QImage *m_image;

	double m_scaleRate;
	QPoint m_mousePoint;
	QPoint m_scrollPoint;
};



#endif  //!BASICIMAGEVIEW_H

