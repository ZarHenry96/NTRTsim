find_library(JSONCPP_LIB jsoncpp)

add_executable(AppTetraSpineHT
	htSpineSine.cpp
	AppTetraSpineHT.cpp
)
target_include_directories(AppTetraSpineHT PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${CMAKE_SOURCE_DIR}/external/env/include
		/usr/local/include
)
target_link_libraries(AppTetraSpineHT PRIVATE
		tetraSpineLearningSine
		tetraSpineHardware
		learningSpines
		ntrt::core
		ntrt::controllers
		ntrt::sensors
		ntrt::helpers::FileHelpers
		ntrt::learning
		${JSONCPP_LIB}
)
configure_file("controlVars.json" "controlVars.json" COPYONLY)

