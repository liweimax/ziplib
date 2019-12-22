#include "AStreamInclude.h"

#include "AZipStreamProvider.h"
#include <memory>
#include <iostream>

int main()
{

    // write
    {
         std::unique_ptr<ZipStreamProvider> zip(ZipStreamProvider::Create());
        zip->Open("hello.zip", false);
        std::string message = R"(
            Today is a good day!
            https://github.com/liweimax/ziplib!
        )";
        zip->AddFile("zlib.lib", "zlib.lib");
        zip->AddData("pass/user.txt", message.data(), message.length());
        zip->Save();
    }
    // read
    {
        std::unique_ptr<ZipStreamProvider> zip(ZipStreamProvider::Create());
        zip->Open("hello.zip", true);
        for (auto entry : zip->ListEntries())
        {
            std::cout << entry << std::endl;
        }
        zip->LoadStream("pass/user.txt", [](std::istream& iss) {
            std::cout << iss.rdbuf();
            });
    }

  return 0;
}
