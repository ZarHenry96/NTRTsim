find_library(JSONCPP_LIB jsoncpp)
find_library(BOOST_PO_LIB boost_program_options)
find_library(NN_LIB neuralNet)

list(APPEND JSON_CTRL_INCLUDE_LIBS
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${CMAKE_SOURCE_DIR}/external/env/include
		/usr/local/include
)
list(APPEND APP_JSONCONTROL_LIBS
		ntrt::helpers::FileHelpers
		${JSONCPP_LIB}
		FlemonsSpineContact
)

add_library(JSONControl
		JSONCPGControl.cpp
		JSONFeedbackControl.cpp
		tgCPGJSONLogger.cpp
)
target_include_directories(JSONControl PUBLIC
		${JSON_CTRL_INCLUDE_LIBS}
		${Boost_INCLUDE_DIRS}
		${NN_INCLUDE_DIRS}
		${CMAKE_SOURCE_DIR}/external/include
		/usr/local/include
)
target_link_libraries(JSONControl PRIVATE
		${APP_JSONCONTROL_LIBS}
		${BOOST_PO_LIB}
		${NN_LIB}
		ntrt::models::obstacles
)

add_executable(AppJSONTests AppJSONTests.cpp)
target_include_directories(AppJSONTests PUBLIC
		${JSON_CTRL_INCLUDE_LIBS}
		${CMAKE_SOURCE_DIR}/external/include
		/usr/local/include
)
target_link_libraries(AppJSONTests PRIVATE
		${APP_JSONCONTROL_LIBS}
)

add_executable(AppSpineJSON
    JSONCPGControl.cpp
    AppJSONSpine.cpp
)
target_include_directories(AppSpineJSON PUBLIC
		${JSON_CTRL_INCLUDE_LIBS}
		${Boost_INCLUDE_DIRS}
		${CMAKE_SOURCE_DIR}/external/include
		/usr/local/include
)
target_link_libraries(AppSpineJSON
		octahedralComplex
		learningSpines
		${APP_JSONCONTROL_LIBS}
		ntrt::core
		ntrt::controllers
		ntrt::sensors
)

add_executable(AppTerrainJSON
		JSONCPGControl.cpp
		JSONFeedbackControl.cpp
		tgCPGJSONLogger.cpp
		AppTerrainJSON.cpp
)
target_include_directories(AppTerrainJSON PUBLIC
		${JSON_CTRL_INCLUDE_LIBS}
		${Boost_INCLUDE_DIRS}
		${NN_INCLUDE_DIRS}
		${CMAKE_SOURCE_DIR}/external/include
		/usr/local/include
)
target_link_libraries(AppTerrainJSON
		${APP_JSONCONTROL_LIBS}
		${BOOST_PO_LIB}
		${NN_LIB}
		ntrt::models::obstacles
		ntrt::core
		ntrt::controllers
		ntrt::sensors
)

configure_file("controlVars.json" "controlVars.json" COPYONLY)
configure_file("controlVarsOct.json" "controlVarsOct.json" COPYONLY)

