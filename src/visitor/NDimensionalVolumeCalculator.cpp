#include <memory>
#include <vector>
#include <tuple>

#include "AbstractGeometricElement.h"
#include "GeometricElementVisitorInterface.h"
#include "Rectangle.h"
#include "Cube.h"
#include "TenDimensionalElement.h"

#include "NDimensionalVolumeCalculator.h"

NDimensionalVolumeCalculator::NDimensionalVolumeCalculator()
: dataHolderPtr(std::make_shared<DataHolder>())
{
}

void NDimensionalVolumeCalculator::visit(Rectangle::SharedPtr rectangle) {
    dataHolderPtr->add_data(rectangle, rectangle->area());
}

void NDimensionalVolumeCalculator::visit(Cube::SharedPtr cube) {
    dataHolderPtr->add_data(cube, cube->volume());
}

void NDimensionalVolumeCalculator::visit(TenDimensionalElement::SharedPtr ten_dim_elem) {
    dataHolderPtr->add_data(ten_dim_elem, ten_dim_elem->ten_dimensional_volume());
}

NDimensionalVolumeCalculator::DataHolderPtr NDimensionalVolumeCalculator::get_data_holder_ptr() {
    return dataHolderPtr;
}
