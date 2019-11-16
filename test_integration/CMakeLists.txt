project(NTRT_Test_Integration)

option(USE_DOUBLE_PRECISION "Use double precision" ON)

add_subdirectory(ICRA2015Tests)
add_subdirectory(MuscleNP)
add_subdirectory(SpineTests)
add_subdirectory(TimestepIndependence)
