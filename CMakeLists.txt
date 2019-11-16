cmake_minimum_required(VERSION 3.15)

cmake_policy(SET CMP0069 NEW) # IPO flags behaviour
cmake_policy(SET CMP0083 NEW) # PIE related flags (for linking phase)

project(ntrt
        VERSION 1.1
        DESCRIPTION "NTRT NASA Tensegrity Robotics Toolkit - A collection of software modules for the modeling,\
                    simulation, and control of Tensegrity Robots"
        LANGUAGES CXX)

# default building options that can be customized at configuration time
option(BUILD_DOC "Enable building library documentation" OFF)
option(BUILD_EXAMPLES "Enable building library examples" ON)
option(BUILD_DEV_EXAMPLES "Enable building library dev examples" OFF)
option(BUILD_TESTING "Enable building the tests" OFF)
option(BUILD_SHARED_LIBS "Enable building all the library as shared" OFF)
option(USE_DOUBLE_PRECISION "Enable Bullet Physic library to use double precision" ON)
option(ENABLE_IPO "Enable Inter-Procedural Optimization" ON)
option(ENABLE_CCACHE "Enable CCache to improve repeated compilations" OFF)

if(USE_DOUBLE_PRECISION)
    message("-- Build with Double Precision")
    add_compile_definitions(BT_USE_DOUBLE_PRECISION)
endif()

# Only do these if this is the main project (not building by add_subdirectory directive)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # C++ Compiler configs
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)

    include(CheckPIESupported)
    check_pie_supported()

    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # program and compiler optimizations
    include(CheckIPOSupported)
    check_ipo_supported(RESULT IPO_SUPPORT)
    if(IPO_SUPPORT AND ENABLE_IPO)
        message("-- Inter-Procedural Optimization (IPO) enabled")
        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
    endif()

    find_program(CCACHE_PROGRAM ccache)
    if(CCACHE_PROGRAM AND ENABLE_CCACHE)
        message("-- CCache enabled")
        set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
    endif()

    # add support folders in IDE
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)

    # Docs only available if this is the main app
    if(BUILD_DOC)
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
find_package(Boost 1.71 REQUIRED COMPONENTS regex random OPTIONAL_COMPONENTS chrono system)
find_package(Bullet 2.88 REQUIRED)
find_package(jsoncpp 1.9.0 REQUIRED)
find_package(yaml-cpp 0.6.3 REQUIRED)
find_package(GTest 1.10.0 REQUIRED)
find_package(neuralNet REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_library(GLU REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLIB REQUIRED glib-2.0)

# source files
add_subdirectory(src)


# additional targets to be compiled
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    message("-- Checking other folders")
    if(BUILD_EXAMPLES)
        message("-- Examples will be built")
        add_subdirectory(examples)
    endif()

    if(BUILD_TESTING)
        message("-- Tests will be built")

        set(THREADS_PREFER_PTHREAD_FLAG ON)
        find_package(Threads REQUIRED)

        add_subdirectory(test)
        add_subdirectory(test_integration)
    endif()
endif()


# configure installation directories and targets
set(INCLUDE_INSTALL_DIR include/${PROJECT_NAME} CACHE PATH "The directory to the header files")
set(LIB_SUFFIX "" CACHE STRING "Define suffix of directory name (32/64)")
set(LIB_INSTALL_DIR lib${LIB_SUFFIX} CACHE PATH "The directory to the library files")
set (NTRT_CONFIG_CMAKE_PATH lib${LIB_SUFFIX}/cmake/${PROJECT_NAME})

# installation process
install(TARGETS ntrt
        EXPORT ${PROJECT_NAME}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)
list(APPEND EXPORT_TARGETS ${PROJECT_NAME})

include(CMakePackageConfigHelpers)
configure_package_config_file(
        ${PROJECT_NAME}Config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        INSTALL_DESTINATION ${NTRT_CONFIG_CMAKE_PATH}
        PATH_VARS INCLUDE_INSTALL_DIR
)
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        VERSION ${PACKAGE_VERSION}
        COMPATIBILITY AnyNewerVersion
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION ${NTRT_CONFIG_CMAKE_PATH}
)
install(EXPORT ${PROJECT_NAME}
        FILE ${PROJECT_NAME}.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${NTRT_CONFIG_CMAKE_PATH}
)