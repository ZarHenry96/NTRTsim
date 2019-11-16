# link_directories(${LIB_DIR})

# message(STATUS "LIB_DIR: " ${LIB_DIR})

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

add_executable(AppSTLParser AppSTLParser.cpp)
#    TensegrityModel.cpp
#    RPLengthController.h
#    RPLengthController_rand.cpp


configure_file("LunarSurface-ascii.stl" "LunarSurface-ascii.stl" COPYONLY)