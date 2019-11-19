find_library(LINEAR_MATH_LIB LinearMath)
find_library(BOOST_PO_LIB boost_program_options)
find_library(NN_LIB neuralNet)
find_library(JSONCPP_LIB jsoncpp)

list(APPEND SPINE_CONTROL_INCS
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
		${Boost_INCLUDE_DIRS}
		${NN_INCLUDE_DIRS}
		${CMAKE_SOURCE_DIR}/external/env/include
		/usr/local/include
)
list(APPEND SPINE_CONTROL_LIBS
		learningSpines
		ntrt::util
		ntrt::learning
		ntrt::controllers
		ntrt::tgcreator
		ntrt::core
		ntrt::helpers::FileHelpers
		ntrt::models::obstacles
		ntrt::sensors
		${LINEAR_MATH_LIB}
		${BOOST_PO_LIB}
		${JSONCPP_LIB}
		${NN_LIB}
		JSONControl
		BaseQuadModelLearning
		MountainGoat
)

add_library(tgCPGGMGActuatorControl tgCPGMGActuatorControl.cpp)
target_include_directories(tgCPGGMGActuatorControl PUBLIC ${SPINE_CONTROL_INCS})
target_link_libraries(tgCPGGMGActuatorControl PRIVATE ${SPINE_CONTROL_LIBS})

add_library(tgCPGMGCableControl tgCPGMGCableControl.cpp)
target_include_directories(tgCPGMGCableControl PUBLIC ${SPINE_CONTROL_INCS})
target_link_libraries(tgCPGMGCableControl PRIVATE ${SPINE_CONTROL_LIBS})

add_library(JSONMGCPGGeneralControl JSONMGCPGGeneralControl.cpp)
target_include_directories(JSONMGCPGGeneralControl PUBLIC ${SPINE_CONTROL_INCS})
target_link_libraries(JSONMGCPGGeneralControl PRIVATE ${SPINE_CONTROL_LIBS})

add_library(JSONMGFeedbackControl JSONMGFeedbackControl.cpp)
target_include_directories(JSONMGFeedbackControl PUBLIC ${SPINE_CONTROL_INCS})
target_link_libraries(JSONMGFeedbackControl PRIVATE ${SPINE_CONTROL_LIBS})

add_executable(AppMGControl
		AppMGControl.cpp
		JSONMGFeedbackControl.cpp
		JSONMGCPGGeneralControl.cpp
		tgCPGMGCableControl.cpp
		tgCPGMGActuatorControl.cpp
)
target_include_directories(AppMGControl PUBLIC ${SPINE_CONTROL_INCS})
target_link_libraries(AppMGControl PRIVATE ${SPINE_CONTROL_LIBS})

