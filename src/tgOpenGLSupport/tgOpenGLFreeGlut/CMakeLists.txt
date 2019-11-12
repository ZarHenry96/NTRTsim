project(tgOpenGLFreeGlut)

#INCLUDE_DIRECTORIES(
#${BULLET_PHYSICS_SOURCE_DIR}/src ${BULLET_PHYSICS_SOURCE_DIR}/Extras/ConvexHull
#${BULLET_PHYSICS_SOURCE_DIR}/Demos/OpenGL
#)
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
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
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

#IF (BUILD_SHARED_LIBS)
#  TARGET_LINK_LIBRARIES(tgOpenGLSupport OpenGLSupport BulletDynamics BulletCollision ${GLUT_glut_LIBRARY} ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY})
#ENDIF (BUILD_SHARED_LIBS)

##INSTALL of other files requires CMake 2.6
#IF (${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} GREATER 2.5)
#        IF(INSTALL_EXTRA_LIBS)
#                IF (APPLE AND BUILD_SHARED_LIBS AND FRAMEWORK)
#                        INSTALL(TARGETS tgOpenGLSupport OpenGLSupport DESTINATION .)
#                ELSE (APPLE AND BUILD_SHARED_LIBS AND FRAMEWORK)
#                INSTALL(TARGETS tgOpenGLSupport OpenGLSupport DESTINATION lib)
#                        INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} DESTINATION include FILES_MATCHING PATTERN "*.h")
#                ENDIF (APPLE AND BUILD_SHARED_LIBS AND FRAMEWORK)
#        ENDIF (INSTALL_EXTRA_LIBS)
#ENDIF (${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} GREATER 2.5)

