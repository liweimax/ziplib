project(lzma C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
endif()

FILE(GLOB lzma_SRCS *.c)
FILE(GLOB lzma_HEADER *.h)

add_library(lzma STATIC ${lzma_SRCS} ${lzma_HEADER})
SET_PROPERTY(TARGET ${PROJECT_NAME}  PROPERTY FOLDER "Zip/extlibs")