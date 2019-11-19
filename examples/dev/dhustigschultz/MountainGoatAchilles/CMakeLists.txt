find_library(LINEAR_MATH_LIB LinearMath)

add_library(MountainGoatAchilles MountainGoatAchilles.cpp)
target_include_directories(MountainGoatAchilles PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(MountainGoatAchilles PRIVATE
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
		BaseQuadModelLearning
)

add_executable(AppMountainGoatAchilles
		MountainGoatAchilles.cpp
		AppMountainGoatAchilles.cpp
)
target_include_directories(AppMountainGoatAchilles PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppMountainGoatAchilles PRIVATE
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
		BaseQuadModelLearning
)