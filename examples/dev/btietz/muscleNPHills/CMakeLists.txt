find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppHillyMuscleNP
    hillyMuscleNP.cpp
    AppHillyMuscleNP.cpp
)
target_include_directories(AppHillyMuscleNP PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppHillyMuscleNP PRIVATE
        ntrt::core
        ntrt::tgcreator
        ${LINEAR_MATH_LIB}
)