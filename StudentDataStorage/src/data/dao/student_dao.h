#ifndef STUDENT_DAO_H
#define STUDENT_DAO_H

#include <vector>
#include "../entities/student.h"

namespace data { namespace dao {
    class StudentDao {
    public:
        virtual ~StudentDao() {}
        virtual std::vector<entities::Student> findWhere(const std::string& propertyName, const std::string& value) = 0;
        virtual std::vector<entities::Student> all() = 0;
        virtual void save(const entities::Student& student) = 0;
    };
}}



#endif