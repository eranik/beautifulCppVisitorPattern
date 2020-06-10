#include "GeometricElement.h"

#include <string>

AbstractGeometricElement::AbstractGeometricElement(std::string name = "AbstractGeometricElement", std::string n_dimentional_volume_keyword = "Volume")
:name(name)
, n_dimentional_volume_keyword(n_dimentional_volume_keyword)
{}

std::string AbstractGeometricElement::get_name() const {
    return name;
}

std::string AbstractGeometricElement::get_n_dimentional_volume_keyword() const {
    return n_dimentional_volume_keyword;
}