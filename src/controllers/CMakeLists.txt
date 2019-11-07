project(controllers)

add_library(${PROJECT_NAME}
        tgBasicController.cpp
        tgImpedanceController.cpp
        tgPIDController.cpp
        tgTensionController.cpp
)
add_library(ntrt::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/include/ntrt/${PROJECT_NAME}
)
target_link_libraries(${PROJECT_NAME} PRIVATE ntrt::core)