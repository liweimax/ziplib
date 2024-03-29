cmake_minimum_required(VERSION 3.5)

project(ZipStream)

option( BUILD_ZIP "Build ZIP" ON )
option( BUILD_BZIP2 "Build BZIP" ON )
option( BUILD_LZMA "Build LZMA" ON )

IF(BUILD_ZIP)
    FIND_PACKAGE(ZLIB)
    IF(ZLIB_FOUND)
        INCLUDE_DIRECTORIES(${ZLIB_INCLUDE_DIR})
    ELSE()
        SET (USE_EXTLIBS_ZLIB 1)
        MESSAGE(WARNING "-- zlib library not found; use extlibs/zlib instead.")
        INCLUDE_DIRECTORIES(${STREAM_SRC_DIR}/extlibs/zlib)
        INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/extlibs/zlib)
    ENDIF(ZLIB_FOUND)
ENDIF(BUILD_ZIP)

IF(BUILD_BZIP2)
	add_definitions(-D_USE_BZIP2)
    FIND_PACKAGE(BZip2)
	    SET (USE_EXTLIBS_BZIP2 1)
    IF(BZIP2_FOUND)
        INCLUDE_DIRECTORIES(${BZIP2_INCLUDE_DIR})
    ELSE()
        MESSAGE(WARNING "-- bzip2 library not found; use extlibs/bzip2 instead.")
        INCLUDE_DIRECTORIES(${STREAM_SRC_DIR}/extlibs/bzip2)
    ENDIF(BZIP2_FOUND)
ENDIF(BUILD_BZIP2)

IF(BUILD_LZMA)
    SET (USE_EXTLIBS_LZMA 1)
	add_definitions(-D_USE_LZMA)
    MESSAGE(WARNING "-- bzip2 library not found; use extlibs/bzip2 instead.")
    INCLUDE_DIRECTORIES(${STREAM_SRC_DIR}/extlibs/lzma)
ENDIF(BUILD_LZMA)

add_subdirectory(extlibs)
add_subdirectory(ziplib)
add_subdirectory(stream)

if(BUILD_TOOLS)
	add_subdirectory(sample)
endif(BUILD_TOOLS)