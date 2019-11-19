add_executable(AppOctaCL_CPG AppOctaCL_CPG.cpp)
target_include_directories(AppOctaCL_CPG PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
        ${Boost_INCLUDE_DIR}
)
target_link_libraries(AppOctaCL_CPG PRIVATE
        octahedralComplex
        learningSpines
        ntrt::core
)
