find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppSpineKinematicsTest
        SpineKinematicsTestController.cpp
        AppSpineKinematicsTest.cpp
)
target_include_directories(AppSpineKinematicsTest PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppSpineKinematicsTest PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		ntrt::sensors
		ntrt::helpers::FileHelpers
		ntrt::models::TensegrityModel
		${LINEAR_MATH_LIB}
)

