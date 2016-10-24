#ifndef UTILS_H
#define UTILS_H

#include <vector>


namespace utils {
    void split(const std::string &s, char delim, std::vector<std::string> &elems);
    std::vector<std::string> split(const std::string &s, char delim);   
}


#endif