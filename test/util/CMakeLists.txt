project(tgcreator_test)

#SET(OPENGL_LIB ${BULLET_PHYSICS_SOURCE_DIR}/Demos/OpenGL)
#SET(OPENGL_FG_LIB ${BULLET_PHYSICS_SOURCE_DIR}/Demos/OpenGL_FreeGlut)
#SET(SRC_DIR ${PROJECT_SOURCE_DIR}/../../src)
#SET(NTRT_BUILD_DIR ${PROJECT_SOURCE_DIR}/../../build)

#include_directories(${CMAKE_CURRENT_BINARY_DIR}
#					${ENV_INC_DIR}
#					${BULLET_PHYSICS_SOURCE_DIR}/src
#					${ENV_INC_DIR}/bullet
#					${ENV_INC_DIR}/boost
#					${ENV_INC_DIR}/tensegrity
#					${SRC_DIR}
#					${OPENGL_LIB}
#					${OPENGL_FG_LIB})
					
# openGL libs required for core
add_executable(CPGEquations_test CPGEquations_test.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		${BULLET_INCLUDE_DIRS}
		${GTEST_INCLUDE_DIRS}
)
target_link_libraries(CPGEquations_test PRIVATE
		GTest
		LinearMath
		ntrt::terrain
		ntrt::core
		ntrt::controllers
		ntrt::util
)
