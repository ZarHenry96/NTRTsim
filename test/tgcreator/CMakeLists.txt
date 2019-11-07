project(test_tgcreator)

add_executable(tgUtil_test tgUtil_test.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIR}
        ${GTEST_INCLUDE_DIRS}
)
target_link_libraries(tgUtil_test PRIVATE
        ntrt::core
        ntrt::tgcreator
        GTest
        LinearMath
)
