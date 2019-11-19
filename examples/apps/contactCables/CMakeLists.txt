project(contactCables)

find_library(LINEAR_MATH_LIB LinearMath)
find_library(BULLET_DYNAMICS_LIB BulletDynamics)

list(APPEND LIBS_ContactCables
        ntrt::models::obstacles
        tetraSpineLearningSine
        tetraSpineHardware
        learningSpines
        ntrt::sensors
        ntrt::tgcreator
        ntrt::core
        ntrt::terrain
        ntrt::tgOpenGLSupport
        ${LINEAR_MATH_LIB}
        ${BULLET_DYNAMICS_LIB}
)

add_library(tetraCollisionsCC
        TetraSpineCollisions.cpp
        colSpineSine.cpp
)
target_include_directories(tetraCollisionsCC PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
)
target_link_libraries(tetraCollisionsCC PRIVATE ${LIBS_ContactCables})

add_library(ContactCableCons ContactCableDemo.cpp)
target_include_directories(ContactCableCons PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
)
target_link_libraries(ContactCableCons PRIVATE ${LIBS_ContactCables})

add_executable(AppTetraSpineCol
        TetraSpineCollisions.cpp
        colSpineSine.cpp
        AppTetraSpineCol.cpp
)
target_include_directories(AppTetraSpineCol PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
)
target_link_libraries(AppTetraSpineCol PRIVATE ${LIBS_ContactCables})
			
add_executable(AppContactCables
        ContactCableDemo.cpp
        AppContactCables.cpp
)
target_include_directories(AppContactCables PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
)
target_link_libraries(AppContactCables PRIVATE ${LIBS_ContactCables})