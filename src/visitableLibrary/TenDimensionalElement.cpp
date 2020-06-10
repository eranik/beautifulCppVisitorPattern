#include "TenDimensionalElement.h"

TenDimensionalElement::TenDimensionalElement (std::array<double, 10> lengths)
: AbstractGeometricElement("Ten Dimensional Element", "Ten Dimensional Volume")
, lengths(lengths)
{
}

void TenDimensionalElement::accept(GeometricElementVisitorInterface& visitor) {
    visitor.visit(shared_from_this());
}

double TenDimensionalElement::ten_dimensional_volume() const {
    double res = 1;
    for (auto l : lengths) {
        res *= fancy_orthagonalize(l);
    }
    return res;
}

double TenDimensionalElement::fancy_orthagonalize(double geometric_elements) const {
    return geometric_elements * std::cos(PI / 6);
}
