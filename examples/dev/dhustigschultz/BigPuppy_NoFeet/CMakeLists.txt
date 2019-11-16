find_library(LINEAR_MATH_LIB LinearMath)

add_library(BigPuppyNoFeet BigPuppyNoFeet.cpp)
target_include_directories(BigPuppyNoFeet PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
		)
target_link_libraries(BigPuppyNoFeet PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)

add_executable(AppBigPuppyNoFeet
    BigPuppyNoFeet.cpp
    AppBigPuppyNoFeet.cpp
)
target_include_directories(AppBigPuppyNoFeet PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigPuppyNoFeet PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)