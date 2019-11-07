project(util)

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
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		${BULLET_INCLUDE_DIRS}
		${Boost_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
		ntrt::controllers
		ntrt::core
		LinearMath
		boost
)

