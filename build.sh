#!/bin/bash

mv ./BeautifulModernVisitorPatternWithData.exe /tmp 2>/dev/null
g++ -O2 -std=c++2a ./BeautifulModernVisitorPatternWithData.cpp  -o BeautifulModernVisitorPatternWithData.exe |& tee BeautifulModernVisitorPatternWithData.log

