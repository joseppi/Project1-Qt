#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle : public Shape
{
public:
    rectangle();
    void Draw(QPainter &painter, QBrush &brush, QPen &pen,const QRect &scene_rect) override;
};

#endif // RECTANGLE_H
