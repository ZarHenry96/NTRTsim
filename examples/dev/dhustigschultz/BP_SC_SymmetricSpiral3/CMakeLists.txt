find_library(LINEAR_MATH_LIB LinearMath)
find_library(BOOST_PO_LIB boost_program_options)
find_library(NN_LIB neuralNet)
find_library(JSONCPP_LIB jsoncpp)

list(APPEND SPINE_CONTROL_INCS
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
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
		${LINEAR_MATH_LIB}
		${BOOST_PO_LIB}
		${JSONCPP_LIB}
		${NN_LIB}
		JSONControl
		JSONQuadControl
		BigPuppySymmetricSpiralMetrics
		BaseQuadModelLearning
)

add_library(JSONMetricsFeedbackControl JSONMetricsFeedbackControl.cpp)
target_include_directories(JSONMetricsFeedbackControl PUBLIC ${SPINE_CONTROL_INCS})
target_link_libraries(JSONMetricsFeedbackControl PRIVATE ${SPINE_CONTROL_LIBS})

add_executable(AppQuadControlMetrics
		AppQuadControlMetrics.cpp
	    JSONMetricsFeedbackControl.cpp
)
target_include_directories(AppQuadControlMetrics PUBLIC ${SPINE_CONTROL_INCS})
target_link_libraries(AppQuadControlMetrics PRIVATE ${SPINE_CONTROL_LIBS})
