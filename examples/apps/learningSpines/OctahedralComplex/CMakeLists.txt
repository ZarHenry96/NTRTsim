list(APPEND LIBS_OctahedralComplex
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

add_library(octahedralComplex FlemonsSpineModelLearningCL.cpp)
target_link_directories(octahedralComplex PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(octahedralComplex PRIVATE ${LIBS_OctahedralComplex})

add_executable(AppFlemonsSpineLearningCL
        FlemonsSpineModelLearningCL.cpp
        AppFlemonsSpineLearningCL.cpp
)
target_link_directories(AppFlemonsSpineLearningCL PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppFlemonsSpineLearningCL PRIVATE ${LIBS_OctahedralComplex})

