#pragma once

#include "AStreamProvider.h"
#include <vector>

class  STREAM_API ZipStreamProvider
	: public StreamProvider
{
protected:
	ZipStreamProvider() = default;

public:
	virtual ~ZipStreamProvider() = default;

    static ZipStreamProvider* Create();
public:
	bool Open(const std::string& fileName, bool readonly = true);
    bool Save();

public:
    bool LoadStream(const std::string& entryName, const LoadCallback& callback) override;
    std::vector<std::string> ListEntries();
public:
    bool AddFile(const std::string& entryName, const std::string& fileName);
    bool AddData(const std::string& entryName, const void* data, uint32_t length);
    bool AddData(const std::string& entryName, std::istream& stream);
private:
};



