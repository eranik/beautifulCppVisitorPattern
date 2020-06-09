#!/bin/bash

mkdir -p bin
pushd bin
	cmake ..
	make -j
	cp ./BeautifulModernVisitorPatternWithData .. 2>/dev/null
popd

