#ifndef GEOMETRIC_ELEMENT_VISITOR_INTERFACE_H_
#define GEOMETRIC_ELEMENT_VISITOR_INTERFACE_H_

#include <memory>

#include "AbstractGeometricElement.h"
#include "Rectangle.h"
#include "Cube.h"
#include "TenDimensionalElement.h"

class AbstractGeometricElement;
class Rectangle;
class Cube;
class TenDimensionalElement;


class GeometricElementVisitorInterface {
public:
    virtual void visit(std::shared_ptr<Rectangle> n) = 0;
    virtual void visit(std::shared_ptr<Cube> n) = 0;
    virtual void visit(std::shared_ptr<TenDimensionalElement> n) = 0;
};

#endif