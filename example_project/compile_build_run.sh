#!/bin/bash

# Clean build directory (if script is called with "--clean")
if [[ "$1" == "--clean" ]]; then
    echo "Cleaning build directory..."
    rm -rf build/*
fi

# Compile the project
cd build
cmake ..

# Build the project - use "make install" instead to install the project locally
make

# Run the project
./example_executable