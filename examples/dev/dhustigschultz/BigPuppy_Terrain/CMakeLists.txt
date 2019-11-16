find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppBigPuppy_Terrain
    BigPuppy.cpp
    AppBigPuppy.cpp
)
target_include_directories(AppBigPuppy_Terrain PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigPuppy_Terrain PRIVATE
        ntrt::core
        ntrt::tgcreator
        ntrt::models::obstacles
        ${LINEAR_MATH_LIB}
)