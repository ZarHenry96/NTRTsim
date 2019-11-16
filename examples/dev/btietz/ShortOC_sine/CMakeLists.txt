add_executable(AppOctaCL_sine
    AppOctaCL_sine.cpp
    OctaCLSine.cpp
)
target_include_directories(AppOctaCL_sine PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${Boost_INCLUDE_DIRS}
)
target_link_libraries(AppOctaCL_sine PRIVATE
		octahedralComplex
		tetraSpineLearningSine
		learningSpines
		ntrt::core
		ntrt::controllers
		ntrt::learning
)
