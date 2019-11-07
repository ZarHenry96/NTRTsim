project(prismModel)

add_executable(AppPrismModel
        PrismModel.cpp
        AppPrismModel.cpp
)
target_link_directories(AppPrismModel PUBLIC
        ${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(AppPrismModel PRIVATE
        ntrt::tgcreator
        ntrt::util
        ntrt::sensors
        ntrt::core
        ntrt::core::terrain
        ntrt::tgOpenGLSupport
)

