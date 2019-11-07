project(tgcreator)

add_library(${PROJECT_NAME}
        tgNodes.cpp
        tgRigidInfo.cpp
        tgRodInfo.cpp
        tgBoxInfo.cpp
        tgBoxMoreAnchorsInfo.cpp
        tgSphereInfo.cpp
        tgStructure.cpp
        tgBuildSpec.cpp
        tgStructureInfo.cpp
        tgConnectorInfo.cpp
        tgCompoundRigidInfo.cpp
        tgPair.cpp
        tgBasicActuatorInfo.cpp
        tgCompressionSpringActuatorInfo.cpp
        tgUnidirComprSprActuatorInfo.cpp
        tgKinematicActuatorInfo.cpp
        tgKinematicContactCableInfo.cpp
        tgBasicContactCableInfo.cpp
        tgRigidAutoCompound.cpp
        tgUtil.cpp
)
add_library(ntrt::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${Boost_INCLUDE_DIRS}
        ${BULLET_INCLUDE_DIRS}
)
# Needed to add boost's random library for tgRigidAutoCompound's hashing function
target_link_libraries(${PROJECT_NAME} PRIVATE
        ntrt::core
        ntrt::tgOpenGLSupport
        boost_random
        LinearMath
        BulletCollision
        BulletDynamics
        BulletSoftBody
)