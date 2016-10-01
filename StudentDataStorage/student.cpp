#include <sstream>
#include "student.h"
#include "utils.h"
#include "validator.h"
#include "invalid_student_exception.h"

const int Student::NUMBER_OF_PROPERTIES = 6;

Student::Student(
		const std::string& name, const std::string& surname, const double& height,
		const double& weight, const std::string& identityCard, const std::string& passport
) {
	setName(name);
	setSurname(surname);
	setHeight(height);
	setWeight(weight);
	setStudentCard(identityCard);
	setPassport(passport);
}

Student::Student() {
	setName("Noname");
	setSurname("Nosurname");
	setHeight(175);
	setWeight(70);
	setStudentCard("��00000000");
	setPassport("��000000");
}


void Student::operator=(const Student& student) {
	setName(student.getName());
	setSurname(student.getSurname());
	setHeight(student.getHeight());
	setWeight(student.getWeight());
	setStudentCard(student.getStudentCard());
	setPassport(student.getPassport());
}

std::string Student::getName() const {
	return name;
}

void Student::setName(const std::string& name) {
	
	if (!Validator::isNameCorrect(name)) {
		throw InvalidStudentException("Incorrect name");
	}
	this->name = name;
}

std::string Student::getSurname() const {
	return surname;
}

void Student::setSurname(const std::string& surname) {
	if (!Validator::isSurnameCorrect(surname)) {
		throw InvalidStudentException("Incorrect surname");
	}
	this->surname = surname;
}

double Student::getHeight() const {
	return height;
}

void Student::setHeight(const double& height) {
	if (!Validator::isHeightCorrect(height)) {
		throw InvalidStudentException("Incorrect height");
	}
	this->height = height;
}

double Student::getWeight() const {
	return weight;
}

void Student::setWeight(const double& weight) {
	if (!Validator::isWeightCorrect(weight)) {
		throw InvalidStudentException("Incorrect weight");
	}
	this->weight = weight;
}

std::string Student::getStudentCard() const {	
	return studentCard;
}

void Student::setStudentCard(const std::string& studentCard) {
	if (!Validator::isStudentCardCorrect(studentCard)) {
		throw InvalidStudentException("Incorrect identity card");
	}
	this->studentCard = studentCard;
}

std::string Student::getPassport() const {
	return passport;
}


void Student::setPassport(const std::string& passport) {
	if (!Validator::isPassportCorrect(passport)) {
		throw InvalidStudentException("Incorrect passport");
	}
	this->passport = passport;
}

std::ostream& operator<<(std::ostream& output, const Student& student) {
	output << "name: " << student.getName() << "\n";
	output << "surname: " << student.getSurname() << "\n";
	output << "height: " << student.getHeight() << "\n";
	output << "weight: " << student.getWeight() << "\n";
	output << "identity card: " << student.getStudentCard() << "\n";
	output << "passport: " << student.getPassport() << "\n\n";
	return output;
}

std::ostream& operator<<(std::ostream& output, const std::vector<Student>& students) {
	for (const auto &student : students) {
		output << student;
	}
	return output;
}

std::istream& operator>>(std::istream& input, Student& student) {
	std::string studentData;
	getline(input, studentData);
	student = Student::convertToStudent(studentData);
	return input;
}

std::vector<Student> Student::getWithIdealWeight(const std::vector<Student>& students) {
	std::vector<Student> withIdealWeight;
	for (const auto& student : students) {
		bool weightIsIdeal = (student.getHeight() - student.getWeight()) == 110;
		if (weightIsIdeal) {
			withIdealWeight.push_back(student);
		}
	}
	return withIdealWeight;
}

Student Student::convertToStudent(const std::string& row) {
	std::vector<std::string> values = split(row, ' ');	
	if (values.size() != NUMBER_OF_PROPERTIES) {
		throw InvalidStudentException("Incorrect string");
	}
	std::string name = values[0];
	std::string surname = values[1];
	double height = stod(values[2]);
	double weight = stod(values[3]);
	std::string studentCard = values[4];
	std::string passport = values[5];
	Student student(name, surname, height, weight, studentCard, passport);
	return student;
}

std::string Student::convertToString(const Student& student) {
	std::string row;
	std::ostringstream convertedHeightWeight;
	convertedHeightWeight << student.getHeight() << " " << student.getWeight();
	row.append(student.getName() + " ");
	row.append(student.getSurname() + " ");
	row.append(convertedHeightWeight.str() + " ");
	row.append(student.getStudentCard() + " ");
	row.append(student.getPassport());
	return row;
}