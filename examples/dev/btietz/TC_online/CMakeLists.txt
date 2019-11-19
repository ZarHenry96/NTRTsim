find_library(LINEAR_MATH_LIB LinearMath)
find_library(BOOST_PO_LIB boost_program_options)
find_library(NN_LIB neuralNet)

add_executable(AppGoalOnline
        SpineOnlineControl.cpp
        AppGoalOnline.cpp
)
target_include_directories(AppGoalOnline PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
        ${BULLET_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
        ${NN_INCLUDE_DIRS}
)
target_link_libraries(AppGoalOnline PRIVATE
        GoalSpine
        learningSpines
        ntrt::helpers::FileHelpers
        ntrt::models::obstacles
        ntrt::core
        ntrt::tgcreator
        ntrt::controllers
        ntrt::util
        ntrt::learning::Adapters
        ntrt::learning::Configuration
        ntrt::learning::NeuroEvolution
        ${LINEAR_MATH_LIB}
        ${BOOST_PO_LIB}
        ${NN_LIB}
)