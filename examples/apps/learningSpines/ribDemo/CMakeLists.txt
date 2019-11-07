add_executable(AppRibModelLearning
        RibModel.cpp
        AppRibModelLearning.cpp
)

target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(${PROJECT_NAME} PRIVATE
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