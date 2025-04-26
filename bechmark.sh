#!/bin/bash

set -e


echo "Compiling raw_pointer.cpp..."
g++ -O3 raw_pointer.cpp -o raw_pointer

echo "Compiling smart_pointer.cpp..."
g++ -O3 smart_pointer.cpp -o smart_pointer

echo ""
echo "Running raw_pointer:"
./raw_pointer


echo ""
echo "Running smart_pointer:"
./smart_pointer
