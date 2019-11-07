project(tetraSpineLearningSine)

add_library(${PROJECT_NAME} tgSineStringControl.cpp)
target_link_directories(${PROJECT_NAME} PUBLIC
		${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(${PROJECT_NAME} PRIVATE
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
		ntrt::tgOpenGLSupport)

add_executable(AppTetraSpineHardwareSine
        tgSineStringControl.cpp
        LearningSpineSine.cpp
        AppTetraSpineHardwareSine.cpp
)
target_link_directories(AppTetraSpineHardwareSine PUBLIC
		${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(AppTetraSpineHardwareSine PRIVATE
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