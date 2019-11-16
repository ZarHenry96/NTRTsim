project(TestJSON)

find_library(JSONCPP_LIB jsoncpp)

add_executable(TestJSON testjson.cpp)
target_include_directories(TestJSON PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${CMAKE_SOURCE_DIR}/external/env/include
        /usr/local/include
)
target_link_libraries(TestJSON PRIVATE
        ${JSONCPP_LIB}
        ntrt::helpers::FileHelpers
)
configure_file(data.txt data.txt COPYONLY)
