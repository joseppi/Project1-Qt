#include "rectangle.h"
#include <qpainter.h>
#include <qrect.h>
rectangle::rectangle() : Shape()
{
    this->type = ShapeType::RECTANGLE;
}

void rectangle::Draw(QPainter &painter, QBrush &brush, QPen &pen,const  QRect &scene_rect)

{
    QColor whiteColor = QColor::fromRgb(255,255,255);
    QColor blackColor = QColor::fromRgb(0,0,0);

        brush.setColor(fill_color);
        pen.setWidth(4);
        pen.setColor(stroke_color);
        pen.setStyle(Qt::PenStyle::DashLine);
        painter.setBrush(brush);
        painter.setPen(pen);

    painter.drawRect(rect);
}
