#ifndef STUDENT_DAO_H
#define STUDENT_DAO_H

#include <vector>
#include <string>
#include "student.h"

class StudentDao {
public:
    virtual ~StudentDao() {}
    virtual std::vector<Student> findWhere(const std::string& propertyName, const std::string& value) = 0;
    virtual std::vector<Student> all() = 0;
    virtual void save(const Student& student) = 0;
};

#endif