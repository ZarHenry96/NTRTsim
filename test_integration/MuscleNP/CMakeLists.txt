project(MuscleNP_test)

add_executable(${PROJECT_NAME} MuscleNP_test.cpp)
target_link_directories(${PROJECT_NAME} PUBLIC
		${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(${PROJECT_NAME}
		GTest
		pthread
		ntrt::core
		ntrt::core::terrain
		ntrt::tgcreator
		${CMAKE_BINARY_DIR}/examples/apps/contactCables/libContactCableCons.so
)
