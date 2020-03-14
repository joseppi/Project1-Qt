#include "shapefactory.h"
#include "shape.h"
#include "rectangle.h"
#include <QPainter>

ShapeFactory::ShapeFactory()
{

}

Shape* ShapeFactory::CreateShape(ShapeType type)
{
    Shape* new_shape = nullptr;

    switch (type) {
        case ShapeType::RECTANGLE:
            new_shape = (Shape*)new rectangle();
        break;

    }
   new_shape->id = shapes.length();

   shapes.append(new_shape);
   return new_shape;
}

void ShapeFactory::DrawShapeList(QPainter &painter, QBrush &brush, QPen &pen,const QRect &scene_rect)
{
    for (int i = 0; i < shapes.length(); i++) {
        shapes[i]->Draw(painter,brush,pen,scene_rect);
    }

    QColor blueColor = QColor::fromRgb(127,190,220);
    QColor whiteColor = QColor::fromRgb(255,255,255);
    QColor blackColor = QColor::fromRgb(0,0,0);



//    brush.setColor(whiteColor);
//    pen.setWidth(4);
//    pen.setColor(blackColor);
//    pen.setStyle(Qt::PenStyle::DashLine);
//    painter.setBrush(brush);
//    painter.setPen(pen);

//    //Draw circle
//    int r = scene_rect.width() /2;
//    int w = r*2;
//    int h = r*2;
//    int x = scene_rect.width() /2 - r;
//    int y = scene_rect.height() /2 - r;
//    QRect circleRect(x,y,w,h);
//    painter.drawEllipse(circleRect);
}
