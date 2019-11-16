add_executable(AppNestedStructureDepthTest AppNestedStructureDepthTest.cpp)
target_include_directories(AppNestedStructureDepthTest PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)
target_link_libraries(AppNestedStructureDepthTest PRIVATE
        ntrt::tgcreator
)

add_executable(AppStructuresOnStack AppStructuresOnStack.cpp)
target_include_directories(AppStructuresOnStack PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)
target_link_libraries(AppStructuresOnStack PRIVATE
        ntrt::tgcreator
)


