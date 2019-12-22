#pragma once

#ifdef WIN32
    #ifdef _STREAM_BUILD_STATIC
        #define STREAM_API
    #else
        #ifdef Stream_EXPORTS
            #define STREAM_API __declspec(dllexport)
         #else
            #define STREAM_API __declspec(dllimport)
        #endif 
    #endif
    #pragma warning( disable: 4251 )
#else
    #define STREAM_API
#endif
