# Adapters for the evolution algorithms
# Brian Tietz, May 2014

project(Adapters)

find_library(NN_LIB neuralNet)

add_library(${PROJECT_NAME} AnnealAdapter.cpp NeuroAdapter.cpp)
add_library(ntrt::learning::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		${NN_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
	ntrt::learning::AnnealEvolution
	ntrt::learning::NeuroEvolution
)