# set input and output files
set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile)
set(DOXYGEN_OUT ${CMAKE_CURRENT_SOURCE_DIR}/docs/doxyDocs)
set(DOXYGEN_GENERATE_HTML YES)
set(INPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

find_package(Dot)
if (DOT_FOUND)
    set(HAVE_DOT YES)
else (DOT_FOUND)
    set(HAVE_DOT NO)
endif(DOT_FOUND)

# request to configure the file
configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
message("Doxygen build started")

add_custom_target(
        doc ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
)