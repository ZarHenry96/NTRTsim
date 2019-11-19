find_library(LINEAR_MATH_LIB LinearMath)

add_library(MountainGoatNL2 MountainGoatNL2.cpp)
target_include_directories(MountainGoatNL2 PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(MountainGoatNL2 PRIVATE
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
		BaseQuadModelLearning
)

add_executable(AppMountainGoatNL2
    MountainGoatNL2.cpp
    AppMountainGoatNL2.cpp
)
target_include_directories(AppMountainGoatNL2 PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppMountainGoatNL2 PRIVATE
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
		BaseQuadModelLearning
)