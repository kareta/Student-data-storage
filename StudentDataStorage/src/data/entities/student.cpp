#include "student.h"

#include <sstream>

#include "../../validators/student_validator.h"
#include "../../exceptions/invalid_student_exception.h"
#include "../../utils/utils.h"

using namespace validators;
using namespace exceptions;
using namespace utils;

namespace data { namespace entities {

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
        setStudentCard("ÒÒ00000000");
        setPassport("ÀÀ000000");
    }

    Student::Student(const std::string& studentData) {
        auto values = split(studentData, ' ');
        if (values.size() != StudentValidator::NUMBER_OF_PROPERTIES) {
            throw InvalidStudentException("Incorrect string");
        }
        setName(values[0]);
        setSurname(values[1]);
        setHeight(std::stod(values[2]));
        setWeight(std::stod(values[3]));
        setStudentCard(values[4]);
        setPassport(values[5]);
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

        if (!StudentValidator::isNameCorrect(name)) {
            throw InvalidStudentException("Incorrect name");
        }
        this->name = name;
    }

    std::string Student::getSurname() const {
        return surname;
    }

    void Student::setSurname(const std::string& surname) {
        if (!StudentValidator::isSurnameCorrect(surname)) {
            throw InvalidStudentException("Incorrect surname");
        }
        this->surname = surname;
    }

    double Student::getHeight() const {
        return height;
    }

    void Student::setHeight(const double& height) {
        if (!StudentValidator::isHeightCorrect(height)) {
            throw InvalidStudentException("Incorrect height");
        }
        this->height = height;
    }

    double Student::getWeight() const {
        return weight;
    }

    void Student::setWeight(const double& weight) {
        if (!StudentValidator::isWeightCorrect(weight)) {
            throw InvalidStudentException("Incorrect weight");
        }
        this->weight = weight;
    }

    std::string Student::getStudentCard() const {
        return studentCard;
    }

    void Student::setStudentCard(const std::string& studentCard) {
        if (!StudentValidator::isStudentCardCorrect(studentCard)) {
            throw InvalidStudentException("Incorrect identity card");
        }
        this->studentCard = studentCard;
    }

    std::string Student::getPassport() const {
        return passport;
    }


    void Student::setPassport(const std::string& passport) {
        if (!StudentValidator::isPassportCorrect(passport)) {
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

    std::istream& operator >> (std::istream& input, Student& student) {
        std::string studentData;
        getline(input, studentData);
        Student studentFromString(studentData);
        student = studentFromString;
        return input;
    }

    std::string Student::toString() const {
        std::string row;
        std::ostringstream convertedHeightWeight;
        convertedHeightWeight << getHeight() << " " << getWeight();
        row.append(getName() + " ");
        row.append(getSurname() + " ");
        row.append(convertedHeightWeight.str() + " ");
        row.append(getStudentCard() + " ");
        row.append(getPassport());
        return row;
    }
}}

