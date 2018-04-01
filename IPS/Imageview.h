#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include "BasicImageview.h"
#include "CImage.h"

class Imageview: public BasicImageview
{
	Q_OBJECT
public:
	Imageview(QWidget *parent = 0);
	~Imageview();
	void setImage(CImage *srcImg);

private:
	

};


#endif //! IMAGEVIEW_H
