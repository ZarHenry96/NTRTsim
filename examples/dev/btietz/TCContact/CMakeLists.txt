find_library(LINEAR_MATH_LIB LinearMath)

add_library(FlemonsSpineContact FlemonsSpineModelContact.cpp)
target_include_directories(FlemonsSpineContact PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(FlemonsSpineContact PRIVATE
        learningSpines
        ntrt::core
        ntrt::tgcreator
        ntrt::core
        ${LINEAR_MATH_LIB}
)


add_executable(AppFlemonsSpineContact
        FlemonsSpineModelContact.cpp
        AppFlemonsSpineContact.cpp
)
target_include_directories(AppFlemonsSpineContact PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
        ${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppFlemonsSpineContact PRIVATE
        learningSpines
        ntrt::core
        ntrt::tgcreator
        ntrt::core
        ${LINEAR_MATH_LIB}
)

