project(nestedStructureTest)

add_executable(AppNestedStructureTest
        NestedStructureTestModel.cpp
        NestedStructureSineWaves.cpp
        AppNestedTetrahedrons.cpp
)
target_include_directories(AppNestedStructureTest PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
target_link_libraries(AppNestedStructureTest PRIVATE
        ntrt::tgcreator
        ntrt::controllers
        ntrt::core
)
