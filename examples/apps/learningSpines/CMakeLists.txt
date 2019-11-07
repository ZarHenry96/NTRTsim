project(learningSpines)

add_library(${PROJECT_NAME}
        BaseSpineModelLearning.cpp
        BaseSpineCPGControl.cpp
        tgCPGActuatorControl.cpp
        tgCPGLogger.cpp
        tgSCASineControl.cpp
        KinematicSpineCPGControl.cpp
        tgCPGCableControl.cpp
        SpineFeedbackControl.cpp
)
target_link_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(${PROJECT_NAME} PRIVATE
        ntrt::sensors
        ntrt::tgcreator
        ntrt::core
        ntrt::util
        ntrt::core::terrain
        ntrt::learning::Adapters
        ntrt::learning::Configuration
        ntrt::learning::AnnealEvolution
        ntrt::helpers::FileHelpers
        ntrt::tgOpenGLSupport
)

add_subdirectory(OctahedralComplex)
add_subdirectory(ribDemo)
add_subdirectory(TetrahedralComplex)
add_subdirectory(TetraSpine)
