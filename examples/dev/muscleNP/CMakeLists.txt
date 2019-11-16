project(MuscleNP)

find_library(LINEAR_MATH_LIB LinearMath)
find_library(BULLET_DYN_LIB BulletDynamics)
find_library(BULLET_COLL_LIB BulletCollision)

add_library(${PROJECT_NAME}
        tgGhostInfo.cpp
        tgGhostModel.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
		${BULLET_DYN_LIB}
		${BULLET_COLL_LIB}
)