#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <iomanip>



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
