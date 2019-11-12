project(tgcreator)

find_library(BOOST_RANDOM_LIB boost_random)
find_library(LINEAR_MATH_LIB LinearMath)
find_library(BULLET_COLLISION_LIB BulletCollision)
find_library(BULLET_DYN_LIB BulletDynamics)
find_library(BULLET_SOFT_BODY_LIB BulletSoftBody)

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
        ${BOOST_RANDOM_LIB}
        ${LINEAR_MATH_LIB}
        ${BULLET_COLLISION_LIB}
        ${BULLET_DYN_LIB}
        ${BULLET_SOFT_BODY_LIB}
)