project(TensegrityModel)

add_library(TensegrityModel SHARED
        TensegrityModel.cpp
        TensegrityModelController.cpp
)
add_library(ntrt::models::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIRS}
        ${YAML_CPP_INCLUDE_DIR}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
        ntrt::core
        ntrt::tgcreator
        ntrt::util
        ntrt::sensors
        ntrt::core::terrain
        ntrt::tgOpenGLSupport
        yaml-cpp
        LinearMath
)

add_executable(BuildModel
        TensegrityModel.cpp
        BuildTensegrityModel.cpp
        TensegrityModelController.cpp
)
target_include_directories(BuildModel PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${BULLET_INCLUDE_DIRS}
        ${YAML_CPP_INCLUDE_DIR}
)
target_link_libraries(BuildModel PRIVATE
        ntrt::core
        ntrt::tgcreator
        ntrt::util
        ntrt::sensors
        ntrt::core::terrain
        ntrt::tgOpenGLSupport
        yaml-cpp
        LinearMath
)