cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project (BeautifulModernVisitorPatternWithData CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")
include_directories(./src/visitableLibrary ./src/visitor)
set (SOURCE_LIST 
	./src/main.cpp
	./src/visitableLibrary/AbstractGeometricElement.cpp
	./src/visitableLibrary/Cube.cpp
	./src/visitableLibrary/TenDimensionalElement.cpp
	./src/visitableLibrary/Rectangle.cpp
	./src/visitor/NDimensionalVolumeCalculator.cpp
)

add_executable(BeautifulModernVisitorPatternWithData ${SOURCE_LIST})
