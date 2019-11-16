add_executable(AppTetraSpineHardware
	tgCPGStringControl_mod.cpp
	LearningSpineJSON.cpp
	AppTetraSpineHardwareLearning.cpp
)
target_include_directories(AppTetraSpineHardware PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
)
target_link_libraries(AppTetraSpineHardware PRIVATE
		tetraSpineHardware
		learningSpines
		ntrt::core
		ntrt::helpers
		ntrt::controllers
		ntrt::learning
		ntrt::util
)

configure_file("controlVars.json" "controlVars.json" COPYONLY)
file(COPY nodeConfig.ini DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY edgeConfig.ini DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(TARGET AppTetraSpineHardware POST_BUILD
					COMMAND ln -sf ${CMAKE_CURRENT_SOURCE_DIR}/logs)
