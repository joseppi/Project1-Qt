#include "rectangle.h"
#include <qpainter.h>
#include <qrect.h>
rectangle::rectangle() : Shape()
{
    this->type = ShapeType::RECTANGLE;
}

void rectangle::Draw(QPainter &painter, QBrush &brush, QPen &pen,const  QRect &scene_rect)

{
    brush.setColor(fill_color);
    pen.setWidth(stroke_thickness);
    pen.setColor(stroke_color);
    pen.setStyle(style);
    painter.setBrush(brush);
    painter.setPen(pen);

    painter.drawRect(rect);
}
