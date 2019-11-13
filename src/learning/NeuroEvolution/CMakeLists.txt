# Library of files that are common between tensegrity projects
# Compiled by Brian Tietz, June 2013

project(NeuroEvolution)

# Add a library with the same name as the project. The library will contain all of the 
# files listed along with any files referenced by those files, so you usually only have
# to include the 'main' files in this list. 

# Note: FileHelpers seems to be necessary, at least for build on mac...

find_library(NN_LIB neuralNet)

add_library(${PROJECT_NAME}
		NeuroEvolution.cpp
		NeuroEvoMember.cpp
		NeuroEvoPopulation.cpp
)
add_library(ntrt::learning::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		${NN_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
		ntrt::learning::Configuration
		ntrt::learning::AnnealEvolution
		ntrt::learning::NeuroEvolution
		ntrt::helpers::FileHelpers
		${NN_LIB}
)
