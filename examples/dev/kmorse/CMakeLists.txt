project(kmorse)

find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppSuperBall_Idaho
        T6Model.cpp
        AppSUPERball.cpp
)
target_include_directories(AppSuperBall_Idaho PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppSuperBall_Idaho PRIVATE
        ntrt::core
        ntrt::tgcreator
        ntrt::sensors
        ${LINEAR_MATH_LIB}
)