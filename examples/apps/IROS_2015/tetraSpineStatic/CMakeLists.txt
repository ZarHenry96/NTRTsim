project(tetraSpineHardware)

find_library(LINEAR_MATH_LIB LinearMath)
find_library(JSONCPP_LIB jsoncpp)

list(APPEND TETRASPINEH_LIB
        learningSpines
        ntrt::sensors
        ntrt::tgcreator
        ntrt::core
        ntrt::util
        ntrt::terrain
        ntrt::tgOpenGLSupport
        ntrt::helpers::FileHelpers
        ${LINEAR_MATH_LIB}
        ${JSONCPP_LIB}
)

add_library(${PROJECT_NAME}
        TetraSpineStaticModel_hf.cpp
        TetraSpineStaticModel.cpp
        SerializedSpineControl.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
)
target_link_libraries(${PROJECT_NAME} PRIVATE ${TETRASPINEH_LIB})

add_executable(AppTetraSpineStatic
        SerializedSpineControl.cpp
        TetraSpineStaticModel.cpp
        TetraSpineStaticModel_hf.cpp
        AppTetraSpineStatic.cpp
)
target_include_directories(AppTetraSpineStatic PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
)
target_link_libraries(AppTetraSpineStatic PRIVATE ${TETRASPINEH_LIB})