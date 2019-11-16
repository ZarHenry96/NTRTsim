find_library(LINEAR_MATH_LIB LinearMath)
find_library(BOOST_PO_LIB boost_program_options)

add_executable(AppRibbed_MixedLearning
		AppMixedLearning.cpp
	    RibModelMixedContact.cpp)
target_include_directories(AppRibbed_MixedLearning PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
		${Boost_INCLUDE_DIRS}
)
target_link_libraries(AppRibbed_MixedLearning PRIVATE
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
		JSONMixedLearning
		JSONControl
		BaseQuadModelLearning
		BigPuppySpineOnlyStats
		JSONQuadControl
)