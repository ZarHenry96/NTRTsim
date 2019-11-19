find_library(BOOST_PO_LIB boost_program_options)

add_executable(AppMultiTerrain AppMultiTerrain.cpp)
target_include_directories(AppMultiTerrain PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
        ${Boost_INCLUDE_DIRS}
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppMultiTerrain PRIVATE
        FlemonsSpineContact
        octahedralComplex
        learningSpines
        ntrt::core
        ntrt::controllers
        ntrt::sensors
        ntrt::models::obstacles
        ${BOOST_PO_LIB}
)