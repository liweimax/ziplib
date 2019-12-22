
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

if(USE_EXTLIBS_ZLIB)
	add_dependencies(${PROJECT_NAME} zlib)
	target_link_libraries(${PROJECT_NAME} zlib)
endif(USE_EXTLIBS_ZLIB)
if(USE_EXTLIBS_BZIP2)
	add_dependencies(${PROJECT_NAME} bzip2)
	target_link_libraries(${PROJECT_NAME} bzip2)
endif(USE_EXTLIBS_BZIP2)
if(USE_EXTLIBS_LZMA)
	add_dependencies(${PROJECT_NAME} lzma)
	target_link_libraries(${PROJECT_NAME} lzma)
endif(USE_EXTLIBS_LZMA)

SET_PROPERTY(TARGET ${PROJECT_NAME} PROPERTY FOLDER "Zip")