#ifndef TEN_DIMENSIONAL_ELEMENT_H_
#define TEN_DIMENSIONAL_ELEMENT_H_

#include <memory>
#include <cmath>

#include "GeometricElementVisitorInterface.h"

class TenDimensionalElement : public AbstractGeometricElement, public std::enable_shared_from_this<TenDimensionalElement>  {
public:
    using SharedPtr = std::shared_ptr<TenDimensionalElement>;

    TenDimensionalElement (std::array<double, 10> lengths);

    virtual void accept(GeometricElementVisitorInterface& visitor) override;

    double ten_dimensional_volume() const;

private:
    const double PI = std::acos(-1);
    std::array<double, 10> lengths;

    double fancy_orthagonalize(double geometric_elements) const;
};

#endif