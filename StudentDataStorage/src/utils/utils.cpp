#include <sstream>
#include "utils.h"
#include "../data/entities/student.h"


namespace utils {
    void split(const std::string &s, char delim, std::vector<std::string> &elems) {
        std::stringstream ss;
        ss.str(s);
        std::string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }

    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }

    
}



