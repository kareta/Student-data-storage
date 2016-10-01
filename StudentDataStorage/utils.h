#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include "student_dao_text.h"

void split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);

void inputStudent(StudentDaoText& dao);
void inputStudentNTimes(StudentDaoText& dao, const int& studentsNumber);

#endif