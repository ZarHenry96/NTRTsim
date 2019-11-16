find_library(LINEAR_MATH_LIB LinearMath)

add_library(BigPuppySymmetricArching BigPuppySymmetricArching.cpp)
target_include_directories(BigPuppySymmetricArching PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(BigPuppySymmetricArching PRIVATE
		BaseQuadModelLearning
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)

add_executable(AppBigPuppySymmetricArching
    BigPuppySymmetricArching.cpp
    AppBigPuppySymmetricArching.cpp
)
target_include_directories(AppBigPuppySymmetricArching PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigPuppySymmetricArching PRIVATE
		BaseQuadModelLearning
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)