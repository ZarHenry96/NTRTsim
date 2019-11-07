project(ICRA2015_test)
             
add_executable(${PROJECT_NAME} ICRA2015_test.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		${OPENGL_INCLUDE_DIR}
		${GLUT_INCLUDE_DIR}
		${BULLET_INCLUDE_DIRS}
		${GTEST_INCLUDE_DIRS}
		# examples folder
		${CMAKE_SOURCE_DIR}/examples/apps
)
target_link_directories(${PROJECT_NAME} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		${CMAKE_SOURCE_DIR}/examples/apps
		${CMAKE_SOURCE_DIR}/examples/apps/IROS_2015/
)
target_link_libraries(${PROJECT_NAME} PRIVATE
		GTest
		pthread
		ntrt::core
		ntrt::helpers::FileHelpers
		ntrt::tgOpenGLSupport
		learningSpines/liblearningSpines.so
		IROS_2015/TetraSpineStatic/libtetraSpineHardware.so
)
