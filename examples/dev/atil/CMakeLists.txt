find_library(LINEAR_MATH_LIB LinearMath)
find_library(BULLET_DYN_LIB BulletDynamics)

add_executable(AppSuperBallLearning
        SuperBallModel.cpp
        SuperBallLearningController.cpp
        AppSUPERball.cpp
        heightSensor.cpp
)
target_include_directories(AppSuperBallLearning PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppSuperBallLearning PRIVATE
        ntrt::tgcreator
        ntrt::core
        ntrt::learning::Adapters
        ${LINEAR_MATH_LIB}
        ${BULLET_DYN_LIB}
)

configure_file("Config.ini" "Config.ini" COPYONLY)