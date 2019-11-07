
add_executable(AppTwoSpringsSuperBall
        T6Model.cpp
#    T6RestLengthController.cpp
        AppSUPERball.cpp
)
target_link_directories(AppTwoSpringsSuperBall PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppTwoSpringsSuperBall PRIVATE ntrt::tgcreator ntrt::core)
