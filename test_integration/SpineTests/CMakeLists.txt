project(WorldConf_Spines_test)

add_executable(${PROJECT_NAME} WorldConf_Spines_test.cpp)

target_link_directories(${PROJECT_NAME} PUBLIC
		${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(${PROJECT_NAME}
		GTest
		pthread
		ntrt::core
		ntrt::core::terrain
		ntrt::tgcreator
		ntrt::helpers::FileHelpers
		${CMAKE_BINARY_DIR}/examples/apps/learningSpines/liblearningSpines.so
		${CMAKE_BINARY_DIR}/examples/apps/learningSpines/TetrahedralComplex/libTetrahedralComplex.so
)
