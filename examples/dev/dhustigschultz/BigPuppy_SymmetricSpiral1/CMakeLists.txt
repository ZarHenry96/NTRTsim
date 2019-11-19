find_library(LINEAR_MATH_LIB LinearMath)

add_library(BigPuppySymmetricSpiral1 BigPuppySymmetricSpiral1.cpp)
target_include_directories(BigPuppySymmetricSpiral1 PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(BigPuppySymmetricSpiral1 PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)

add_executable(AppBigPuppySymmetricSpiral1
		BigPuppySymmetricSpiral1.cpp
		AppBigPuppySymmetricSpiral1.cpp
)
target_include_directories(AppBigPuppySymmetricSpiral1 PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigPuppySymmetricSpiral1 PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)
