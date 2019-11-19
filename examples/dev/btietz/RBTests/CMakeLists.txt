find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppContactModelTest AppContactModelTest.cpp)
target_include_directories(AppContactModelTest PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppContactModelTest PRIVATE
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)