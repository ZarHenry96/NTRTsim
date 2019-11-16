
find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppRibModelLearning
        RibModel.cpp
        AppRibModelLearning.cpp
)

target_include_directories(AppRibModelLearning PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
        ${Boost_INCLUDE_DIRS}
)
target_link_libraries(AppRibModelLearning PRIVATE
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
        ${LINEAR_MATH_LIB}
)