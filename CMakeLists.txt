cmake_minimum_required(VERSION 3.5)

project(ZipStream)

option( BUILD_TOOLS "Build Tools" ON )

set(STREAM_PROJECT_NAME "ZipStream")
set(STREAM_SRC_DIR ${CMAKE_SOURCE_DIR})

if(MSVC)
	set(OUT_VERSION "${CMAKE_SYSTEM_NAME}/${CMAKE_VS_PLATFORM_TOOLSET}/${PlatformName}")
else(MSVC)
	set(OUT_VERSION "${CMAKE_SYSTEM_NAME}/${PlatformName}")
endif(MSVC)
set (OUTPUT_DIR "${CMAKE_SOURCE_DIR}/bin/${OUT_VERSION}")

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY  ${OUTPUT_DIR})
set(CMAKE_PDB_OUTPUT_DIRECTORY  ${OUTPUT_DIR})	
SET(EXECUTABLE_OUTPUT_PATH ${OUTPUT_DIR})
SET(LIBRARY_OUTPUT_PATH ${OUTPUT_DIR})

add_subdirectory(src)
