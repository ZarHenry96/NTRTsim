project(tetraSpineHardware)

add_library(${PROJECT_NAME}
        TetraSpineStaticModel_hf.cpp
        TetraSpineStaticModel.cpp
        SerializedSpineControl.cpp
)
target_link_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(${PROJECT_NAME} PRIVATE
        learningSpines
        ntrt::sensors
        ntrt::tgcreator
        ntrt::core
        ntrt::util
        ntrt::core::terrain
        ntrt::tgOpenGLSupport
        ntrt::helpers::FileHelpers
        jsoncpp
)

add_executable(AppTetraSpineStatic
        SerializedSpineControl.cpp
        TetraSpineStaticModel.cpp
        TetraSpineStaticModel_hf.cpp
        AppTetraSpineStatic.cpp
)

target_link_directories(AppTetraSpineStatic PUBLIC
        ${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(AppTetraSpineStatic
        PRIVATE
        learningSpines
        ntrt::sensors
        ntrt::tgcreator
        ntrt::core
        ntrt::util
        ntrt::core::terrain
        ntrt::tgOpenGLSupport
        ntrt::helpers::FileHelpers
        jsoncpp
)