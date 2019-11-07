project(prismModel_serialize)

add_executable(AppPrismModel_Serialize
		PrismModel.cpp
		AppPrismModel.cpp
)
target_link_directories(AppPrismModel_Serialize PUBLIC
		${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(AppPrismModel_Serialize PRIVATE
		jsoncpp
		ntrt::helpers::FileHelpers
		ntrt::tgcreator
		ntrt::util
		ntrt::sensors
		ntrt::core
		ntrt::core::terrain
		ntrt::tgOpenGLSupport
)

