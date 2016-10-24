#ifndef INVALID_STUDENT_EXCEPTION_H
#define INVALID_STUDENT_EXCEPTION_H

#include <string>
#include "exception.h"

namespace exceptions {
    class InvalidStudentException : public Exception {
    public:

        explicit InvalidStudentException(const std::string& message) : Exception(message) {}
        virtual ~InvalidStudentException() {}
    };
}



#endif