project(sensors)

find_library(LINEAR_MATH_LIB LinearMath)
find_library(BOOST_REGEX_LIB boost_regex)

add_library(${PROJECT_NAME}
        # Older software
        tgDataLogger.cpp
        tgDataObserver.cpp
        # For the new sensors
        tgDataManager.cpp
        tgDataLogger2.cpp

        tgSensor.cpp
        tgRodSensor.cpp
        tgSpringCableActuatorSensor.cpp
        tgCompoundRigidSensor.cpp
        tgSensorInfo.cpp
        tgRodSensorInfo.cpp
        tgSpringCableActuatorSensorInfo.cpp
        tgCompoundRigidSensorInfo.cpp
)
add_library(ntrt::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${Boost_INCLUDE_DIRS}
        ${BULLET_INCLUDE_DIRS}
)

# Note that we need to compile in support for boost's regex library
# for use in tgCompoundRigidSensor and its info class.
target_link_libraries(${PROJECT_NAME} PRIVATE
        ntrt::tgOpenGLSupport
        ntrt::core
        ntrt::util
        ${BOOST_REGEX_LIB}
        ${LINEAR_MATH_LIB}
)

# library installation
install(TARGETS ${PROJECT_NAME}
        EXPORT ${CMAKE_PROJECT_NAME}
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
        RUNTIME DESTINATION ${BIN_INSTALL_DIR}
        INCLUDES DESTINATION ${INCLUDE_INSTALL_DIR}
)
list(APPEND EXPORT_TARGETS ${PROJECT_NAME})