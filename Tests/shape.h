#ifndef SHAPE_H
#define SHAPE_H

enum ShapeType {
    SHAPE_UNDEFINED,
    RECTANGLE,
    ELIPSE
};

struct Position {
    float x;
    float y;
    float z;
};

struct Size {
    float w;
    float h;
};

class Shape
{
public:
    Shape();

public:
    Position pos;
    Size size;
    ShapeType type;
};

#endif // SHAPE_H
