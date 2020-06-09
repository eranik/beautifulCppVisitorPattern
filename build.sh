#!/bin/bash

mv ./VisitorWithDataInAndOut.exe /tmp
g++ -O2 -std=c++2a ./VisitorWithDataInAndOut.cpp  -o VisitorWithDataInAndOut.exe |& tee VisitorWithDataInAndOut.log

