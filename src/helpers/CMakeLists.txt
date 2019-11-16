project(helpers)

add_subdirectory(FileHelpers)

add_library(${PROJECT_NAME} FileHelpers)
add_library(ntrt::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)