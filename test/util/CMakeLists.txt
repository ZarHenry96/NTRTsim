project(tgcreator_test)

find_library(LINEAR_MATH_LIB LinearMath)
find_library(GTEST_LIB gtest)
find_library(GMOCK_LIB gmock)

add_executable(CPGEquations_test CPGEquations_test.cpp)
target_include_directories(CPGEquations_test PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		${BULLET_INCLUDE_DIRS}
		${GTEST_INCLUDE_DIRS}
)
target_link_libraries(CPGEquations_test PRIVATE
		ntrt::terrain
		ntrt::core
		ntrt::controllers
		ntrt::util
		${LINEAR_MATH_LIB}
		${GTEST_LIB}
		${GMOCK_LIB}
		Threads::Threads
)
