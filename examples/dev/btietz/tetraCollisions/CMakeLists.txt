project(tetraCollisions)

configure_file("controlVars.json" "controlVars.json" COPYONLY)

find_library(LINEAR_MATH_LIB LinearMath)

add_library(tetraCollisions tscDataLogger.cpp tscDataObserver.cpp)
target_include_directories(tetraCollisions PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(tetraCollisions PRIVATE
		ntrt::core
		ntrt::util
		${LINEAR_MATH_LIB}
)