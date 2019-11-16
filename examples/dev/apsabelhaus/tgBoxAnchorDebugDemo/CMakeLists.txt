
find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppTgBoxAnchorDebugDemo
        tgBoxAnchorDebugModel.cpp
        AppTgBoxAnchorDebugDemo.cpp
)
target_include_directories(AppTgBoxAnchorDebugDemo PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)
target_link_libraries(AppTgBoxAnchorDebugDemo PRIVATE
        ntrt::tgcreator
        ntrt::controllers
        ntrt::core
        ntrt::sensors
        ${LINEAR_MATH_LIB}
)

