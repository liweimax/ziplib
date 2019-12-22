#pragma once
#include <cstdint>
#include <memory>
#include "ICompressionMethod.h"

#include "StoreMethod.h"
#include "DeflateMethod.h"
#ifdef _USE_BZIP2
#include "Bzip2Method.h"
#endif
#ifdef _USE_LZMA
#include "LzmaMethod.h"
#endif
#define ZIP_METHOD_TABLE          \
  ZIP_METHOD_ADD(StoreMethod);    \
  ZIP_METHOD_ADD(DeflateMethod);  \
  ZIP_METHOD_ADD(Bzip2Method);    \
  ZIP_METHOD_ADD(LzmaMethod);

#define ZIP_METHOD_ADD(method_class)                                                            \
  if (compressionMethod == method_class::GetZipMethodDescriptorStatic().GetCompressionMethod()) \
    return method_class::Create()

struct ZipMethodResolver
{
  static ICompressionMethod::Ptr GetZipMethodInstance(uint16_t compressionMethod)
  {
    ZIP_METHOD_ADD(StoreMethod);    
    ZIP_METHOD_ADD(DeflateMethod);  
#ifdef _USE_BZIP2
    ZIP_METHOD_ADD(Bzip2Method);   
#endif
#ifdef _USE_LZMA
    ZIP_METHOD_ADD(LzmaMethod);
#endif
    return ICompressionMethod::Ptr();
  }
};

#undef ZIP_METHOD
