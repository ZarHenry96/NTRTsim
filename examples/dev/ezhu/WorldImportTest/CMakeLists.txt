project(WorldImportTest)

find_library(LINEAR_MATH_LIB LinearMath)
add_executable(AppWorldImportTest
        RPLengthController.h
        RPLengthController_rand.cpp
        AppWorldImportTest.cpp
)
target_include_directories(AppWorldImportTest PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppWorldImportTest PRIVATE
		ntrt::core
		ntrt::controllers
		ntrt::models::TensegrityModel
		${LINEAR_MATH_LIB}
)