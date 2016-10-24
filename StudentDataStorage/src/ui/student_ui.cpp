#include "student_ui.h"

#include "../data/dao/student_dao_text.h"
#include "../data/entities/student.h"
#include "../exceptions/invalid_student_exception.h"

#include <iostream>

namespace ui {

    void StudentUi::run() {     
        std::cout << "Students number to input: ";
        auto studentsNumber = 0;
        std::cin >> studentsNumber;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        inputStudentNTimes(studentsNumber);

        auto numberWithIdealWeight = studentService.numberWithIdealWeight();

        std::cout << "There are " << numberWithIdealWeight << " students with ideal weight\n\n";
        std::cout << "List of all students in the database:\n";
        std::cout << studentService.allStudentsToString();

        getchar();
    }

    void StudentUi::inputStudent() {
        std::string studentData;
        std::cin >> studentData;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        studentService.storeFromString(studentData);
    }

    void StudentUi::inputStudentNTimes(const int& studentsNumber) {
        system("chcp 1251");
        std::cout << "Type student data\n";
        std::cout << "Format <name> <surname> <height> <weight> <identityCode> <passport>\n";
        for (auto i = 0; i < studentsNumber; i++) {
            try {
                inputStudent();
            }
            catch (exceptions::InvalidStudentException& e) {
                std::cout << e.what() << "\n";
                std::cout << "Try another one\n";
            }
        }
    }
}
