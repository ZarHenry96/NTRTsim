find_library(LINEAR_MATH_LIB LinearMath)

add_library(MountainGoatFM0 MountainGoatFM0.cpp)
target_include_directories(MountainGoatFM0 PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(MountainGoatFM0 PRIVATE
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
		BaseQuadModelLearning
)

add_executable(AppMountainGoatFM0
    MountainGoatFM0.cpp
    AppMountainGoatFM0.cpp
)
target_include_directories(AppMountainGoatFM0 PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppMountainGoatFM0 PRIVATE
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
		BaseQuadModelLearning
)