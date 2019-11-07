# Adapters for the evolution algorithms
# Brian Tietz, May 2014

project(Adapters)

# Add a library with the same name as the project. The library will contain all of the 
# files listed along with any files referenced by those files, so you usually only have
# to include the 'main' files in this list.

add_library(${PROJECT_NAME} AnnealAdapter.cpp)
add_library(ntrt::learning::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)
target_link_libraries(${PROJECT_NAME} PRIVATE ntrt::learning::AnnealEvolution)