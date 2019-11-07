
add_executable(App6Bar
        RPLengthController.h
        RPLengthController_rand.cpp
        App6Bar.cpp
)
target_link_directories(App6Bar PUBLIC
		${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(App6Bar
		PRIVATE
		ntrt::core
		ntrt::tgcreator
		ntrt::controllers
		ntrt::util
		ntrt::sensors
		ntrt::core::terrain
		ntrt::tgOpenGLSupport
		ntrt::learning::Adapters
		ntrt::models::TensegrityModel
		yaml-cpp
)


