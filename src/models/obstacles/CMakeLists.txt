project(obstacles)

find_library(LINEAR_MATH_LIB LinearMath)
find_library(BULLET_COLLISION_LIB BulletCollision)
find_library(BULLET_DYN_LIB BulletDynamics)

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
		$<INSTALL_INTERFACE:include>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
		ntrt::tgcreator
		ntrt::core
		ntrt::terrain
		ntrt::tgOpenGLSupport
		${LINEAR_MATH_LIB}
		${BULLET_COLLISION_LIB}
		${BULLET_DYN_LIB}
)

add_executable(AppObstacleTest
		tgBlockField.cpp
		tgStairs.cpp
		AppObstacleTest.cpp
)
target_include_directories(AppObstacleTest PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
		${BULLET_INCLUDE_DIRS}
)

target_link_libraries(AppObstacleTest PRIVATE
		ntrt::tgcreator
		ntrt::core
		ntrt::terrain
		ntrt::tgOpenGLSupport
		${LINEAR_MATH_LIB}
		${BULLET_COLLISION_LIB}
		${BULLET_DYN_LIB}
)

# library installation
install(TARGETS ${PROJECT_NAME}
		EXPORT ${CMAKE_PROJECT_NAME}
		LIBRARY DESTINATION ${LIB_INSTALL_DIR}
		ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
		RUNTIME DESTINATION ${BIN_INSTALL_DIR}
		INCLUDES DESTINATION ${INCLUDE_INSTALL_DIR}
)
list(APPEND EXPORT_TARGETS ${PROJECT_NAME})