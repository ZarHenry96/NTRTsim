find_library(BOOST_PO_LIB boost_program_options)
find_library(JSONCPP_LIB jsoncpp)
find_library(NN_LIB neuralNet)

add_executable(AppGATests AppGATests.cpp)
target_include_directories(AppGATests PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${Boost_INCLUDE_DIRS}
        ${NN_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/external/env/include
        /usr/local/include
)
target_link_libraries(AppGATests PRIVATE
        ntrt::learning::Adapters
        ntrt::learning::Configuration
        ntrt::learning::NeuroEvolution
        ntrt::helpers::FileHelpers
        ${BOOST_PO_LIB}
        ${JSONCPP_LIB}
        ${NN_LIB}
)

add_executable(AppJSONLearningTests AppGATests_JSON.cpp
)
target_include_directories(AppJSONLearningTests PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${Boost_INCLUDE_DIRS}
        ${NN_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}/external/env/include
        /usr/local/include
)
target_link_libraries(AppJSONLearningTests PRIVATE
        ntrt::learning::Adapters
        ntrt::learning::Configuration
        ntrt::learning::NeuroEvolution
        ntrt::helpers::FileHelpers
        ${BOOST_PO_LIB}
        ${JSONCPP_LIB}
        ${NN_LIB}
)