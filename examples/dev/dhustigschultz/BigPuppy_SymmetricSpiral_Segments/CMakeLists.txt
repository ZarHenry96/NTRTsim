find_library(LINEAR_MATH_LIB LinearMath)

add_library(BigPuppySymmetricSpiralSegments BigPuppySymmetricSpiralSegments.cpp)
target_include_directories(BigPuppySymmetricSpiralSegments PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(BigPuppySymmetricSpiralSegments PRIVATE
		BaseQuadModelLearning
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)

add_executable(AppBigPuppySymmetricSpiralSegments
    BigPuppySymmetricSpiralSegments.cpp
    AppBigPuppySymmetricSpiralSegments.cpp
)
target_include_directories(AppBigPuppySymmetricSpiralSegments PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigPuppySymmetricSpiralSegments PRIVATE
		BaseQuadModelLearning
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)
