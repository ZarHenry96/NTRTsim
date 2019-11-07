#!/bin/bash

# Copyright © 2012, United States Government, as represented by the
# Administrator of the National Aeronautics and Space Administration.
# All rights reserved.
# 
# The NASA Tensegrity Robotics Toolkit (NTRT) v1 platform is licensed
# under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# http://www.apache.org/licenses/LICENSE-2.0.
# 
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
# either express or implied. See the License for the specific language
# governing permissions and limitations under the License.

# Purpose: GoogleTest setup
# Date:    2019-11-05

##############################################################################
#                         START DO NOT MODIFY                                #
##############################################################################
SCRIPT_PATH="`dirname \"$0\"`"
SCRIPT_PATH="`( cd \"$SCRIPT_PATH\" && pwd )`"
##############################################################################
#                          END DO NOT MODIFY                                 #
##############################################################################

# Add the relative path from this script to the helpers folder.
pushd "${SCRIPT_PATH}/helpers/" > /dev/null

##############################################################################
#                         START DO NOT MODIFY                                #
##############################################################################
if [ ! -f "helper_functions.sh" ]; then
    echo "Could not find helper_functions.sh. Are we in the bash helpers folder?"
    exit 1;
fi

# Import our common files
source "helper_functions.sh"
source "helper_paths.sh"
source "helper_definitions.sh"

# Get out of the bash helpers folder.
popd > /dev/null
##############################################################################
#                          END DO NOT MODIFY                                 #
##############################################################################

#Source this package's configuration
source_conf "general.conf"
source_conf "googletest.conf"

# Variables
googletest_pkg=`echo $GOOGLETEST_URL|awk -F/ '{print $NF}'`  # get the package name from the url

# Check to see if googletest has been built already
function check_googletest_built()
{
    # Check for a library that's created when googletest is built
    fname=$(find "$GOOGLETEST_BUILD_DIR" -iname libgtest* 2>/dev/null)
    if [ -f "$fname" ]; then
        return $TRUE
    fi
    return $FALSE
}

# Download the package to env/downloads
function download_googletest()
{

    googletest_pkg_path="$DOWNLOADS_DIR/$googletest_pkg"

    if [ -f "$googletest_pkg_path" ]; then
        echo "- GoogleTest package already exists ('$googletest_pkg_path') -- skipping download."
        return
    fi

    echo "Downloading $googletest_pkg to $googletest_pkg_path"
    download_file "$GOOGLETEST_URL" "$googletest_pkg_path"
}

# Unpack to the build directory specified in install.conf
function unpack_googletest()
{
    # Create directory and unpack
    if check_directory_exists "$GOOGLETEST_BUILD_DIR"; then
        echo "- GoogleTest is already unpacked to '$GOOGLETEST_BUILD_DIR' -- skipping."
        return
    fi

    echo "Unpacking googletestgoogletest to $GOOGLETEST_BUILD_DIR (this may take a minute...)"
    # TODO: Do we need to remove the dir if it already exists?
    create_directory_if_noexist $GOOGLETEST_BUILD_DIR

    # Unzip
    pushd "$GOOGLETEST_BUILD_DIR" > /dev/null
    tar -xf "$DOWNLOADS_DIR/$googletest_pkg" || { echo "- ERROR: Failed to unpack GoogleTest"; exit 1; }
    mv googletest*/* .
    popd > /dev/null
}

# Build the package under the build directory specified in in install.conf
function build_googletest()
{

    echo "- Building GoogleTest under $GOOGLETEST_BUILD_DIR"
    pushd "$GOOGLETEST_BUILD_DIR" > /dev/null

    # Perform the build
    # If you turn double precision on, turn it on in inc.CMakeGoogleTest.txt as well for the NTRT build
    "$ENV_DIR/bin/cmake" . -G "Unix Makefiles" \
        -DBUILD_SHARED_LIBS=OFF \
        -DCMAKE_INSTALL_PREFIX="$GOOGLETEST_INSTALL_PREFIX" \
        -DCMAKE_POSITION_INDEPENDENT_CODE=ON \
        -DCMAKE_INSTALL_NAME_DIR="$GOOGLETEST_INSTALL_PREFIX" || { echo "- ERROR: CMake for GoogleTest failed."; exit 1; }
    #If you turn this on, turn it on in inc.CMakeGoogleTest.txt as well for the NTRT build
    # Additional googletestgoogletest options:
    # -DFRAMEWORK=ON
    # -DBUILD_DEMOS=ON

    make || { echo "- ERROR: GoogleTest build failed"; exit 1; }

    popd > /dev/null
}

# Install the package under the package install prefix from install.conf
function install_googletest()
{

    echo "- Installing GoogleTest under $GOOGLETEST_INSTALL_PREFIX"

    pushd "$GOOGLETEST_BUILD_DIR" > /dev/null

#    create_exist_symlink $GOOGLETEST_BUILD_DIR/lib/libgmock.a $LIB_DIR/
#    create_exist_symlink $GOOGLETEST_BUILD_DIR/lib/libgmock_main.a $LIB_DIR/
#
#    create_exist_symlink $GOOGLETEST_BUILD_DIR/lib/libgtest.a $LIB_DIR/
#    create_exist_symlink $GOOGLETEST_BUILD_DIR/lib/libgtest_main.a $LIB_DIR/
    make install || { echo "Install failed -- maybe you need to use sudo when running setup?"; exit 1; }

   popd > /dev/null
}

# Create symlinks under env for building our applications and IDE integration
function env_link_googletest()
{

    # Build
    pushd "$ENV_DIR/build" > /dev/null
    rm googletest 2>/dev/null   # Note: this will fail if 'googletest' is a directory, which is what we want.

    # If we're building under env, use a relative path for the link; otherwise use an absolute one.
    if str_contains "$GOOGLETEST_BUILD_DIR" "$ENV_DIR"; then
        current_pwd=`pwd`
        rel_path=$(get_relative_path "$current_pwd" "$GOOGLETEST_BUILD_DIR" )
        create_exist_symlink "$rel_path" googletest
    else
        create_exist_symlink "$GOOGLETEST_BUILD_DIR" googletest  # this links directly to the most recent build...
    fi

    # Symlink our header files in
    create_exist_symlink $GOOGLETEST_BUILD_DIR/googletest/include/gtest $INCLUDE_DIR/gtest
    create_exist_symlink $GOOGLETEST_BUILD_DIR/googlemock/include/gmock $INCLUDE_DIR/gmock

    popd > /dev/null

}

function main()
{

    ensure_install_prefix_writable $GOOGLETEST_INSTALL_PREFIX

    if check_package_installed "$GOOGLETEST_INSTALL_PREFIX/lib/libgtest*"; then
        echo "- GoogleTest is installed under prefix $GOOGLETEST_INSTALL_PREFIX -- skipping."
        env_link_googletest
        return
    fi

    if check_googletest_built; then
        echo "- GoogleTest is already built under $GOOGLETEST_BUILD_DIR -- skipping."
        install_googletest
        env_link_googletest
        return
    fi

    if check_file_exists "$GOOGLETEST_PACKAGE_DIR/CMakeLists.txt"; then
        echo "- GoogleTest is already unpacked to $GOOGLETEST_BUILD_DIR -- skipping."
        build_googletest
        install_googletest
        env_link_googletest
        return
    fi

    if check_file_exists "$DOWNLOADS_DIR/$googletest_pkg"; then
        echo "- GoogleTest package already exists under env/downloads -- skipping download."
        unpack_googletest
        build_googletest
        install_googletest
        env_link_googletest
        return
    fi

    # If we haven't returned by now, we have to do everything
    download_googletest
    unpack_googletest
    build_googletest
    install_googletest
    env_link_googletest
}


main
