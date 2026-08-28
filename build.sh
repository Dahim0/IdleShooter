#!/bin/bash
clang++ $(find Code -name "*.cpp") -o game -I. -lraylib