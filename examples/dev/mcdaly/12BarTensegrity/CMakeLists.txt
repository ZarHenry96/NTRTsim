find_library(LINEAR_MATH_LIB LinearMath)

add_executable(App12Bar
        App12Bar.cpp
        RPLengthController.h
        RPLengthController_rand.cpp
)
target_include_directories(App12Bar PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(App12Bar PRIVATE
		ntrt::core
		ntrt::tgcreator
		ntrt::models::TensegrityModel
		${LINEAR_MATH_LIB}
)
