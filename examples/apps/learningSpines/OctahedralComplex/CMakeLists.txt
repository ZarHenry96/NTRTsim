project(octahedralComplex)

find_library(LINEAR_MATH_LIB LinearMath)

list(APPEND LIBS_OctahedralComplex
        learningSpines
        ntrt::sensors
        ntrt::tgcreator
        ntrt::core
        ntrt::util
        ntrt::terrain
        ntrt::learning::Adapters
        ntrt::learning::Configuration
        ntrt::learning::AnnealEvolution
        ntrt::tgOpenGLSupport
        ${LINEAR_MATH_LIB}
)

add_library(octahedralComplex FlemonsSpineModelLearningCL.cpp)
target_include_directories(octahedralComplex PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
        ${Boost_INCLUDE_DIRS}
)
target_link_libraries(octahedralComplex PRIVATE ${LIBS_OctahedralComplex})

add_executable(AppFlemonsSpineLearningCL
        FlemonsSpineModelLearningCL.cpp
        AppFlemonsSpineLearningCL.cpp
)
target_include_directories(AppFlemonsSpineLearningCL PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
        ${Boost_INCLUDE_DIRS}
)
target_link_libraries(AppFlemonsSpineLearningCL PRIVATE ${LIBS_OctahedralComplex})

