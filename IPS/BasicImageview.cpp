#include "BasicImageview.h"

BasicImageview::BasicImageview(QWidget *parent)
	:QGraphicsView(parent)
	,m_scene(0)
	,m_image(0)
{
	m_scene = new QGraphicsScene(this);
	setScene(m_scene);
}

BasicImageview::~BasicImageview()
{
	if (m_image != NULL)
		delete m_image;
	if (m_scene != NULL)
		delete m_scene;

}

void BasicImageview::setImage(const QImage *QImg)
{
	if (QImg == NULL)
		return;

	if (m_image == 0)
	{
		m_scene->setSceneRect(0, 0, QImg->width(), QImg->height());
		m_image = m_scene->addPixmap(QPixmap::fromImage(*QImg));
	}
	else
	{
		m_scene->setSceneRect(0, 0, QImg->width(), QImg->height());
		m_image->setPixmap(QPixmap::fromImage(*QImg));

	}
	
	show();
}