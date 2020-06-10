#ifndef N_DIMENSIONAL_VOLUME_CALCULATOR_H_
#define N_DIMENSIONAL_VOLUME_CALCULATOR_H_

#include <memory>
#include <vector>
#include <tuple>

#include "AbstractGeometricElement.h"
#include "GeometricElementVisitorInterface.h"
#include "Rectangle.h"
#include "Cube.h"
#include "TenDimensionalElement.h"

class NDimensionalVolumeCalculator : public GeometricElementVisitorInterface {
public:
    // Internal class DataHolder
    class DataHolder {
    public:
        using DataPtr = std::shared_ptr<std::vector<std::tuple<AbstractGeometricElement::SharedPtr, double>>>;
        DataHolder()
        : data_ptr(std::make_shared<DataType>())
        {}
        void add_data(AbstractGeometricElement::SharedPtr ptr, double value) {
            data_ptr->push_back({ptr, value});
        }

        DataPtr get_data_ptr() {
            return data_ptr;
        }

    private:
        using DataType = std::vector<std::tuple<AbstractGeometricElement::SharedPtr, double>>;
        DataPtr data_ptr;
    };
    using DataHolderPtr = std::shared_ptr<NDimensionalVolumeCalculator::DataHolder>;
    // end of Internal class DataHolder

    NDimensionalVolumeCalculator();

    virtual void visit(Rectangle::SharedPtr rectangle) override;
    virtual void visit(Cube::SharedPtr cube) override;

    virtual void visit(TenDimensionalElement::SharedPtr ten_dim_elem) override;
    DataHolderPtr get_data_holder_ptr();

private:
    DataHolderPtr dataHolderPtr;
};

#endif