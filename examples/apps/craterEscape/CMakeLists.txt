project(appEscape)

add_executable(AppEscape
        EscapeModel.cpp
        EscapeController.cpp
        AppEscape.cpp
)

target_link_directories(AppEscape PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
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
        ntrt::core::terrain
        ntrt::tgOpenGLSupport
)
