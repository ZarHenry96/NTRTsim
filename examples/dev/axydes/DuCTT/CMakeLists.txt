option(BUILD_DUCTT "Build the DuCTT robot model" OFF)

find_library(LINEAR_MATH_LIB LinearMath)
find_library(BULLET_DYN_LIB BulletDynamics)

if(BUILD_DUCTT)
    add_executable(AppDuCTTTest
            tgPrismatic.cpp
            tgPrismaticInfo.cpp
            DuCTTTestModel.cpp
            AppDuCTT.cpp
    )
    target_include_directories(AppDuCTTTest PUBLIC
            $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
            ${BULLET_INCLUDE_DIRS}
    )
    target_link_libraries(AppDuCTTTest PRIVATE
            ntrt::tgcreator
            ntrt::core
            ${LINEAR_MATH_LIB}
            ${BULLET_DYN_LIB}
    )
endif()
