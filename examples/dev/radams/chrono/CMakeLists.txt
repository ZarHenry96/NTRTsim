
add_executable(AppChronoTest chronoTest.cpp)
target_link_directories(AppChronoTest PUBLIC
        ${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(AppChronoTest PRIVATE
        boost_system
        boost_chrono
)