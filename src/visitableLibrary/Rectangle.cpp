#include "Rectangle.h"

Rectangle::Rectangle (double width, double height)
: AbstractGeometricElement("Rectangle", "Surface")
, width(width)
, height(height)
{
}

void Rectangle::accept(GeometricElementVisitorInterface& visitor) {
    visitor.visit(shared_from_this());
}

double Rectangle::area() const {
    return width * height;
}
