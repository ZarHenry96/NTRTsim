#Project name must match folder name for includes to work!
project(core)

add_subdirectory(terrain)

add_library(${PROJECT_NAME}
        tgWorldBulletPhysicsImpl.cpp
        tgBulletSpringCableAnchor.cpp
        tgSpringCable.cpp
        tgBulletSpringCable.cpp
        tgBulletContactSpringCable.cpp
        tgBulletCompressionSpring.cpp
        tgBulletUnidirComprSpr.cpp
        tgModel.cpp
        tgSpringCableActuator.cpp
        tgBasicActuator.cpp
        tgKinematicActuator.cpp
        tgCompressionSpringActuator.cpp
        tgUnidirComprSprActuator.cpp
        tgWorld.cpp
        tgSimulation.cpp
        tgSenseable.cpp
        tgBulletRenderer.cpp
        tgSimView.cpp
        tgSimViewGraphics.cpp
        tgBulletUtil.cpp
        tgBaseRigid.cpp
        tgRod.cpp
        tgBox.cpp
        tgBoxMoreAnchors.cpp
        tgSphere.cpp
        abstractMarker.cpp
)
add_library(ntrt::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
        ntrt::${PROJECT_NAME}::terrain
        ntrt::tgOpenGLSupport
        LinearMath
        BulletDynamics
        BulletCollision
        BulletSoftBody
)
