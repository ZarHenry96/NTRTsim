
#add_executable(AppTgCreatorTest AppTgCreatorTest.cpp)
#target_link_directories(AppTgCreatorTest PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
#target_link_libraries(AppTgCreatorTest PRIVATE ntrt::tgcreator ntrt::core)

add_executable(AppNestedStructureDepthTest AppNestedStructureDepthTest.cpp)
target_link_directories(AppNestedStructureDepthTest PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppNestedStructureDepthTest PRIVATE ntrt::tgcreator ntrt::core)

add_executable(AppStructuresOnStack AppStructuresOnStack.cpp)
target_link_directories(AppStructuresOnStack PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppStructuresOnStack PRIVATE ntrt::tgcreator ntrt::core)
