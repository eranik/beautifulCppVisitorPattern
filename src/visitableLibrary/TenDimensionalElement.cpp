#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <iomanip>

class TenDimensionalElement : public AbstractGeometricElement, public std::enable_shared_from_this<TenDimensionalElement>  {
public:
    using SharedPtr = std::shared_ptr<TenDimensionalElement>;

    TenDimensionalElement (std::array<double, 10> lengths)
    : AbstractGeometricElement("Ten Dimensional Element", "Ten Dimensional Volume")
    , lengths(lengths)
    {
    }

    virtual void accept(GeometricElementVisitorInterface& visitor) override {
        visitor.visit(shared_from_this());
    }

    double ten_dimensional_volume() const {
        double res = 1;
        for (auto l : lengths) {
            res *= fancy_orthagonalize(l);
        }
        return res;
    }

private:
    const double PI = std::acos(-1);
    std::array<double, 10> lengths;

    double fancy_orthagonalize(double geometric_elements) const {
        return geometric_elements * std::cos(PI / 6);
    }
};
