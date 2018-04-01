#include "BasicImageview.h"
#include <qscrollbar.h>

BasicImageview::BasicImageview(QWidget *parent)
	:QGraphicsView(parent)
	, m_scene(0)
	, m_image(0)
	, m_pixmapItem(0)
{
	m_scene = new QGraphicsScene(this);
	setScene(m_scene);
}

BasicImageview::~BasicImageview()
{
	if (m_pixmapItem != NULL)
		delete m_pixmapItem;
	if (m_scene != NULL)
		delete m_scene;

}

void BasicImageview::setQImage(QImage *QImg)
{
	if (QImg == NULL)
		return;

	if (m_image == 0)
	{
		m_image = QImg;

		m_scene->setSceneRect(0, 0, QImg->width(), QImg->height());
		m_pixmapItem = m_scene->addPixmap(QPixmap::fromImage(*QImg));
		m_scaleRate = 1.0;
	}
	else
	{
		m_scene->setSceneRect(0, 0, QImg->width(), QImg->height());
		m_pixmapItem->setPixmap(QPixmap::fromImage(*QImg));

	}
	
	show();
}

void BasicImageview::scaleImage()
{
	QPoint refPoint = m_mousePoint + m_scrollPoint;
	QPoint newRefPoint = refPoint*m_scaleRate* m_image->width() / (m_scene->width());
	QPoint newScrollPoint = newRefPoint - m_mousePoint;

	horizontalScrollBar()->setSliderPosition(newScrollPoint.x());
	verticalScrollBar()->setSliderPosition(newScrollPoint.y());

	m_scene->setSceneRect(0, 0, m_image->width()*m_scaleRate, m_image->height()*m_scaleRate);
	m_pixmapItem->setScale(m_scaleRate);
	update();
}


void BasicImageview::wheelEvent(QWheelEvent *event)
{
	if (event->modifiers() == Qt::ControlModifier)
	{
		QPoint numDegrees = event->angleDelta() /120;   //(0,15) or (0,-15)
		double num = event->delta() / 120.0 ; //num = 1 or -1;
		
		m_mousePoint = event->pos();
		m_scrollPoint = QPoint(horizontalScrollBar()->sliderPosition(),
			                   verticalScrollBar()->sliderPosition());
		if (num > 0)
			m_scaleRate = m_scaleRate*1.01;
		else
			m_scaleRate = m_scaleRate*0.99;

		scaleImage();
	}
}
