#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <fstream>

namespace utils {
    void split(const std::string &splittedString, char delimiter, std::vector<std::string> &elements);
    std::vector<std::string> split(const std::string &splittedString, char delimiter);   

    inline bool fileExists(const std::string& fileName)
    {
        std::ifstream file(fileName);
        return file.good();
    }
}


#endif