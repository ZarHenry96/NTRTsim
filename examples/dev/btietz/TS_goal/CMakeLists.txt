find_library(LINEAR_MATH_LIB LinearMath)
find_library(BOOST_PO_LIB boost_program_options)

add_executable(AppTSGoal
        TetraSpineGoal.cpp
        AppTSGoal.cpp
        )
target_include_directories(AppTSGoal PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
        $<INSTALL_INTERFACE:include>
        $<INSTALL_INTERFACE:examples>
        ${BULLET_INCLUDE_DIRS}
        ${Boost_INCLUDE_DIRS}
)
target_link_libraries(AppTSGoal PRIVATE
        GoalSpine
        FlemonsSpineContact
        learningSpines
        ntrt::core
        ntrt::tgcreator
        ntrt::models::obstacles
        ${LINEAR_MATH_LIB}
        ${BOOST_PO_LIB}
)

