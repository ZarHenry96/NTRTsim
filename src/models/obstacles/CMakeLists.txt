project(obstacles)

add_library(${PROJECT_NAME}
		tgBlockField.cpp
		tgStairs.cpp
		tgCraterDeep.cpp
		tgCraterShallow.cpp
		tgWall.cpp
)
add_library(ntrt::models::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
		ntrt::tgcreator
		ntrt::core
        ntrt::core::terrain
        ntrt::tgOpenGLSupport
		LinearMath
)

add_executable(AppObstacleTest
		tgBlockField.cpp
		tgStairs.cpp
		AppObstacleTest.cpp
)
target_include_directories(AppObstacleTest PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppObstacleTest PRIVATE
		ntrt::tgcreator
		ntrt::core
		ntrt::core::terrain
		ntrt::tgOpenGLSupport
		LinearMath
)
