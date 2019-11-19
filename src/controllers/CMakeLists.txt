project(controllers)

add_library(${PROJECT_NAME}
        tgBasicController.cpp
        tgImpedanceController.cpp
        tgPIDController.cpp
        tgTensionController.cpp
)
add_library(ntrt::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} PRIVATE ntrt::core)

# library installation
install(TARGETS ${PROJECT_NAME}
        EXPORT ${CMAKE_PROJECT_NAME}
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
        RUNTIME DESTINATION ${BIN_INSTALL_DIR}
        INCLUDES DESTINATION ${INCLUDE_INSTALL_DIR}
)
list(APPEND EXPORT_TARGETS ${PROJECT_NAME})