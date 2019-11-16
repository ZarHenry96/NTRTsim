project(tetraSpineLearningSine)

list(APPEND TETRASPINEL_LIB
		tetraSpineHardware
		learningSpines
		ntrt::sensors
		ntrt::tgcreator
		ntrt::util
		ntrt::controllers
		ntrt::core
		ntrt::core::terrain
		ntrt::learning::Adapters
		ntrt::learning::Configuration
		ntrt::learning::AnnealEvolution
		ntrt::tgOpenGLSupport
)

add_library(${PROJECT_NAME} tgSineStringControl.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
)
target_link_libraries(${PROJECT_NAME} PRIVATE ${TETRASPINEL_LIB})

add_executable(AppTetraSpineHardwareSine
        tgSineStringControl.cpp
        LearningSpineSine.cpp
        AppTetraSpineHardwareSine.cpp
)
target_include_directories(AppTetraSpineHardwareSine PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
)
target_link_libraries(AppTetraSpineHardwareSine PRIVATE ${TETRASPINEL_LIB})