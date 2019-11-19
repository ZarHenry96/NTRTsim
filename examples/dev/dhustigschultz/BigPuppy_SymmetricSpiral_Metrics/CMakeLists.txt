find_library(LINEAR_MATH_LIB LinearMath)

add_library(BigPuppySymmetricSpiralMetrics BigPuppySymmetricSpiralMetrics.cpp)
target_include_directories(BigPuppySymmetricSpiralMetrics PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(BigPuppySymmetricSpiralMetrics PRIVATE
		BaseQuadModelLearning
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)

add_executable(AppBigPuppySymmetricSpiralMetrics
    BigPuppySymmetricSpiralMetrics.cpp
    AppBigPuppySymmetricSpiralMetrics.cpp
)
target_include_directories(AppBigPuppySymmetricSpiralMetrics PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigPuppySymmetricSpiralMetrics PRIVATE
		BaseQuadModelLearning
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)
