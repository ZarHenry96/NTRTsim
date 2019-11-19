project(prismModel_serialize)

find_library(JSONCPP_LIB jsoncpp)

add_executable(AppPrismModel_Serialize
		PrismModel.cpp
		PrismModel.h
		AppPrismModel.cpp
)
target_include_directories(AppPrismModel_Serialize PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
		${CMAKE_SOURCE_DIR}/external/env/include
		/usr/local/include
)
target_link_libraries(AppPrismModel_Serialize PRIVATE
		${JSONCPP_LIB}
		ntrt::helpers::FileHelpers
		ntrt::tgcreator
		ntrt::util
		ntrt::sensors
		ntrt::core
		ntrt::terrain
		ntrt::tgOpenGLSupport
)

