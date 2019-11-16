find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppVerticalSpine
        VerticalSpineModel.cpp
        AppVerticalSpine.cpp
        VerticalSpineBendingController.cpp
        VerticalSpinePassiveController.cpp
)
target_include_directories(AppVerticalSpine PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppVerticalSpine PRIVATE
        learningSpines
        ntrt::core
        ntrt::tgcreator
        ntrt::sensors
        ntrt::helpers::FileHelpers
        ${LINEAR_MATH_LIB}
)