#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <iomanip>

class Rectangle : public AbstractGeometricElement, public std::enable_shared_from_this<Rectangle> {
public:
    using SharedPtr = std::shared_ptr<Rectangle>;
    
    Rectangle (double width, double height)
    : AbstractGeometricElement("Rectangle", "Surface")
    , width(width)
    , height(height)
    {
    }

    virtual void accept(GeometricElementVisitorInterface& visitor) override {
        visitor.visit(shared_from_this());
    }

    double area() const {
        return width * height;
    }

private:
    double width;
    double height;
};
