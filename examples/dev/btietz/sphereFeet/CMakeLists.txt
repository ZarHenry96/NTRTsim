find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppSuperSphereBall
    T6SphereModel.cpp
    AppSUPERSphereball.cpp
)
target_include_directories(AppSuperSphereBall PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppSuperSphereBall PRIVATE
        ntrt::core
        ntrt::tgcreator
        ${LINEAR_MATH_LIB}
)

