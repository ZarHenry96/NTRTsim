find_library(LINEAR_MATH_LIB LinearMath)

add_library(BigPuppySpineOnly BigPuppySpineOnly.cpp)
target_include_directories(BigPuppySpineOnly PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(BigPuppySpineOnly PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)

add_executable(AppBigPuppySpineOnly
    BigPuppySpineOnly.cpp
    AppBigPuppySpineOnly.cpp
) 
target_include_directories(AppBigPuppySpineOnly PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigPuppySpineOnly PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)