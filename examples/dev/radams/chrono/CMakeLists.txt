find_library(BOOST_CHRONO_LIB boost_chrono)
find_library(BOOST_SYSTEM_LIB boost_system)

add_executable(AppChronoTest chronoTest.cpp)
target_include_directories(AppChronoTest PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        ${Boost_INCLUDE_DIRS}
)
target_link_libraries(AppChronoTest PRIVATE
        ${BOOST_CHRONO_LIB}
        ${BOOST_SYSTEM_LIB}
)