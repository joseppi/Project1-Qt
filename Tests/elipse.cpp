#include "elipse.h"
#include <qpainter.h>
#include <qrect.h>

Elipse::Elipse()
{
    this->type = ShapeType::ELIPSE;
}

void Elipse::Draw(QPainter &painter, QBrush &brush, QPen &pen, const QRect &scene_rect)
{
    brush.setColor(fill_color);
    pen.setWidth(stroke_thickness);
    pen.setColor(stroke_color);
    pen.setStyle(style);
    painter.setBrush(brush);
    painter.setPen(pen);

    painter.drawEllipse(rect);
}
