project(models)

# Add additional dev directories here.
add_subdirectory(obstacles)
add_subdirectory(TensegrityModel)

add_library(${PROJECT_NAME} obstacles TensegrityModel)
add_library(ntrt::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

