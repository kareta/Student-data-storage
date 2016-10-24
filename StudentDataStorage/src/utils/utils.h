#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include "../data/dao/student_dao_text.h"

namespace utils {
    void split(const std::string &s, char delim, std::vector<std::string> &elems);
    std::vector<std::string> split(const std::string &s, char delim);

    void inputStudent(data::dao::StudentDaoText& dao);
    void inputStudentNTimes(data::dao::StudentDaoText& dao, const int& studentsNumber);
}


#endif