find_library(LINEAR_MATH_LIB LinearMath)


add_executable(App6Bar
        RPLengthController.h
        RPLengthController_rand.cpp
        App6Bar.cpp
)
target_include_directories(App6Bar PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(App6Bar PRIVATE
		ntrt::core
		ntrt::tgcreator
		ntrt::models::TensegrityModel
		${LINEAR_MATH_LIB}
)
