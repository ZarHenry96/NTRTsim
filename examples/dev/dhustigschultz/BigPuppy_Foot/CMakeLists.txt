find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppBigFoot
    BigFoot.cpp
    AppBigFoot.cpp
)
target_include_directories(AppBigFoot PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigFoot PRIVATE
        ntrt::core
        ntrt::tgcreator
        ${LINEAR_MATH_LIB}
)