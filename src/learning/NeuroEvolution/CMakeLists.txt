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
		$<INSTALL_INTERFACE:include>
		${NN_ROOT}/${NN_INCLUDE_DIR}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
		ntrt::learning::Configuration
		ntrt::helpers::FileHelpers
		${NN_LIB}
)

# library installation
install(TARGETS ${PROJECT_NAME}
		EXPORT ${CMAKE_PROJECT_NAME}
		LIBRARY DESTINATION ${LIB_INSTALL_DIR}
		ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
		RUNTIME DESTINATION ${BIN_INSTALL_DIR}
		INCLUDES DESTINATION ${INCLUDE_INSTALL_DIR}
)
list(APPEND EXPORT_TARGETS ${PROJECT_NAME})