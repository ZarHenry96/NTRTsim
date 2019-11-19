project(tgOpenGLFreeGlut)

find_library(GLU_LIB GLU)
find_library(GLUT_LIB glut)
find_library(OPENGL_LIB OpenGL)
find_library(LINEAR_MAT_LIB LinearMath)
find_library(BULLET_DYN_LIB BulletDynamics)
find_library(BULLET_COLLISION_LIB BulletCollision)

add_library(${PROJECT_NAME}
        tgDemoApplication.cpp
        tgGlutDemoApplication.cpp
        tgGlutStuff.cpp
        tgGLDebugDrawer.cpp
)
add_library(ntrt::tgOpenGLSupport::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${BULLET_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR}
        ${OPENGL_EGL_INCLUDE_DIRS}
        ${GLUT_INCLUDE_DIR}
)
target_link_libraries(${PROJECT_NAME} PRIVATE
        ${OPENGL_LIB}
        ${GLUT_LIB}
        ${GLU_LIB}
        ${LINEAR_MATH_LIB}
        ${BULLET_DYN_LIB}
        ${BULLET_COLLISION_LIB}
        ntrt::tgOpenGLSupport::tgOpenGLBase
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

