#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

namespace exceptions {
    class Exception : public std::exception
    {
    public:
        explicit Exception(const char* message) : message(message) {}
        explicit Exception(const std::string& message) : message(message) {}
        virtual ~Exception() {}

        /** Returns a pointer to the (constant) error description.
        *  @return A pointer to a const char*. The underlying memory
        *          is in posession of the Exception object. Callers must
        *          not attempt to free the memory.
        */
        virtual const char* what() const {
            return message.c_str();
        }

    protected:
        /** Error message.
        */
        std::string message;
    };
}



#endif