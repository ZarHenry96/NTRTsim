project(util)

find_library(LINEAR_MATH_LIB LinearMath)

add_library(${PROJECT_NAME}
		CPGNode.cpp
		CPGEquations.cpp
		CPGNodeFB.cpp
		CPGEquationsFB.cpp
		tgBaseCPGNode.cpp
)
add_library(ntrt::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
		${BULLET_INCLUDE_DIRS}
		${Boost_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
		ntrt::controllers
		ntrt::core
		${LINEAR_MATH_LIB}
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