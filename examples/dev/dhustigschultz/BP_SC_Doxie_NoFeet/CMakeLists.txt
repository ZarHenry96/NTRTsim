#target_link_libraries(AppQuadControlDoxieNF ${ENV_LIB_DIR}/libjsoncpp.a FileHelpers boost_program_options obstacles JSONControl)
find_library(LINEAR_MATH_LIB LinearMath)
find_library(BOOST_PO_LIB boost_program_options)

add_executable(AppQuadControlDoxieNF AppQuadControlDoxieNF.cpp)
target_include_directories(AppQuadControlDoxieNF PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
		${Boost_INCLUDE_DIRS}
)
target_link_libraries(AppQuadControlDoxieNF PRIVATE
		BigDoxieNoFeet
		JSONQuadFeedback
		learningSpines
		ntrt::core
		ntrt::tgcreator
		ntrt::models::obstacles
		${LINEAR_MATH_LIB}
		${BOOST_PO_LIB}
)

