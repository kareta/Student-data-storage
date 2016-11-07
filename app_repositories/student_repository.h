#ifndef STUDENT_REPOSITORY_H
#define STUDENT_REPOSITORY_H

#include "i_student_repository.h"
#include "storage/database_engine.h"

using namespace app_entities;
using namespace storage;

namespace app_repositories 
{

    class StudentRepository : public IStudentRepository 
    {
        DatabaseEngine databaseEngine;
        std::string tablePath;
        std::vector<std::pair<std::string, std::string>> columns;
    public:
        explicit StudentRepository();
        std::vector<Student> findWhere(const std::string& propertyName, const std::string& value) override;
        std::vector<Student> all() override;
        void save(const Student& student) override;

        StudentRepository& operator<<(Student& student);
        StudentRepository& operator>>(std::vector<Student>& students);
    };

}

#endif