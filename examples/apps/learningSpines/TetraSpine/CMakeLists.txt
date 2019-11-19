
find_library(JSONCPP_LIB jsoncpp)
find_library(LINEAR_MATH_LIB LinearMath)

list(APPEND LIBS_TetraSpineLearning
        learningSpines
        ntrt::sensors
        ntrt::tgcreator
        ntrt::controllers
        ntrt::core
        ntrt::util
        ntrt::terrain
        ntrt::learning::Adapters
        ntrt::learning::Configuration
        ntrt::learning::AnnealEvolution
        ntrt::tgOpenGLSupport
        ntrt::helpers::FileHelpers
        ${LINEAR_MATH_LIB}
        ${JSONCPP_LIB}
)

add_executable(AppTetraSpineLearning
        TetraSpineLearningModel.cpp
        TetraSpineCPGControl.cpp
        AppTetraSpineLearning.cpp
)
target_include_directories(AppTetraSpineLearning PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
        ${Boost_INCLUDE_DIRS}
)
target_link_libraries(AppTetraSpineLearning PRIVATE ${LIBS_TetraSpineLearning})

add_executable(AppTetraSpineSerial
        SerializedSineWaves.cpp
        TetraSpineLearningModel.cpp
        AppTetraSpineSerial.cpp
)
target_include_directories(AppTetraSpineSerial PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
        ${Boost_INCLUDE_DIRS}
)
target_link_libraries(AppTetraSpineSerial PRIVATE ${LIBS_TetraSpineLearning})

configure_file("controlVars.json" "controlVars.json" COPYONLY)

