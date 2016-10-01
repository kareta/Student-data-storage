#include <iostream>
#include "student.h"
#include "student_dao_text.h"
#include "invalid_student_exception.h"
#include "utils.h"

void main() {
	std::string tablePath = "C:\\Users\\vitya\\student";
	StudentDaoText dao(tablePath);
	std::vector<Student> students;

	std::cout << "Students number to input: ";
	auto studentsNumber = 0;
	std::cin >> studentsNumber;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	inputStudentNTimes(dao, studentsNumber);
	dao >> students;
	auto numberOfIdealWight = Student::getWithIdealWeight(students).size();
	std::cout << "There are " << numberOfIdealWight << " students with ideal weight\n\n";
	std::cout << "List of all students in the database:\n";
	std::cout << students;

	getchar();
}