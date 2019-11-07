project(contactCables)

list(APPEND LIBS_ContactCables
        ntrt::models::obstacles
        tetraSpineLearningSine
        tetraSpineHardware
        learningSpines
        ntrt::sensors
        ntrt::tgcreator
        ntrt::core
        ntrt::core::terrain
        ntrt::tgOpenGLSupport
)


add_library(tetraCollisions
        TetraSpineCollisions.cpp
        colSpineSine.cpp
)
target_link_directories(tetraCollisions PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(tetraCollisions PRIVATE ${LIBS_ContactCables})

add_library(ContactCableCons ContactCableDemo.cpp)
target_link_directories(ContactCableCons PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(ContactCableCons PRIVATE ${LIBS_ContactCables})

add_executable(AppTetraSpineCol
        TetraSpineCollisions.cpp
        colSpineSine.cpp
        AppTetraSpineCol.cpp
)
target_link_directories(AppTetraSpineCol PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppTetraSpineCol PRIVATE ${LIBS_ContactCables})
			
add_executable(AppContactCables
        ContactCableDemo.cpp
        AppContactCables.cpp
)
target_link_directories(AppContactCables PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppContactCables PRIVATE ${LIBS_ContactCables})