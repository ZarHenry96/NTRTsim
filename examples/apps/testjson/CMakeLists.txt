
add_executable(TestJSON testjson.cpp)
target_link_directories(TestJSON PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(TestJSON PRIVATE jsonpp ntrt::helpers::FileHelpers)
configure_file(data.txt data.txt COPYONLY)
