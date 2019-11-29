#pragma once

#include "AStreamProvider.h"

class STREAM_API FileStreamProvider 
	: public StreamProvider
{
public:
	explicit FileStreamProvider(const std::string& dir);
	virtual ~FileStreamProvider();

	virtual bool LoadStream(const std::string& streamId, const LoadCallback& callback) override;
private:
    std::string m_Directory;
};

