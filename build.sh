#!/bin/bash

mkdir -p bin
pushd bin
	cmake .. |& tee build.log
	make -j |& tee -a build.log
	cp ./BeautifulModernVisitorPatternWithData .. 2>/dev/null
popd

