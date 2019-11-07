project(MotorTimestep_test)
             
add_executable(${PROJECT_NAME} MotorTimestep_test.cpp)
target_link_directories(${PROJECT_NAME} PUBLIC
		${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(${PROJECT_NAME}
		pthread
		ntrt::tgOpenGLSupport
		ntrt::core
		${CMAKE_BINARY_DIR}/examples/motorModel/libTimestepTest.so
)
