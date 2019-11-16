find_library(LINEAR_MATH_LIB LinearMath)
find_library(BULLET_COLL_LIB BulletCollision)

list(APPEND TESTS_INCS
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIRS}
)
list(APPEND TESTS_LIBS
        ntrt::tgcreator
        ntrt::core
        ${LINEAR_MATH_LIB}
)

add_executable(testTgStructure testTgStructure.cpp)
target_include_directories(testTgStructure PUBLIC ${TEST_INCS})
target_link_libraries(testTgStructure PRIVATE ${TESTS_LIBS})

add_executable(testTgBuildSpec testTgBuildSpec.cpp)
target_include_directories(testTgBuildSpec PUBLIC ${TEST_INCS})
target_link_libraries(testTgBuildSpec PRIVATE ${TESTS_LIBS})

add_executable(AppBuilderTest AppBuilderTest.cpp)
target_include_directories(AppBuilderTest PUBLIC ${TEST_INCS})
target_link_libraries(AppBuilderTest PRIVATE ${TESTS_LIBS})

add_executable(AppHilbert2D AppHilbert2D.cpp)
target_include_directories(AppHilbert2D PUBLIC ${TEST_INCS})
target_link_libraries(AppHilbert2D PRIVATE ${TESTS_LIBS})

add_executable(AppConnectorTest AppConnectorTest.cpp)
target_include_directories(AppConnectorTest PUBLIC ${TEST_INCS})
target_link_libraries(AppConnectorTest PRIVATE ${TESTS_LIBS})

add_executable(AppStructureTest AppStructureTest.cpp)
target_include_directories(AppStructureTest PUBLIC ${TEST_INCS})
target_link_libraries(AppStructureTest PRIVATE ${TESTS_LIBS})

add_executable(AppRBStringTest
        RBStringTest.cpp
        AppRBString.cpp
)
target_include_directories(AppRBStringTest PUBLIC ${TEST_INCS})
target_link_libraries(AppRBStringTest PRIVATE ${TESTS_LIBS})

add_executable(AppRotationTest AppRotationTest.cpp)
target_include_directories(AppRotationTest PUBLIC ${TEST_INCS})
target_link_libraries(AppRotationTest PRIVATE
        ${TESTS_LIBS}
        ${BULLET_COLL_LIB}
)