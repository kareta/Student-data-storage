#ifndef STUDENT_DAO_TEXT_H
#define STUDENT_DAO_TEXT_H

#include <memory>
#include "student_dao.h"
#include "../engine/database_engine.h"

namespace data { namespace dao {

    class StudentDaoText : public StudentDao {
        std::unique_ptr<engine::DatabaseEngine> databaseEngine;
        std::string tablePath;
        std::vector<std::pair<std::string, std::string>> columns;
    public:
        explicit StudentDaoText(const std::string& tablePath);
        virtual ~StudentDaoText() {};
        std::vector<entities::Student> findWhere(const std::string& propertyName, const std::string& value) override;
        std::vector<entities::Student> all() override;
        void save(const entities::Student& student) override;

        void saveUnsafe(const entities::Student& student) const;
        void closeUnsafeSaving() const;

        StudentDaoText& operator<<(entities::Student& student);
        StudentDaoText& operator >> (std::vector<entities::Student>& students);
    };

}}

#endif