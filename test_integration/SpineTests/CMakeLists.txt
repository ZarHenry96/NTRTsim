project(WorldConf_Spines_test)

find_library(GTEST_LIB gtest)
find_library(GMOCK_LIB gmock)

add_executable(${PROJECT_NAME} WorldConf_Spines_test.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${GTEST_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME}
		${GTEST_LIB}
		${GMOCK_LIB}
		Threads::Threads
		ntrt::core
		ntrt::helpers::FileHelpers
		learningSpines
		TetrahedralComplex
)
