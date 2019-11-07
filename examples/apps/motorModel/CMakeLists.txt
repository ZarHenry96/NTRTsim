list(APPEND LIBS_TimestepTest
		ntrt::tgcreator
		ntrt::util
		ntrt::sensors
		ntrt::controllers
		ntrt::core
		ntrt::core::terrain
		ntrt::tgOpenGLSupport
)

add_library(TimestepTest tsTestRig.cpp)
target_link_directories(TimestepTest PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(TimestepTest PRIVATE ${LIBS_TimestepTest})

add_executable(AppTSTest
        tsTestRig.cpp
        AppTimestepTest.cpp
)
target_link_directories(AppTSTest PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppTSTest PRIVATE ${LIBS_TimestepTest})
