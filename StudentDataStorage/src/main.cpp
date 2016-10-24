#include <iostream>
#include "data/entities/student.h"
#include "data/dao/student_dao_text.h"
#include "utils/utils.h"



void main() {
    std::string tablePath = "C:\\Users\\vitya\\student";
    data::dao::StudentDaoText dao(tablePath);
    std::vector<data::entities::Student> students;

    std::cout << "Students number to input: ";
    auto studentsNumber = 0;
    std::cin >> studentsNumber;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    utils::inputStudentNTimes(dao, studentsNumber);
    dao >> students;
    auto numberOfIdealWight = data::entities::Student::getWithIdealWeight(students).size();
    std::cout << "There are " << numberOfIdealWight << " students with ideal weight\n\n";
    std::cout << "List of all students in the database:\n";
    std::cout << students;

    getchar();
}
