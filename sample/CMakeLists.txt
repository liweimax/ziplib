
project(sample)

INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/src
    .
)

FILE(GLOB PROJECT_SRC *.cpp)
FILE(GLOB PROJECT_HEADER *.h)

add_executable(${PROJECT_NAME} ${PROJECT_SRC} ${PROJECT_HEADER})

add_dependencies(${PROJECT_NAME} ziplib)
target_link_libraries(${PROJECT_NAME} ziplib)
SET_PROPERTY(TARGET ${PROJECT_NAME}  PROPERTY FOLDER "tool")