option(BUILD_DUCTT "Build the DuCTT robot model" OFF)

if(BUILD_DUCTT)
    add_executable(AppDuCTTTest
            tgPrismatic.cpp
            tgPrismaticInfo.cpp
            DuCTTTestModel.cpp
            AppDuCTT.cpp
    )
    target_link_directories(AppDuCTTTest PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
    target_link_libraries(AppDuCTTTest PRIVATE ntrt::tgcreator ntrt::core)
endif()
