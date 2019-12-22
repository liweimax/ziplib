
project(stream-test)

INCLUDE_DIRECTORIES(
	${STREAM_SRC_DIR}/stream
    .
)

FILE(GLOB PROJECT_SRC *.cpp)
FILE(GLOB PROJECT_HEADER *.h)

add_executable(${PROJECT_NAME} ${PROJECT_SRC} ${PROJECT_HEADER})

add_dependencies(${PROJECT_NAME} ${STREAM_PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} ${STREAM_PROJECT_NAME})
SET_PROPERTY(TARGET stream-test PROPERTY FOLDER "Zip/tool")