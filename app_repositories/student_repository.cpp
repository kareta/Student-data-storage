#include "student_repository.h"

#include <sstream>
#include <app_exceptions/invalid_student_exception.h>

using namespace app_entities;
using namespace app_exceptions;

namespace app_repositories {

    StudentRepository::StudentRepository() : databaseEngine(), tablePath("C:\\Users\\vitya\\student") 
    {

        std::pair<std::string, std::string> name("name", "string");
        std::pair<std::string, std::string> surname("surname", "string");
        std::pair<std::string, std::string> height("height", "double");
        std::pair<std::string, std::string> weight("weight", "double");
        std::pair<std::string, std::string> studentCard("studentCard", "string");
        std::pair<std::string, std::string> passport("passport", "string");

        columns.push_back(name);
        columns.push_back(surname);
        columns.push_back(height);
        columns.push_back(weight);
        columns.push_back(studentCard);
        columns.push_back(passport);
    }

    std::vector<Student> StudentRepository::findWhere(const std::string& propertyName, const std::string& value)
    {
        std::vector<::Student> students;
        auto rows = databaseEngine.selectWhere(tablePath, propertyName, value);
        for (auto &row : rows)
        {
            try 
            {
                Student student(row);
                students.push_back(student);
            }
            catch (const InvalidStudentException& e) 
            {
                //write to log
            }
        }
        return students;
    }

    std::vector<Student> StudentRepository::all()
    {
        std::vector<Student> students;
        auto rows = databaseEngine.selectAll(tablePath);
        for (auto &row : rows)
        {
            try 
            {
                Student student(row);
                students.push_back(student);
            }
            catch (const InvalidStudentException& e) 
            {
                //write to log
            }

        }
        return students;
    }

    void StudentRepository::save(const Student& student)
    {
        databaseEngine.createIfNotExists(tablePath, columns);
        databaseEngine.insert(tablePath, student.toString());
    }


    StudentRepository& StudentRepository::operator<<(Student& student)
    {
        this->save(student);
        return *this;
    }

    StudentRepository& StudentRepository::operator>>(std::vector<::Student>& students)
    {
        students = this->all();
        return *this;
    }
}

