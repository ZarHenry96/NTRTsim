find_library(LINEAR_MATH_LIB LinearMath)

add_library(BigDoxieNoFeet BigDoxieNoFeet.cpp)
target_include_directories(BigDoxieNoFeet PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(BigDoxieNoFeet PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)

add_executable(AppBigDoxieNoFeet
		BigDoxieNoFeet.cpp
		AppBigDoxieNoFeet.cpp
)
target_include_directories(AppBigDoxieNoFeet PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigDoxieNoFeet PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)