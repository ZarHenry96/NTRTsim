# Adapters for the evolution algorithms
# Brian Tietz, May 2014

project(Adapters)

find_library(NN_LIB neuralNet)

add_library(${PROJECT_NAME} AnnealAdapter.cpp NeuroAdapter.cpp)
add_library(ntrt::learning::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
		${NN_ROOT}/${NN_INCLUDE_DIR}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
	ntrt::learning::AnnealEvolution
	ntrt::learning::NeuroEvolution
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