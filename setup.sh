#!/bin/bash

# ======================= #
#   INSTALLATION SCRIPT   #
# ======================= #

gen_conf='INSTALL_PREFIX="/usr/local"'
ADD_FLAGS=''

if [ $# -gt 0 ]; then
    if [ "$1" == "local" ]; then
      echo -e "\nInstallation files will be placed in a local folder\n"
      # install NTRT library in a custom location
      ADD_FLAGS='-DCMAKE_INSTALL_PREFIX="external/env" -DCMAKE_INSTALL_NAME_DIR="external/env"'
      # updates general dependencies configuration
      gen_conf='INSTALL_PREFIX="$ENV_DIR"'
    else
      echo -e "\nInstallation files will be placed in the system folder\n"
    fi
fi

# updates general dependencies configuration
echo ${gen_conf} > external/conf/general.conf

# build external dependencies
echo "Installing library dependencies"
pushd external > /dev/null

# generate configuration files (if they have not already been created)
./setup_dependencies.sh

# build and install library dependencies
./setup_dependencies.sh || { echo -e "\nError installing the dependencies -- exiting now."; exit 1; }

popd
# ======================= #

# build NTRT library
echo "Configuring library build..."
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release ${ADD_FLAGS} || { echo -e "\nError while configuring the build -- exiting now."; exit 1; }
echo "Done!"
echo "Building the library..."
cmake --build build -j || { echo -e "\nError while building the library -- exiting now."; exit 1; }
echo "Done!"
echo "Installing the library..."
cmake --install build || { echo -e "\nError while installing the library -- exiting now."; exit 1; }
echo "Done!"
