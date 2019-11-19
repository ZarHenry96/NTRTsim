find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppSimpleMuscleNP
        simpleMuscleNP.cpp
        AppsimpleMuscleNP.cpp
)
target_include_directories(AppSimpleMuscleNP PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppSimpleMuscleNP PRIVATE
        ntrt::core
        ntrt::tgcreator
        ${LINEAR_MATH_LIB}
)