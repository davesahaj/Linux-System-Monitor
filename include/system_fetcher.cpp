#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

#include "system_fetcher.h"

std::string SystemFetcher::operating_system()
{
    std::string line;
    std::string key;//can use
    std::string value;// maps?

    std::string path{"/etc/os-release"};
    std::ifstream fileStream(path);

    if (fileStream.is_open())
    {
        while (getline(fileStream, line))
        {
            replace(line.begin(), line.end(), ' ', '_');
            replace(line.begin(), line.end(), '=', ' ');
            replace(line.begin(), line.end(), '"', ' ');
            std::istringstream lineStream(line);

            // std::cout << line << std::endl;
        }

        fileStream.close();
    }

    else
    {
        std::cout << "cannot open file for some reason." << std::endl;
    }

    return "done";
}

int main()
{
    std::cout << "asd";
    SystemFetcher::operating_system();
}