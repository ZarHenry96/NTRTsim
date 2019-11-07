#add_library(
#  tgDataObserver.cpp
#  tgDataLogger.cpp
#)

add_executable(AppVerticalSpine
        VerticalSpineModel.cpp
        AppVerticalSpine.cpp
        VerticalSpineBendingController.cpp
        VerticalSpinePassiveController.cpp
)
target_link_directories(AppVerticalSpine PUBLIC
        ${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(AppVerticalSpine PRIVATE
        ntrt::core
        ntrt::tgcreator
        ntrt::sensors
        ntrt::learning::Adapters
)
