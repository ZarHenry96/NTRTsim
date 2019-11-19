find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppInternalFiction
        T6Model.cpp
        AppSUPERball.cpp
)
target_include_directories(AppInternalFiction PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${BULLET_INCLUDE_DIRS}
        )
target_link_libraries(AppInternalFiction PRIVATE
        ntrt::core
        ntrt::tgcreator
        ${LINEAR_MATH_LIB}
)