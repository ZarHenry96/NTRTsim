project(FileHelpers)

# Compose our header file for resource inclusion
set(RESOURCE_PATH "${CMAKE_SOURCE_DIR}/resources/src")
set(TEST_RESOURCE_PATH "${CMAKE_SOURCE_DIR}/resources/test")
configure_file("${FileHelpers_SOURCE_DIR}/resources.h.in" "${FileHelpers_BINARY_DIR}/resources.h")

add_library(FileHelpers FileHelpers.cpp)
add_library(ntrt::helpers::${PROJECT_NAME} ALIAS FileHelpers)

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)
