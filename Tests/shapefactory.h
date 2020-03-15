#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "shape.h"
#include <qlist.h>


class QPainter;
class QBrush;
class QPen;
class QRect;

class ShapeFactory
{
public:
    QList<Shape*> shapes;

public:
    ShapeFactory();
    Shape* CreateShape(ShapeType type);
    void CreateShape(Shape* shape);
    void DrawShapeList(QPainter &painter, QBrush &brush, QPen &pen,const QRect &scene_rect);
    QList<Shape*> GetShapes();
};

#endif // SHAPEFACTORY_H
