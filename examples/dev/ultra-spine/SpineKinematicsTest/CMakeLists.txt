# add_library(TensegrityModel
#     TensegrityModel.cpp)

add_executable(AppSpineKinematicsTest
        SpineKinematicsTestController.cpp
        AppSpineKinematicsTest.cpp
)
target_link_directories(AppSpineKinematicsTest PUBLIC
		${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(AppSpineKinematicsTest PRIVATE
		ntrt::core
		ntrt::tgcreator
		ntrt::util
		ntrt::sensors
		ntrt::core::terrain
		ntrt::tgOpenGLSupport
		yaml-cpp
		ntrt::learning::Adapters
		ntrt::models::TensegrityModel
)


