project(terrain)

find_library(LINEAR_MATH_LIB LinearMath)
find_library(BULLET_COLLISION_LIB BulletCollision)

add_library(${PROJECT_NAME}
        tgBulletGround.cpp
        tgBoxGround.cpp
        tgEmptyGround.cpp
        tgPlaneGround.cpp
        tgCraterGround.cpp
        tgHillyGround.cpp
)
add_library(ntrt::core::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
        ${LINEAR_MATH_LIB}
        ${BULLET_COLLISION_LIB}
)