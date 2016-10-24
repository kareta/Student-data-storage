#include "student_ui.h"

#include "../data/dao/student_dao_text.h"
#include "../data/entities/student.h"
#include "../utils/utils.h"
#include "../exceptions/invalid_student_exception.h"

#include <iostream>

namespace ui {

    void StudentUi::run() {
        std::string tablePath = "C:\\Users\\vitya\\student";
        data::dao::StudentDaoText dao(tablePath);
        std::vector<data::entities::Student> students;

        std::cout << "Students number to input: ";
        auto studentsNumber = 0;
        std::cin >> studentsNumber;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        inputStudentNTimes(dao, studentsNumber);
        dao >> students;
        auto numberOfIdealWight = data::entities::Student::getWithIdealWeight(students).size();
        std::cout << "There are " << numberOfIdealWight << " students with ideal weight\n\n";
        std::cout << "List of all students in the database:\n";
        std::cout << students;

        getchar();
    }

    void StudentUi::inputStudent(data::dao::StudentDaoText& dao) {
        data::entities::Student student;
        std::cin >> student;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        dao << student;
    }

    void StudentUi::inputStudentNTimes(data::dao::StudentDaoText& dao, const int& studentsNumber) {
        system("chcp 1251");
        std::cout << "Type student data\n";
        std::cout << "Format <name> <surname> <height> <weight> <identityCode> <passport>\n";
        for (auto i = 0; i < studentsNumber; i++) {
            try {
                inputStudent(dao);
            }
            catch (exceptions::InvalidStudentException& e) {
                std::cout << e.what() << "\n";
                std::cout << "Try another one\n";
            }
        }
    }
}
