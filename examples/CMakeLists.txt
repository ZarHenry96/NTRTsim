add_subdirectory(apps)

if(BUILD_DEV_EXAMPLES)
    message("-- Dev examples will be built")
    add_subdirectory(dev)
endif()