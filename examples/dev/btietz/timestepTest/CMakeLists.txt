find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppPIDTest
		pidTestRig.cpp
		AppPIDTest.cpp
)
target_include_directories(AppPIDTest PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppPIDTest PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		ntrt::controllers
		${LINEAR_MATH_LIB}
)