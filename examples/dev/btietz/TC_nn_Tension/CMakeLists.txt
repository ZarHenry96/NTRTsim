find_library(LINEAR_MATH_LIB LinearMath)
find_library(BOOST_PO_LIB boost_program_options)
find_library(NN_LIB neuralNet)
find_library(JSONCPP_LIB jsoncpp)

add_executable(AppTCNNW_Tension
        JSONGoalTensionNNW.cpp
        AppGoalTensionNNW.cpp
)
target_include_directories(AppTCNNW_Tension PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
        ${Boost_INCLUDE_DIRS}
        ${NN_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/external/env/include
        /usr/local/include
)
target_link_libraries(AppTCNNW_Tension PRIVATE
        GoalSpine
        FlemonsSpineContact
        learningSpines
        ntrt::helpers::FileHelpers
        ntrt::models::obstacles
        ntrt::core
        ntrt::tgcreator
        ntrt::util
        ${BOOST_PO_LIB}
        ${NN_LIB}
        JSONControl
)