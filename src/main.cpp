#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>

#include "AbstractGeometricElement.h"
#include "Rectangle.h"
#include "Cube.h"
#include "TenDimensionalElement.h"
#include "NDimensionalVolumeCalculator.h"

int main() {
    std::vector<AbstractGeometricElement::SharedPtr> geometric_elements;
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
