find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppBigPuppy
    BigPuppy.cpp
    AppBigPuppy.cpp
) 
target_include_directories(AppBigPuppy PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigPuppy PRIVATE
        ntrt::core
        ntrt::tgcreator
        ${LINEAR_MATH_LIB}
)