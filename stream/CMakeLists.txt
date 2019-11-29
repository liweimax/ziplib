
project(${STREAM_PROJECT_NAME})

INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/ziplib
	.
)

add_definitions(-DStream_EXPORTS)

FILE(GLOB PROJECT_SRC *.cpp)
FILE(GLOB PROJECT_HEADER *.h)

add_library(${PROJECT_NAME} SHARED ${PROJECT_SRC} ${PROJECT_HEADER})

add_dependencies(${PROJECT_NAME} ziplib)
target_link_libraries(${PROJECT_NAME} ziplib)