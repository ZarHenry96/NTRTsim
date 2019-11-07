project(MuscleNP)

add_library(${PROJECT_NAME}
        tgGhostInfo.cpp
        tgGhostModel.cpp
)
target_link_directories(${PROJECT_NAME}  PUBLIC
		${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(${PROJECT_NAME} PRIVATE
		ntrt::tgcreator
		ntrt::core
		ntrt::tgOpenGLSupport
)