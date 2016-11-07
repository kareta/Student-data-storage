#ifndef STUDENT_SERVICE_H
#define STUDENT_SERVICE_H

#include <app_entities/student.h>
#include <app_validators/student_validator.h>
#include <app_exceptions/invalid_student_exception.h>
#include <utils/utils.h>
#include "app_repositories/student_repository.h"

using namespace app_entities;
using namespace app_validators;
using namespace app_exceptions;
using namespace app_repositories;

namespace app_services 
{

    class StudentService 
    {
        StudentRepository studentRepository;
    public:
        explicit StudentService();

        void store(Student& student);
        void storeFromString(const std::string& studentData);

        Student studentFromString(const std::string& studentData) const;

        std::vector<Student> allStudents();

        std::vector<Student> withIdealWeight();
        int numberWithIdealWeight();

        std::string allStudentsToString();
    };
}

#endif