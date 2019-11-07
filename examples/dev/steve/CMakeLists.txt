link_libraries(tgcreator core Adapters)

add_executable(AppT12SuperBallPayload
        T12SuperBallPayload/T12SuperBallPayload.cpp
        T12SuperBallPayload/T12SuperBallPayloadController.cpp
        T12SuperBallPayload/AppT12SuperBallPayload.cpp
)
target_link_directories(AppT12SuperBallPayload PUBLIC
		${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(AppT12SuperBallPayload PRIVATE
		ntrt::tgcreator
		ntrt::core
		ntrt::learning::Adapters
)
 
add_executable(AppScarrArm
        ScarrArm/ScarrArmModel.cpp
        ScarrArm/ScarrArmController.cpp
        ScarrArm/AppScarrArm.cpp
)
target_link_directories(AppScarrArm PUBLIC
		${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(AppScarrArm PRIVATE
		ntrt::tgcreator
		ntrt::core
		ntrt::learning::Adapters
)

file(COPY Escape_T6/Config.ini DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(AppEscape_T6
        Escape_T6/Crater.cpp
        Escape_T6/CraterDeep.cpp
        Escape_T6/Escape_T6Model.cpp
        Escape_T6/Escape_T6Controller.cpp
        Escape_T6/AppEscape_T6.cpp
)
target_link_directories(AppEscape_T6 PUBLIC
		${CMAKE_SOURCE_DIR}/include/ntrt
)
target_link_libraries(AppEscape_T6 PRIVATE
		ntrt::tgcreator
		ntrt::core
		ntrt::learning::Adapters
)

add_custom_command(TARGET AppEscape_T6 POST_BUILD
					COMMAND ln -sf Escape_T6/logs)
