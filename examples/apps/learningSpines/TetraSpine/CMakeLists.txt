list(APPEND LIBS_TetraSpineLearning
        learningSpines
        ntrt::sensors
        ntrt::tgcreator
        ntrt::controllers
        ntrt::core
        ntrt::util
        ntrt::core::terrain
        ntrt::learning::Adapters
        ntrt::learning::Configuration
        ntrt::learning::AnnealEvolution
        ntrt::tgOpenGLSupport
        ntrt::helpers::FileHelpers
        jsoncpp
)

add_executable(AppTetraSpineLearning
        TetraSpineLearningModel.cpp
        TetraSpineCPGControl.cpp
        AppTetraSpineLearning.cpp

)
target_link_directories(AppTetraSpineLearning PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppTetraSpineLearning PRIVATE ${LIBS_TetraSpineLearning})

add_executable(AppTetraSpineSerial
        SerializedSineWaves.cpp
        TetraSpineLearningModel.cpp
        AppTetraSpineSerial.cpp
)
target_link_directories(AppTetraSpineSerial PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppTetraSpineSerial PRIVATE ${LIBS_TetraSpineLearning})

configure_file("controlVars.json" "controlVars.json" COPYONLY)

