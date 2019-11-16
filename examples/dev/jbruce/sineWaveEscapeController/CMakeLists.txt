find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppSineWaveEscapeController
        T6Model.cpp
        Escape_T6Controller.cpp
        AppSUPERball.cpp
)
target_include_directories(AppSineWaveEscapeController PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppSineWaveEscapeController PRIVATE
        ntrt::core
        ntrt::tgcreator
        ntrt::learning
        ${LINEAR_MATH_LIB}
)