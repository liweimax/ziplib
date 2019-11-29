#include "AStreamInclude.h"
#include "AFileStreamProvider.h"
#include <fstream>


FileStreamProvider::FileStreamProvider(const std::string& dir)
	:m_Directory(dir)
{

}

FileStreamProvider::~FileStreamProvider()
{

}

bool FileStreamProvider::LoadStream(const std::string& streamId, const LoadCallback& callback)
{
	auto filePath = m_Directory  + streamId;
    std::ifstream ifs(filePath);
    if (!ifs.is_open())
        return false;

	callback(ifs);

	return true;
}