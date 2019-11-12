cmake_minimum_required(VERSION 3.15)

cmake_policy(SET CMP0083 NEW)

project(NTRT
        VERSION 1.1
        DESCRIPTION "NTRT NASA Tensegrity_Robotics_Toolkit - A collection of software modules for the modeling,\
                    simulation, and control of Tensegrity Robots"
        LANGUAGES CXX)

option(BUILD_DOC "Enable building library documentation" OFF)
option(BUILD_EXAMPLES "Enable building library examples" OFF)
option(BUILD_TESTING "Enable building the tests" OFF)
option(BUILD_SHARED_LIBS "Enable building all the library as shared" OFF)
option(USE_DOUBLE_PRECISION "Enable Bullet Physic library to use double precision" ON)

if(USE_DOUBLE_PRECISION)
    message("-- Exploit double precision")
    add_compile_definitions(BT_USE_DOUBLE_PRECISION)
endif()

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)

    include(CheckPIESupported)
    check_pie_supported()

    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDE's
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)

    if(BUILD_DOC)
        # Docs only available if this is the main app
        find_package(Doxygen)
        if(Doxygen_FOUND)
            add_subdirectory(docs)
        else()
            message(STATUS "Doxygen not found, not building docs")
        endif()
    endif()
endif()

# select which type of build perform
set(default_build_type "RelWithDebInfo")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
            STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
            "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# in addition to the default installation path, add two more paths
# where required libraries can be found on the system
list(APPEND CMAKE_PREFIX_PATH /usr/local/include ${CMAKE_SOURCE_DIR}/external/env)

# load required libraries
find_package(Boost 1.71 REQUIRED COMPONENTS regex random)
find_package(Bullet 2.88 REQUIRED)
find_package(jsoncpp 1.9.0 REQUIRED)
find_package(yaml-cpp 0.6.3 REQUIRED)
find_package(GTest 1.10.0 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_library(GLU REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLIB REQUIRED glib-2.0)

# source files
add_subdirectory(src)

# Bring in the bullet graphics dependencies, etc.
#include(src/inc.CMakeBullet.txt)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # examples files
    if(BUILD_EXAMPLES)
        add_subdirectory(examples)
    endif()

    if(BUILD_TESTING)
        add_subdirectory(test)
        add_subdirectory(test_integration)
    endif()
endif()


#add_library(ntrt src)


install(TARGETS ntrt
        EXPORT NTRT
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ntrtConfigVersion.cmake
        VERSION ${PACKAGE_VERSION}
        COMPATIBILITY AnyNewerVersion
)

install(EXPORT NTRT
        FILE NTRT.cmake
        NAMESPACE NTRT::
        DESTINATION lib/cmake/NTRT
)

configure_file(src/NTRTConfig.cmake.in src/NTRTConfig.cmake @ONLY)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/src/NTRTConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/NTRTConfigVersion.cmake"
        DESTINATION lib/cmake/NTRT
)