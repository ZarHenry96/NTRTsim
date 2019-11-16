# set input and output files
set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile)
set(DOXYGEN_OUT ${CMAKE_CURRENT_SOURCE_DIR}/docs/doxyDocs)
set(DOXYGEN_GENERATE_HTML YES)
set(INPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

add_custom_target(
        doc ALL
        COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
)