
project(${STREAM_PROJECT_NAME})

INCLUDE_DIRECTORIES(
    ${STREAM_SRC_DIR}/ziplib
	.
)

add_definitions(-DStream_EXPORTS)

FILE(GLOB PROJECT_SRC *.cpp)
FILE(GLOB PROJECT_HEADER *.h)

add_library(${PROJECT_NAME} SHARED ${PROJECT_SRC} ${PROJECT_HEADER})

add_dependencies(${PROJECT_NAME} ziplib)
target_link_libraries(${PROJECT_NAME} ziplib)

SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Zip")