
add_executable(AppSUPERball
        T6Model.cpp
        AppSUPERball.cpp
        controllers/T6TensionController.cpp
)
target_link_directories(AppSUPERball PUBLIC ${CMAKE_SOURCE_DIR}/include/ntrt)
target_link_libraries(AppSUPERball PRIVATE ntrt::tgcreator ntrt::controllers ntrt::core)

# To compile a controller, add a line like the
# following inside add_executable:
#    controllers/T6TensionController.cpp
