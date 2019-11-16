find_library(LINEAR_MATH_LIB LinearMath)
find_library(BOOST_PO_LIB boost_program_options)
find_library(NN_LIB neuralNet)
find_library(JSONCPP_LIB jsoncpp)

add_library(JSONGoalTension JSONGoalTension.cpp)
target_include_directories(JSONGoalTension PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
        ${Boost_INCLUDE_DIRS}
        ${NN_INCLUDE_DIRS}
)
target_link_libraries(JSONGoalTension PRIVATE
        GoalSpine
        FlemonsSpineContact
        learningSpines
        ntrt::helpers::FileHelpers
        ntrt::models::obstacles
        ntrt::core
        ntrt::tgcreator
        ntrt::util
        ntrt::learning
        ntrt::controllers
        ${BOOST_PO_LIB}
        ${JSONCPP_LIB}
        ${NN_LIB}
        JSONControl
)

add_executable(AppTC_Tension
        JSONGoalTension.cpp
        AppGoalTension.cpp
)
target_include_directories(AppTC_Tension PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
        ${Boost_INCLUDE_DIRS}
        ${NN_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/external/env/include
        /usr/local/include
)
target_link_libraries(AppTC_Tension PRIVATE
        GoalSpine
        FlemonsSpineContact
        learningSpines
        ntrt::helpers::FileHelpers
        ntrt::models::obstacles
        ntrt::core
        ntrt::tgcreator
        ntrt::util
        ntrt::learning
        ntrt::controllers
        ${BOOST_PO_LIB}
        ${JSONCPP_LIB}
        ${NN_LIB}
        JSONControl
)

