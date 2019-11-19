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

# library installation
install(TARGETS ${PROJECT_NAME}
        EXPORT ${CMAKE_PROJECT_NAME}
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
        RUNTIME DESTINATION ${BIN_INSTALL_DIR}
        INCLUDES DESTINATION ${INCLUDE_INSTALL_DIR}
)
list(APPEND EXPORT_TARGETS ${PROJECT_NAME})