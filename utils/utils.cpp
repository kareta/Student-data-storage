#include <sstream>
#include "utils.h"


namespace utils 
{
    void split(const std::string &splittedString, char delimiter, std::vector<std::string> &elements) 
    {
        std::stringstream stringStream;
        stringStream.str(splittedString);
        std::string item;
        while (getline(stringStream, item, delimiter)) 
        {
            elements.push_back(item);
        }
    }

    std::vector<std::string> split(const std::string &splittedString, char delimiter) 
    {
        std::vector<std::string> elements;
        split(splittedString, delimiter, elements);
        return elements;
    }    
}



