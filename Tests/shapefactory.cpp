#include "shapefactory.h"
#include "shape.h"
#include "rectangle.h"

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

   shapes.append(new_shape);
   return new_shape;
}
