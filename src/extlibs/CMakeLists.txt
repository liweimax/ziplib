
if(USE_EXTLIBS_ZLIB)
    add_subdirectory(zlib)
endif(USE_EXTLIBS_ZLIB)

if(USE_EXTLIBS_BZIP2)
    add_subdirectory(bzip2)
endif(USE_EXTLIBS_BZIP2)

if(USE_EXTLIBS_LZMA)
    add_subdirectory(lzma)
endif(USE_EXTLIBS_LZMA)