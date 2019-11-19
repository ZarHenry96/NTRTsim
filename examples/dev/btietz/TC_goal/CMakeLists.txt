find_library(LINEAR_MATH_LIB LinearMath)
find_library(BOOST_PO_LIB boost_program_options)
find_library(NN_LIB neuralNet)
find_library(JSONCPP_LIB jsoncpp)

add_library(GoalSpine
        BaseSpineModelGoal.cpp
        FlemonsSpineModelGoal.cpp
        SpineGoalControl.cpp
        JSONGoalControl.cpp
)
target_include_directories(GoalSpine PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
        ${BULLET_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
        ${NN_INCLUDE_DIRS}
        )
target_link_libraries(GoalSpine PRIVATE
        ntrt::helpers::FileHelpers
        ntrt::models::obstacles
        ntrt::core
        ntrt::tgcreator
        ntrt::util
        ntrt::learning
        ntrt::controllers
        ${LINEAR_MATH_LIB}
        ${BOOST_PO_LIB}
        JSONControl
        learningSpines
)

add_executable(AppGoalTerrain
        BaseSpineModelGoal.cpp
        FlemonsSpineModelGoal.cpp
        SpineGoalControl.cpp
        JSONGoalControl.cpp
        AppGoalTerrain.cpp
)
target_include_directories(AppGoalTerrain PUBLIC
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
target_link_libraries(AppGoalTerrain PRIVATE
        learningSpines
        ntrt::helpers::FileHelpers
        ntrt::models::obstacles
        ntrt::core
        ntrt::tgcreator
        ntrt::util
        ntrt::learning
        ntrt::controllers
        ${LINEAR_MATH_LIB}
        ${BOOST_PO_LIB}
        ${JSONCPP_LIB}
        ${NN_LIB}
        JSONControl
)

