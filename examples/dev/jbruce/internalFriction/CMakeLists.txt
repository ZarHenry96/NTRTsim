
add_executable(AppInternalFiction
        T6Model.cpp
#    T6RestLengthController.cpp
        AppSUPERball.cpp
)
target_link_directories(AppInternalFiction PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppInternalFiction PRIVATE ntrt::tgcreator ntrt::core)
