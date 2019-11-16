find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppTwoSpringsSuperBall
        T6Model.cpp
#    T6RestLengthController.cpp
        AppSUPERball.cpp
)
target_include_directories(AppTwoSpringsSuperBall PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppTwoSpringsSuperBall PRIVATE
        ntrt::core
        ntrt::tgcreator
        ${LINEAR_MATH_LIB}
)