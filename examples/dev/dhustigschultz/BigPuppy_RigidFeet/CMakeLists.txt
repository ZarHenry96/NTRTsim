find_library(LINEAR_MATH_LIB LinearMath)

add_library(BigPuppyRigidFeet BigPuppyRigidFeet.cpp)
target_include_directories(BigPuppyRigidFeet PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(BigPuppyRigidFeet PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)

add_executable(AppBigPuppyRigidFeet
    BigPuppyRigidFeet.cpp
    AppBigPuppyRigidFeet.cpp
)
target_include_directories(AppBigPuppyRigidFeet PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/examples>
		${BULLET_INCLUDE_DIRS}
)
target_link_libraries(AppBigPuppyRigidFeet PRIVATE
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)