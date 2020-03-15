#ifndef ELIPSE_H
#define ELIPSE_H


#include "shape.h"


class Elipse : public Shape
{
public:
    Elipse();
    void Draw(QPainter &painter, QBrush &brush, QPen &pen,const QRect &scene_rect) override;
};

#endif // ELIPSE_H
