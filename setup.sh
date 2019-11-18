#!/bin/bash

# ======================= #
#   INSTALLATION SCRIPT   #
# ======================= #

# build external dependencies
echo "Installing library dependencies"
pushd external > /dev/null

# generate configuration files (if they have not already been created)
./setup_dependencies.sh

# build and install library dependencies
./setup_dependencies.sh
popd

# build NTRT library
echo "Configuring library build..."
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release || { echo "Error while configuring the build -- exiting now."; exit 1; }
echo "Done!"
echo "Building the library..."
cmake --build build -j || { echo "Error while building the library -- exiting now."; exit 1; }
echo "Done!"
echo "Installing the library..."
cmake --install build || { echo "Error while installing the library -- exiting now."; exit 1; }
echo "Done!"
