#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <memory>

#include "AbstractGeometricElement.h"
#include "GeometricElementVisitorInterface.h"

class Rectangle : public AbstractGeometricElement, public std::enable_shared_from_this<Rectangle> {
public:
    using SharedPtr = std::shared_ptr<Rectangle>;
    
    Rectangle (double width, double height);

    void accept(GeometricElementVisitorInterface& visitor) override;

    double area() const;

private:
    double width;
    double height;
};

#endif