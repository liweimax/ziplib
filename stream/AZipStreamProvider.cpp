#include "AStreamInclude.h"
#include "AZipStreamProvider.h"

#include "ZipFile.h"
#include "streams/memstream.h"

#include <fstream>
#include <sstream>



class ZipStreamProviderImpl : public ZipStreamProvider
{
public:
    ZipStreamProviderImpl() = default;

    bool Open(const std::string& fileName, bool readonly)
    {
        m_ReadOnly = readonly;
        m_FileName = fileName;
        try
        {
            m_Archive = ZipFile::Open(fileName);
        }
        catch (...)
        {
            return false;
        }

        return true;
    }
    bool LoadStream(const std::string& streamId, const LoadCallback& callback)
    {
        ZipArchiveEntry::Ptr entry = m_Archive->GetEntry(streamId);
        if (!entry)
            return false;

        auto pStream = entry->GetDecompressionStream();
        if (!pStream)
            return false;

        callback(*pStream);

        return true;
    }
    bool Save()
    {
        if (m_ReadOnly)
            return true;

        ZipFile::SaveAndClose(m_Archive, m_FileName);
        return true;
    }

    bool AddFile(const std::string& entityName, const std::string& fileName)
    {
        std::ifstream ifs(fileName, std::ios::binary);
        if (!ifs)
            return false;

  
        return AddData(entityName, ifs);
    }

    bool AddData(const std::string& entityName, std::istream& stream)
    {
        ZipArchiveEntry::Ptr entry = m_Archive->CreateEntry(entityName);
        if (!entry)
            return false;

        DeflateMethod::Ptr ctx = DeflateMethod::Create();
        ctx->SetCompressionLevel(DeflateMethod::CompressionLevel::L1);

        entry->SetCompressionStream( 
            stream,
            ctx,
            ZipArchiveEntry::CompressionMode::Immediate
        );

        return true;
    }

    std::vector<std::string> ListEntries()
    {
        std::vector<std::string> names;
        size_t entries = m_Archive->GetEntriesCount();
        if (entries == 0)
            return std::move(names);
        names.reserve(entries);
        for (size_t i = 0; i < entries; ++i)
        {
            auto entry = m_Archive->GetEntry(int(i));
            names.push_back(entry->GetFullName());
        }
        return std::move(names);
    }
private:
    ZipArchive::Ptr m_Archive;
    char* m_Buffer = 0;
    bool m_ReadOnly = true;
    std::string m_FileName;
};

#define Impl dynamic_cast<ZipStreamProviderImpl*>(this)

ZipStreamProvider* ZipStreamProvider::Create()
{
    return new ZipStreamProviderImpl();
}

bool ZipStreamProvider::Open(const std::string& fileName, bool readonly)
{
    return Impl->Open(fileName, readonly);
}

bool ZipStreamProvider::LoadStream(const std::string& streamId, const LoadCallback& callback)
{
	return Impl->LoadStream(streamId, callback);
}

bool ZipStreamProvider::Save()
{
    return Impl->Save();
}

bool ZipStreamProvider::AddFile(const std::string& entityName, const std::string& fileName)
{
    return Impl->AddFile(entityName, fileName);
}
bool ZipStreamProvider::AddData(const std::string& entityName, const void* data, uint32_t length)
{
    imemstream mss((char*)data, length);
    return Impl->AddData(entityName, mss);
}

bool ZipStreamProvider::AddData(const std::string& entityName, std::istream& stream)
{
    return Impl->AddData(entityName, stream);
}

std::vector<std::string> ZipStreamProvider::ListEntries()
{
    return std::move(Impl->ListEntries());
}