find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppBigPuppy_2
    BigPuppy.cpp
    AppBigPuppy.cpp
) 
target_include_directories(AppBigPuppy_2 PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigPuppy_2 PRIVATE
        ntrt::core
        ntrt::tgcreator
        ${LINEAR_MATH_LIB}
)