#include "rectangle.h"
#include <qpainter.h>
#include <qrect.h>
rectangle::rectangle() : Shape()
{

}

void rectangle::Draw(QPainter &painter, QBrush &brush, QPen &pen,const  QRect &scene_rect)

{
    QColor whiteColor = QColor::fromRgb(255,255,255);
    QColor blackColor = QColor::fromRgb(0,0,0);

        brush.setColor(whiteColor);
        pen.setWidth(4);
        pen.setColor(blackColor);
        pen.setStyle(Qt::PenStyle::DashLine);
        painter.setBrush(brush);
        painter.setPen(pen);

        //Draw circle
        int r = scene_rect.width() /2;
        int w = r*2;
        int h = r*2;
        int x = scene_rect.width() /2 - r;
        int y = scene_rect.height() /2 - r;
        painter.drawEllipse(rect);
    painter.drawRect(rect);
}
