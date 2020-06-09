#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <iomanip>

class GeometricElement;
class Rectangle;
class Cube;
class TenDimensionalElement;

class GeometricElementVisitorInterface {
public:
    virtual void visit(std::shared_ptr<Rectangle> n) = 0;
    virtual void visit(std::shared_ptr<Cube> n) = 0;
    virtual void visit(std::shared_ptr<TenDimensionalElement> n) = 0;
};

class GeometricElement {
public:
    GeometricElement(std::string name = "GeometricElement", std::string n_dimentional_volume_keyword = "Volume")
    :name(name)
    , n_dimentional_volume_keyword(n_dimentional_volume_keyword)
    {}

    virtual void accept(GeometricElementVisitorInterface& visitor) = 0;
    using SharedPtr = std::shared_ptr<GeometricElement>;

    std::string get_name() const {
        return name;
    }

    std::string get_n_dimentional_volume_keyword() const {
        return n_dimentional_volume_keyword;
    }
protected:
    std::string name;
    std::string n_dimentional_volume_keyword;
};

class Rectangle : public GeometricElement, public std::enable_shared_from_this<Rectangle> {
public:
    using SharedPtr = std::shared_ptr<Rectangle>;
    
    Rectangle (double width, double height)
    : GeometricElement("Rectangle", "Surface")
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

class Cube : public GeometricElement, public std::enable_shared_from_this<Cube>  {
public:
    using SharedPtr = std::shared_ptr<Cube>;

    Cube (double width, double height, double length)
    : GeometricElement("Cube", "Volume")
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

class TenDimensionalElement : public GeometricElement, public std::enable_shared_from_this<TenDimensionalElement>  {
public:
    using SharedPtr = std::shared_ptr<TenDimensionalElement>;

    TenDimensionalElement (std::array<double, 10> lengths)
    : GeometricElement("Ten Dimensional Element", "Ten Dimensional Volume")
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

class NDimensionalVolumeCalculator : public GeometricElementVisitorInterface {
public:
    // Internal class DataHolder
    class DataHolder {
    public:
        using DataPtr = std::shared_ptr<std::vector<std::tuple<GeometricElement::SharedPtr, double>>>;
        DataHolder()
        : data_ptr(std::make_shared<DataType>())
        {}
        void add_data(GeometricElement::SharedPtr ptr, double value) {
            data_ptr->push_back({ptr, value});
        }

        DataPtr get_data_ptr() {
            return data_ptr;
        }

    private:
        using DataType = std::vector<std::tuple<GeometricElement::SharedPtr, double>>;
        DataPtr data_ptr;
    };
    using DataHolderPtr = std::shared_ptr<NDimensionalVolumeCalculator::DataHolder>;
    // end of Internal class DataHolder

    NDimensionalVolumeCalculator()
    : dataHolderPtr(std::make_shared<DataHolder>())
    {
    }

    virtual void visit(Rectangle::SharedPtr rectangle) override {
        dataHolderPtr->add_data(rectangle, rectangle->area());
    }

    virtual void visit(Cube::SharedPtr cube) override {
        dataHolderPtr->add_data(cube, cube->volume());
    }

    virtual void visit(TenDimensionalElement::SharedPtr ten_dim_elem) override {
        dataHolderPtr->add_data(ten_dim_elem, ten_dim_elem->ten_dimensional_volume());
    }

    DataHolderPtr get_data_holder_ptr() {
        return dataHolderPtr;
    }
    
private:
    DataHolderPtr dataHolderPtr;
};

int main() {
    std::vector<GeometricElement::SharedPtr> geometric_elements;
    geometric_elements.push_back(std::make_shared<Rectangle>(10.2, 20.3));
    geometric_elements.push_back(std::make_shared<Cube>(5.1, 6.2, 7.3));
    geometric_elements.push_back(std::make_shared<TenDimensionalElement>(std::array<double, 10>{1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10}));

    // Using visitor
    NDimensionalVolumeCalculator n_dimensional_volume_calculator;

    for (auto node_shared_ptr : geometric_elements) {
        node_shared_ptr->accept(n_dimensional_volume_calculator);
    }
    // end of using visitor

    // Print data from visitor DataHolder
    NDimensionalVolumeCalculator::DataHolder::DataPtr data_ptr = n_dimensional_volume_calculator.get_data_holder_ptr()->get_data_ptr();

    constexpr int WIDTH = 30;
    for (const auto&[element, value] : *data_ptr) {
        std::cout << std::left << std::setw(WIDTH) << element->get_name() + ":" <<  std::setw(WIDTH) << element->get_n_dimentional_volume_keyword() << std::setw(WIDTH) << value << std::endl;
    }
    // end of print data from visitor DataHolder

    return 0;
}
