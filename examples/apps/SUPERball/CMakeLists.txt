
find_library(LINEAR_MATH_LIB LinearMath)

add_executable(AppSUPERball
        T6Model.cpp
        AppSUPERball.cpp
        controllers/T6TensionController.cpp
)
target_include_directories(AppSUPERball PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
)
target_link_libraries(AppSUPERball PRIVATE
        ntrt::tgcreator
        ntrt::controllers
        ntrt::core
        ${LINEAR_MATH_LIB}
)