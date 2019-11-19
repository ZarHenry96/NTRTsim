project(TensegrityModel)

find_library(LINEAR_MAT_LIB LinearMath)
find_library(YAML_CPP_LIB yaml-cpp)
find_library(BULLET_DYN_LIB BulletDynamics)
find_library(OPENGL_LIB OpenGL)
find_library(GLUT_LIB glut)

add_library(${PROJECT_NAME}
        TensegrityModel.cpp
        TensegrityModelController.cpp
)
add_library(ntrt::models::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${BULLET_INCLUDE_DIRS}
        ${YAML_CPP_INCLUDE_DIR}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
        ntrt::core
        ntrt::tgcreator
        ntrt::util
        ntrt::sensors
        ntrt::terrain
        ntrt::tgOpenGLSupport
        ${YAML_CPP_LIB}
        ${LinearMath}
)

add_executable(BuildModel
        TensegrityModel.cpp
        BuildTensegrityModel.cpp
        TensegrityModelController.cpp
)
target_include_directories(BuildModel PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${BULLET_INCLUDE_DIRS}
        ${YAML_CPP_INCLUDE_DIR}
)
target_link_libraries(BuildModel PRIVATE
        ${OPENGL_LIB}
        ${GLUT_LIB}
        ${YAML_CPP_LIB}
        ${LinearMath}
        ntrt::core
        ntrt::tgcreator
        ntrt::util
        ntrt::sensors
        ntrt::terrain
        ntrt::tgOpenGLSupport
)

# library installation
install(TARGETS ${PROJECT_NAME}
        EXPORT ${CMAKE_PROJECT_NAME}
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
        RUNTIME DESTINATION ${BIN_INSTALL_DIR}
        INCLUDES DESTINATION ${INCLUDE_INSTALL_DIR}
)
list(APPEND EXPORT_TARGETS ${PROJECT_NAME})