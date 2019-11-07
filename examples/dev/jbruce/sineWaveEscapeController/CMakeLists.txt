
add_executable(AppSineWaveEscapeController
        T6Model.cpp
#    Escape_T6Controller.cpp
        AppSUPERball.cpp
)
target_link_directories(AppSineWaveEscapeController PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppSineWaveEscapeController PRIVATE ntrt::tgcreator ntrt::core)