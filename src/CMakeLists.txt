
project(ziplib)

INCLUDE_DIRECTORIES(
    .
)




if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)

endif()

FILE(GLOB PROJECT_SRC *.cpp)
FILE(GLOB PROJECT_SRC ${PROJECT_SRC} detail/*.cpp)
FILE(GLOB PROJECT_HEADER *.h)

add_library(${PROJECT_NAME} STATIC ${PROJECT_SRC} ${PROJECT_HEADER})

add_dependencies(${PROJECT_NAME} zlib bzip2 lzma)
target_link_libraries(${PROJECT_NAME} zlib bzip2 lzma)