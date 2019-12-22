
project(ziplib-test)

INCLUDE_DIRECTORIES(
	${STREAM_SRC_DIR}/ziplib
    .
)

FILE(GLOB PROJECT_SRC *.cpp)
FILE(GLOB PROJECT_HEADER *.h)

add_executable(${PROJECT_NAME} ${PROJECT_SRC} ${PROJECT_HEADER})

add_dependencies(${PROJECT_NAME} ziplib)
target_link_libraries(${PROJECT_NAME} ziplib)
SET_PROPERTY(TARGET ziplib-test PROPERTY FOLDER "Zip/tool")