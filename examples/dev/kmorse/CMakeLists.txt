project(kmorse)

add_executable(AppSuperBall_Idaho
        T6Model.cpp
        AppSUPERball.cpp
)
target_link_directories(AppSuperBall_Idaho PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppSuperBall_Idaho PRIVATE ntrt::tgcreator ntrt::core)
