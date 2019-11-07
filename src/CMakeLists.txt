add_subdirectory(tgOpenGLSupport)
add_subdirectory(core)
add_subdirectory(controllers)
add_subdirectory(helpers)
add_subdirectory(util)
add_subdirectory(sensors)
add_subdirectory(tgcreator)
add_subdirectory(models)
add_subdirectory(learning)

add_library(ntrt
        tgOpenGLSupport
        core
        controllers
        helpers
        util
        tgcreator
        models
        learning
)
set_target_properties(ntrt PROPERTIES LINKER_LANGUAGE CXX)