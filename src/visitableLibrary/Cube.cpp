#include "Cube.h"

Cube::Cube (double width, double height, double length)
: AbstractGeometricElement("Cube", "Volume")
, width(width)
, height(height)
, length(length)
{
}

void Cube::accept(GeometricElementVisitorInterface& visitor) {
    visitor.visit(shared_from_this());
}

double Cube::volume() const {
    return width * height * length;
}
