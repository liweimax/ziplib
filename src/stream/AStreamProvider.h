#pragma once

#include <string>
#include <functional>

class  STREAM_API StreamProvider
{
public:
	StreamProvider();
	virtual ~StreamProvider();
    typedef std::function<void(std::istream&)> LoadCallback;
	virtual bool LoadStream(const std::string& streamId, const LoadCallback& callback) = 0;
private:
};


