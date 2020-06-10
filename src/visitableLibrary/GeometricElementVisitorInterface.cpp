#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <iomanip>



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