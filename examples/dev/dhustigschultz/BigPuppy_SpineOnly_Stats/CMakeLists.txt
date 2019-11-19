find_library(LINEAR_MATH_LIB LinearMath)

list(APPEND BPSO_INCS
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/examples>
		$<INSTALL_INTERFACE:include>
		$<INSTALL_INTERFACE:examples>
		${BULLET_INCLUDE_DIRS}
)
list(APPEND BPSO_LIBS
		learningSpines
		ntrt::core
		ntrt::tgcreator
		${LINEAR_MATH_LIB}
)

add_library(BigPuppySpineOnlyStats BigPuppySpineOnlyStats.cpp)
target_include_directories(BigPuppySpineOnlyStats PUBLIC ${BPSO_INCS})
target_link_libraries(BigPuppySpineOnlyStats PRIVATE ${BPSO_LIBS})

add_library(BaseQuadModelLearning BaseQuadModelLearning.cpp)
target_include_directories(BaseQuadModelLearning PUBLIC ${BPSO_INCS})
target_link_libraries(BaseQuadModelLearning PRIVATE ${BPSO_LIBS})

add_executable(AppBigPuppySpineOnlyStats
    BigPuppySpineOnlyStats.cpp
    AppBigPuppySpineOnlyStats.cpp
    BaseQuadModelLearning.cpp
)
target_include_directories(AppBigPuppySpineOnlyStats PUBLIC ${BPSO_INCS})
target_link_libraries(AppBigPuppySpineOnlyStats PRIVATE ${BPSO_LIBS})