list(APPEND LIBS_TetrahedralComplex
		learningSpines
		ntrt::sensors
		ntrt::tgcreator
		ntrt::core
		ntrt::util
		ntrt::core::terrain
		ntrt::learning::Adapters
		ntrt::learning::Configuration
		ntrt::learning::AnnealEvolution
		ntrt::tgOpenGLSupport
)

add_library(TetrahedralComplex FlemonsSpineModelLearning.cpp)
target_link_directories(TetrahedralComplex PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(TetrahedralComplex PRIVATE ${LIBS_TetrahedralComplex})

add_executable(AppFlemonsSpineLearning
		FlemonsSpineModelLearning.cpp
        AppFlemonsSpineLearning.cpp
)
target_link_directories(AppFlemonsSpineLearning PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppFlemonsSpineLearning PRIVATE ${LIBS_TetrahedralComplex})
