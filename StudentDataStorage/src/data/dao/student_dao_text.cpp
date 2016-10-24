#include "student_dao_text.h"
#include <sstream>
#include "../../exceptions/invalid_student_exception.h"

namespace data { namespace dao {

    StudentDaoText::StudentDaoText(const std::string& tablePath)
        : databaseEngine(new engine::DatabaseEngine), tablePath(tablePath) {

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

    std::vector<entities::Student> StudentDaoText::findWhere(const std::string& propertyName, const std::string& value) {
        std::vector<entities::Student> students;
        auto rows = databaseEngine->selectWhere(tablePath, propertyName, value);
        for (auto &row : rows)
        {
            try {
                students.push_back(entities::Student::convertToStudent(row));
            }
            catch (const exceptions::InvalidStudentException& e) {

            }
        }
        return students;
    }

    std::vector<entities::Student> StudentDaoText::all() {
        std::vector<entities::Student> students;
        auto rows = databaseEngine->selectAll(tablePath);
        for (auto &row : rows)
        {
            try {
                students.push_back(entities::Student::convertToStudent(row));
            }
            catch (const exceptions::InvalidStudentException& e) {

            }

        }
        return students;
    }

    void StudentDaoText::save(const entities::Student& student) {
        databaseEngine->createIfNotExists(tablePath, columns);
        databaseEngine->insert(tablePath, entities::Student::convertToString(student));
    }

    void StudentDaoText::saveUnsafe(const entities::Student& student) const
    {
        databaseEngine->createIfNotExists(tablePath, columns);
        databaseEngine->insertUnsafe(tablePath, entities::Student::convertToString(student));
    }

    void StudentDaoText::closeUnsafeSaving() const
    {
        databaseEngine->closeUnsafe();
    }

    StudentDaoText& StudentDaoText::operator<<(entities::Student& student) {
        this->save(student);
        return *this;
    }

    StudentDaoText& StudentDaoText::operator >> (std::vector<entities::Student>& students) {
        students = this->all();
        return *this;
    }
}}

