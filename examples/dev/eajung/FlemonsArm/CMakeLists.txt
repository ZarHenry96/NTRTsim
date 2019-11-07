
add_executable(FlemonsArm
        FlemonsArm.cpp
        AppFlemonsArm.cpp
) 
target_link_directories(FlemonsArm PUBLIC
        ${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(FlemonsArm PRIVATE
        ntrt::tgcreator
        ntrt::util
        ntrt::sensors
        ntrt::core
        ntrt::core::terrain
        ntrt::tgOpenGLSupport
)
