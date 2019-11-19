#Project name must match folder name for includes to work!
project(core)

add_subdirectory(terrain)

find_library(LINEAR_MATH_LIB LinearMath)
find_library(BULLET_COLLISION_LIB BulletCollision)
find_library(BULLET_DYN_LIB BulletDynamics)
find_library(BULLET_SOTF_BO_LIB BulletSoftBody)

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
        $<INSTALL_INTERFACE:include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
        ntrt::terrain
        ntrt::tgOpenGLSupport
        ${LINEAR_MATH_LIB}
        ${BULLET_DYN_LIB}
        ${BULLET_COLLISION_LIB}
        ${BULLET_SOTF_BO_LIB}

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