find_library(LINEAR_MATH_LIB LinearMath)
find_library(BOOST_PO_LIB boost_program_options)
find_library(JSONCPP_LIB jsoncpp)

add_executable(AppQuadCoupling
        AppQuadCoupling.cpp
        JSONQuadFeedbackControl.cpp
        BigPuppySymmetricSpiral2.cpp
)
target_include_directories(AppQuadCoupling PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
        ${BULLET_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/external/env/include
        /usr/local/include
)
target_link_libraries(AppQuadCoupling PRIVATE
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
        JSONControl
)