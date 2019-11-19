find_library(LINEAR_MATH_LIB LinearMath)

list(APPEND LINE_INS_LIB
		ntrt::core
		ntrt::tgcreator
		ntrt::util
		ntrt::sensors
		ntrt::terrain
		ntrt::tgOpenGLSupport
		${LINEAR_MATH_LIB}
)

add_executable(AppCordeTest
    CordeModel.cpp
    AppCordeTest.cpp
)
target_include_directories(AppCordeTest PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppCordeTest PRIVATE ${LINE_INS_LIB})

add_executable(AppLineInsertionCheck AppLineInsertionCheck.cpp)
target_include_directories(AppLineInsertionCheck PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppLineInsertionCheck PRIVATE ${LINE_INS_LIB})