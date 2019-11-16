find_library(LINEAR_MATH_LIB LinearMath)

add_library(MountainGoat MountainGoat.cpp)
target_include_directories(MountainGoat PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
		)
target_link_libraries(MountainGoat PRIVATE
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
		BaseQuadModelLearning
)


add_executable(AppMountainGoat
		MountainGoat.cpp
    	AppMountainGoat.cpp
)
target_include_directories(AppMountainGoat PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppMountainGoat PRIVATE
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
		BaseQuadModelLearning
)