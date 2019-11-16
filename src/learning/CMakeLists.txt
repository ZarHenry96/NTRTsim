project(learning)

# Add additional learning library directories here.
add_subdirectory(Configuration)
add_subdirectory(AnnealEvolution)
add_subdirectory(NeuroEvolution)
add_subdirectory(Adapters)

add_library(${PROJECT_NAME} Configuration AnnealEvolution NeuroEvolution Adapters)
target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
)
add_library(ntrt::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)