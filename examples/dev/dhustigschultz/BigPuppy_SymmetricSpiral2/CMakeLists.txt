find_library(LINEAR_MATH_LIB LinearMath)

add_library(BigPuppySymmetricSpiral2 BigPuppySymmetricSpiral2.cpp)
target_include_directories(BigPuppySymmetricSpiral2 PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(BigPuppySymmetricSpiral2 PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)

add_executable(AppBigPuppySymmetricSpiral2
		BigPuppySymmetricSpiral2.cpp
		AppBigPuppySymmetricSpiral2.cpp
)
target_include_directories(AppBigPuppySymmetricSpiral2 PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigPuppySymmetricSpiral2 PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)
