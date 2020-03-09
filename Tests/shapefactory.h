#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "shape.h"
#include <qlist.h>

class ShapeFactory
{
public:
    QList<Shape*> shapes;

public:
    ShapeFactory();
    Shape* CreateShape(ShapeType type);


};

#endif // SHAPEFACTORY_H
