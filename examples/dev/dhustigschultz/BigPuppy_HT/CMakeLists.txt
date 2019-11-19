find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppBigPuppy_HandTuned
    BigPuppyController.cpp
    BigPuppy.cpp
    AppBigPuppy.cpp
)
target_include_directories(AppBigPuppy_HandTuned PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigPuppy_HandTuned PRIVATE
        ntrt::core
        ntrt::tgcreator
        ntrt::sensors
        ${LINEAR_MATH_LIB}
)