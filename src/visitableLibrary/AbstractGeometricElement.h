#ifndef GEOMETRIC_ELEMENT_H_
#define GEOMETRIC_ELEMENT_H_

#include <string>
#include <memory>

// #include "GeometricElementVisitorInterface.h"
class GeometricElementVisitorInterface;

class AbstractGeometricElement {
public:
    using SharedPtr = std::shared_ptr<AbstractGeometricElement>;
    virtual void accept(GeometricElementVisitorInterface& visitor) = 0;

    AbstractGeometricElement(std::string name = "GeometricElement", std::string n_dimentional_volume_keyword = "Volume");

    std::string get_name() const;
    std::string get_n_dimentional_volume_keyword() const;
    
protected:
    std::string name;
    std::string n_dimentional_volume_keyword;
};

#endif