project(tgOpenGLSupport)

add_subdirectory(tgOpenGLBase)
add_subdirectory(tgOpenGLFreeGlut)

add_library(${PROJECT_NAME} tgOpenGLBase tgOpenGLFreeGlut)
add_library(ntrt::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PRIVATE
        ntrt::${PROJECT_NAME}::tgOpenGLFreeGlut
        ntrt::${PROJECT_NAME}::tgOpenGLBase
)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)