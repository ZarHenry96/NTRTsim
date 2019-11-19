project(FileHelpers)

# Compose our header file for resource inclusion
set(RESOURCE_PATH "${CMAKE_SOURCE_DIR}/resources/src")
set(TEST_RESOURCE_PATH "${CMAKE_SOURCE_DIR}/resources/test")
configure_file("${FileHelpers_SOURCE_DIR}/resources.h.in"
               "${CMAKE_SOURCE_DIR}/include/ntrt/helpers/resources.h")

add_library(FileHelpers FileHelpers.cpp)
add_library(ntrt::helpers::${PROJECT_NAME} ALIAS FileHelpers)

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# library installation
install(TARGETS ${PROJECT_NAME}
        EXPORT ${CMAKE_PROJECT_NAME}
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
        RUNTIME DESTINATION ${BIN_INSTALL_DIR}
        INCLUDES DESTINATION ${INCLUDE_INSTALL_DIR}
)
list(APPEND EXPORT_TARGETS ${PROJECT_NAME})