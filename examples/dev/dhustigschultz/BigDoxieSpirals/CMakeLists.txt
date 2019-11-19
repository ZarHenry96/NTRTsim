find_library(LINEAR_MATH_LIB LinearMath)

add_library(BigDoxieSpirals BigDoxieSpirals.cpp)
target_include_directories(BigDoxieSpirals PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(BigDoxieSpirals PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)

add_executable(AppBigDoxieSpirals
		BigDoxieSpirals.cpp
		AppBigDoxieSpirals.cpp
)
target_include_directories(AppBigDoxieSpirals PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigDoxieSpirals PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)