#include <sstream>
#include "utils.h"
#include <iostream>
#include "../data/entities/student.h"
#include "../exceptions/invalid_student_exception.h"

namespace utils {
    void split(const std::string &s, char delim, std::vector<std::string> &elems) {
        std::stringstream ss;
        ss.str(s);
        std::string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
    }

    std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }

    void inputStudent(data::dao::StudentDaoText& dao) {
        data::entities::Student student;
        std::cin >> student;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        dao << student;
    }

    void inputStudentNTimes(data::dao::StudentDaoText& dao, const int& studentsNumber) {
        system("chcp 1251");
        std::cout << "Type student data\n";
        std::cout << "Format <name> <surname> <height> <weight> <identityCode> <passport>\n";
        for (auto i = 0; i < studentsNumber; i++) {
            try {
                utils::inputStudent(dao);
            }
            catch (exceptions::InvalidStudentException& e) {
                std::cout << e.what() << "\n";
                std::cout << "Try another one\n";
            }
        }
    }
}



