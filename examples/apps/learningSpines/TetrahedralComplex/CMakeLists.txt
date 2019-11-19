
find_library(LINEAR_MATH_LIB LinearMath)

list(APPEND LIBS_TetrahedralComplex
		learningSpines
		ntrt::sensors
		ntrt::tgcreator
		ntrt::core
		ntrt::util
		ntrt::terrain
		ntrt::learning::Adapters
		ntrt::learning::Configuration
		ntrt::learning::AnnealEvolution
		ntrt::tgOpenGLSupport
		${LINEAR_MATH_LIB}
)

add_library(TetrahedralComplex FlemonsSpineModelLearning.cpp)
target_include_directories(TetrahedralComplex PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${Boost_INCLUDE_DIRS}
)
target_link_libraries(TetrahedralComplex PRIVATE ${LIBS_TetrahedralComplex})

add_executable(AppFlemonsSpineLearning
		FlemonsSpineModelLearning.cpp
        AppFlemonsSpineLearning.cpp
)
target_include_directories(AppFlemonsSpineLearning PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${Boost_INCLUDE_DIRS}
)
target_link_libraries(AppFlemonsSpineLearning PRIVATE ${LIBS_TetrahedralComplex})
