project(test_tgcreator)

find_library(LINEAR_MATH_LIB LinearMath)
find_library(GTEST_LIB gtest)
find_library(GMOCK_LIB gmock)

add_executable(tgUtil_test tgUtil_test.cpp)
target_include_directories(tgUtil_test PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIR}
        ${GTEST_INCLUDE_DIRS}
)
target_link_libraries(tgUtil_test PRIVATE
        ntrt::core
        ntrt::tgcreator
        ${LINEAR_MATH_LIB}
        ${GTEST_LIB}
        ${GMOCK_LIB}
        Threads::Threads
)
