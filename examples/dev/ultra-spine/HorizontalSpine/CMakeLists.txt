
# add_library(TensegrityModel
#     TensegrityModel.cpp)

add_executable(AppHorizontalSpine
#    TensegrityModel.cpp
        AppHorizontalSpine.cpp)
target_link_directories(AppHorizontalSpine PUBLIC
		${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(AppHorizontalSpine PRIVATE
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


