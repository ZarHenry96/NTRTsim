project(appEscape)

find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppEscape
        EscapeModel.cpp
        EscapeController.cpp
        AppEscape.cpp
)
target_include_directories(AppEscape PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
)
target_link_libraries(AppEscape PRIVATE
        ntrt::models::obstacles
        ntrt::tgcreator
        ntrt::util
        ntrt::sensors
        ntrt::learning::Adapters
        ntrt::learning::Configuration
        ntrt::learning::AnnealEvolution
        ntrt::helpers::FileHelpers
        ntrt::core
        ntrt::terrain
        ntrt::tgOpenGLSupport
        ${LINEAR_MATH_LIB}
)
