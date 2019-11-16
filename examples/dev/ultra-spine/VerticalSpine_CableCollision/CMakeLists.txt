add_executable(AppVerticalSpineCableCollision
        VerticalSpineModelCableCollision.cpp
        AppVerticalSpineCableCollision.cpp
)
target_include_directories(AppVerticalSpineCableCollision PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppVerticalSpineCableCollision PRIVATE
        learningSpines
        ntrt::core
        ntrt::tgcreator
)