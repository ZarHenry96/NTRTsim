project(MuscleNP_test)

find_library(LINEAR_MATH_LIB LinearMath)
find_library(GTEST_LIB gtest)
find_library(GMOCK_LIB gmock)

add_executable(${PROJECT_NAME} MuscleNP_test.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${GTEST_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME}
		${LINEAR_MATH_LIB}
		${GTEST_LIB}
		${GMOCK_LIB}
		Threads::Threads
		ntrt::core
		ntrt::core::terrain
		ntrt::tgcreator
		ContactCableCons
)
