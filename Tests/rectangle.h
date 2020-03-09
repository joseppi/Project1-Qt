#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class rectangle : public Shape
{
public:
    rectangle();
    void Draw() override;
};

#endif // RECTANGLE_H
