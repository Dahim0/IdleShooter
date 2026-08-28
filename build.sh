#!/bin/bash
clang++ Code/*.cpp -o game -lraylib \
  -framework OpenGL \
  -framework Cocoa \
  -framework IOKit \
  -framework CoreVideo
