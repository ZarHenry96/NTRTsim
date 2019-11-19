
add_executable(AppBoxStructureTest
    NestedBoxTestModel.cpp
    AppNestedBoxTetrahedrons.cpp
)
target_include_directories(AppBoxStructureTest PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBoxStructureTest PRIVATE
        ntrt::core
        ntrt::tgcreator
)
