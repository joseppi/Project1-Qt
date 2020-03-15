#include "shape.h"
Shape::Shape()
{
    rect.setRect(0,0,100,100);
    fill_color = QColor::fromRgb(255,255,255);
    stroke_color = QColor::fromRgb(0,0,0);
}

void Shape::Draw(QPainter &painter, QBrush &brush, QPen &pen,const QRect &scene_rect)
{

}



