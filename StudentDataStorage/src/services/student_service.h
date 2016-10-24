#ifndef STUDENT_SERVICE_H
#define STUDENT_SERVICE_H

#include "../data/dao/student_dao_text.h"
#include "../validators/student_validator.h"
#include "../exceptions/invalid_student_exception.h"
#include "../utils/utils.h"

#include <string>

using namespace validators;
using namespace exceptions;
using namespace utils;

using namespace data::dao;

using namespace data::entities;

namespace services {

    class StudentService {
        StudentDaoText studentDao;
    public:
        StudentService();

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