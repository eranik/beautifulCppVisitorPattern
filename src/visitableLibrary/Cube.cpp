#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <iomanip>


class Cube : public AbstractGeometricElement, public std::enable_shared_from_this<Cube>  {
public:
    using SharedPtr = std::shared_ptr<Cube>;

    Cube (double width, double height, double length)
    : AbstractGeometricElement("Cube", "Volume")
    , width(width)
    , height(height)
    , length(length)
    {
    }

    virtual void accept(GeometricElementVisitorInterface& visitor) override {
        visitor.visit(shared_from_this());
    }

    double volume() const {
        return width * height * length;
    }

private:
    double width;
    double height;
    double length;
};
