#ifndef CUBE_H_
#define CUBE_H_

#include <memory>

#include "AbstractGeometricElement.h"
#include "GeometricElementVisitorInterface.h"

class Cube : public AbstractGeometricElement, public std::enable_shared_from_this<Cube>  {
public:
    using SharedPtr = std::shared_ptr<Cube>;

    Cube (double width, double height, double length);

    virtual void accept(GeometricElementVisitorInterface& visitor) override;

    double volume() const;

private:
    double width;
    double height;
    double length;
};

#endif