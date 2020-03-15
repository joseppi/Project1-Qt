#ifndef SHAPE_H
#define SHAPE_H

#include <qrect.h>
#include <QPainter>

class QPainter;
class QBrush;
class QPen;
class QRect;


enum ShapeType {
    SHAPE_UNDEFINED,
    RECTANGLE,
    ELIPSE
};


class Shape
{
public:
    Shape();    
    virtual void Draw(QPainter &painter, QBrush &brush, QPen &pen,const QRect &scene_rect);

public:
    QRect rect;
    ShapeType type;
    QColor fill_color;
    QColor stroke_color;
    Qt::PenStyle style;
    int stroke_thickness;
    int id;

};

#endif // SHAPE_H
