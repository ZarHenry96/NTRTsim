#link_directories(${LIB_DIR})
#
#link_libraries(core
#               tgcreator
#               controllers
#               util
#               sensors
#               terrain
#               tgOpenGLSupport
#               yaml-cpp
#	       Adapters
#	       TensegrityModel)

# add_library(TensegrityModel
#     TensegrityModel.cpp)

add_executable(App12Bar
#    TensegrityModel.cpp
        App12Bar.cpp
        RPLengthController.h
        RPLengthController_rand.cpp)
target_link_directories(App12Bar PUBLIC
		${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(App12Bar PRIVATE
		ntrt::core
		ntrt::tgcreator
		ntrt::controllers
		ntrt::util
		ntrt::sensors
		ntrt::core::terrain
		ntrt::tgOpenGLSupport
		yaml-cpp
		ntrt::learning::Adapters
		ntrt::models::TensegrityModel
)


