project(prismModel)

add_executable(AppPrismModel
        PrismModel.cpp
        PrismModel.h
        AppPrismModel.cpp
)
target_include_directories(AppPrismModel PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)
target_link_libraries(AppPrismModel PRIVATE
        ntrt::tgcreator
        ntrt::util
        ntrt::sensors
        ntrt::core
        ntrt::terrain
        ntrt::tgOpenGLSupport
)

