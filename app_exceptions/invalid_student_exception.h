#ifndef INVALID_STUDENT_EXCEPTION_H
#define INVALID_STUDENT_EXCEPTION_H

#include "exceptions/exception.h"

namespace app_exceptions {
    class InvalidStudentException : public exceptions::Exception {
    public:

        explicit InvalidStudentException(const std::string& message) : Exception(message) {}
        virtual ~InvalidStudentException() {}
    };
}



#endif