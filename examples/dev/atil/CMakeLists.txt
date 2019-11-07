
add_executable(AppSuperBallLearning
        SuperBallModel.cpp
        SuperBallLearningController.cpp
        AppSUPERball.cpp
        heightSensor.cpp
)
target_link_directories(AppSuperBallLearning PUBLIC
        ${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(AppSuperBallLearning PRIVATE
        ntrt::tgcreator
        ntrt::core
        ntrt::learning::Adapters
)
