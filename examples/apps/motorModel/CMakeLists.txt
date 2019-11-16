find_library(LINEAR_MATH_LIB LinearMath)

list(APPEND LIBS_TimestepTest
		ntrt::tgcreator
		ntrt::util
		ntrt::sensors
		ntrt::controllers
		ntrt::core
		ntrt::core::terrain
		ntrt::tgOpenGLSupport
		${LINEAR_MATH_LIB}
)

add_library(TimestepTest tsTestRig.cpp tsTestRig.h)
target_include_directories(TimestepTest PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)
target_link_libraries(TimestepTest PRIVATE ${LIBS_TimestepTest})

add_executable(AppTSTest
        tsTestRig.cpp
		tsTestRig.h
        AppTimestepTest.cpp
)
target_include_directories(AppTSTest PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)
target_link_libraries(AppTSTest PRIVATE ${LIBS_TimestepTest})
