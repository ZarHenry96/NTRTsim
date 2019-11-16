find_library(LINEAR_MATH_LIB LinearMath)

add_library(BigDoxie BigDoxie.cpp)
target_include_directories(BigDoxie PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(BigDoxie PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)

add_executable(AppBigDoxie
		BigDoxie.cpp
		AppBigDoxie.cpp
)
target_include_directories(AppBigDoxie PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigDoxie PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)