
add_executable(AppNestedStructureTest
        NestedStructureTestModel.cpp
        NestedStructureSineWaves.cpp
        AppNestedTetrahedrons.cpp
)
target_link_directories(AppNestedStructureTest PUBLIC
        ${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(AppNestedStructureTest PRIVATE
        ntrt::tgcreator
        ntrt::controllers
        ntrt::core
)
