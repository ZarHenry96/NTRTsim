find_library(LINEAR_MATH_LIB LinearMath)

add_executable(FlemonsArm
        FlemonsArm.cpp
        AppFlemonsArm.cpp
) 
target_include_directories(FlemonsArm PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(FlemonsArm PRIVATE
        ntrt::core
        ntrt::tgcreator
        ${LINEAR_MATH_LIB}
)