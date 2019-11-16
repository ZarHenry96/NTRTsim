find_library(LINEAR_MATH_LIB LinearMath)

list(APPEND STEVE_INCS
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		${BULLET_INCLUDE_DIRS}
)
list(APPEND STEVE_LIBS
		ntrt::tgcreator
		ntrt::core
		ntrt::learning::Adapters
)

add_executable(AppT12SuperBallPayload
        T12SuperBallPayload/T12SuperBallPayload.cpp
        T12SuperBallPayload/T12SuperBallPayloadController.cpp
        T12SuperBallPayload/AppT12SuperBallPayload.cpp
)
target_include_directories(AppT12SuperBallPayload PUBLIC ${STEVE_INCS})
target_link_libraries(AppT12SuperBallPayload PRIVATE
		${STEVE_LIBS}
		${LINEAR_MATH_LIB}
)

add_executable(AppScarrArm
        ScarrArm/ScarrArmModel.cpp
        ScarrArm/ScarrArmController.cpp
        ScarrArm/AppScarrArm.cpp
)
target_include_directories(AppScarrArm PUBLIC ${STEVE_INCS})
target_link_libraries(AppScarrArm PRIVATE
		${STEVE_LIBS}
		${LINEAR_MATH_LIB}
)

file(COPY Escape_T6/Config.ini DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(AppEscape_T6
        Escape_T6/Crater.cpp
        Escape_T6/CraterDeep.cpp
        Escape_T6/Escape_T6Model.cpp
        Escape_T6/Escape_T6Controller.cpp
        Escape_T6/AppEscape_T6.cpp
)
target_include_directories(AppEscape_T6 PUBLIC ${STEVE_INCS})
target_link_libraries(AppEscape_T6 PRIVATE
		${STEVE_LIBS}
		ntrt::helpers::FileHelpers
		${LINEAR_MATH_LIB}
)

add_custom_command(TARGET AppEscape_T6 POST_BUILD
		COMMAND ln -sf Escape_T6/logs
)