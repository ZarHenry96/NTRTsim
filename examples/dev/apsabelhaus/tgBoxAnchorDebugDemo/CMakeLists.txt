
add_executable(AppTgBoxAnchorDebugDemo
        tgBoxAnchorDebugModel.cpp
        AppTgBoxAnchorDebugDemo.cpp
)
target_link_directories(AppTgBoxAnchorDebugDemo PUBLIC
        ${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(AppTgBoxAnchorDebugDemo PRIVATE
        ntrt::tgcreator
        ntrt::controllers
        ntrt::core
        ntrt::sensors
)

