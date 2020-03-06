#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "shape.h"

class ShapeFactory
{
public:
    ShapeFactory();
    Shape CreateShape(ShapeType type);
};

#endif // SHAPEFACTORY_H
