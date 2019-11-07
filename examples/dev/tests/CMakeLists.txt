list(APPEND LIBS_TESTS
        ntrt::tgcreator
        ntrt::util
        ntrt::sensors
        ntrt::core
        ntrt::core::terrain
        ntrt::tgOpenGLSupport
)

add_executable(testTgStructure
        testTgStructure.cpp
)
target_link_directories(testTgStructure PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(testTgStructure PRIVATE ${LIBS_TESTS})

add_executable(testTgBuildSpec
        testTgBuildSpec.cpp
)
target_link_directories(testTgBuildSpec PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(testTgBuildSpec PRIVATE ${LIBS_TESTS})

add_executable(AppBuilderTest
        AppBuilderTest.cpp
)
target_link_directories(AppBuilderTest PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppBuilderTest PRIVATE ${LIBS_TESTS})

add_executable(AppHilbert2D
        AppHilbert2D.cpp
)
target_link_directories(AppHilbert2D PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppHilbert2D PRIVATE ${LIBS_TESTS})

add_executable(AppConnectorTest
        AppConnectorTest.cpp
)
target_link_directories(AppConnectorTest PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppConnectorTest PRIVATE ${LIBS_TESTS})

add_executable(AppStructureTest
        AppStructureTest.cpp
)
target_link_directories(AppStructureTest PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppStructureTest PRIVATE ${LIBS_TESTS})

add_executable(AppRBStringTest
        RBStringTest.cpp
        AppRBString.cpp
)
target_link_directories(AppRBStringTest PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppRBStringTest PRIVATE ${LIBS_TESTS})

add_executable(AppRotationTest
        AppRotationTest.cpp
)
target_link_directories(AppRotationTest PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppRotationTest PRIVATE ${LIBS_TESTS})
