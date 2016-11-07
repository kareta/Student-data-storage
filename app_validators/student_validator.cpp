#include <regex>
#include "student_validator.h"
#include <app_exceptions/invalid_student_exception.h>
#include "utils/utils.h"


using namespace app_exceptions;

namespace app_validators {

    const int StudentValidator::NUMBER_OF_PROPERTIES = 6;
    const std::string StudentValidator::NAME_PATTERN = "^[a-zA-Z]+$";
    const std::string StudentValidator::PASSPORT_PATTERN = "^[A-Z]{2}\\d{6}$";
    const std::string StudentValidator::STUDENT_CARD_PATTERN = "^[A-Z]{2}\\d{8}$";
    const double StudentValidator::MIN_HEIGHT = 30;
    const double StudentValidator::MAX_HEIGHT = 300;
    const double StudentValidator::MIN_WEIGHT = 2;
    const double StudentValidator::MAX_WEIGHT = 1000;

    void StudentValidator::dataIsCorrect(const std::string& studentData) 
    {
        auto values = utils::split(studentData, ' ');
        if (values.size() != NUMBER_OF_PROPERTIES) {
            throw InvalidStudentException("Incorrect string");
        }
        nameIsCorrect(values[0]);
        surnameIsCorrect(values[1]);
        heightIsCorrect(stod(values[2]));
        weightIsCorrect(stod(values[3]));
        studentCardIsCorrect(values[4]);
        passportIsCorrect(values[5]);
    }

    void StudentValidator::passportIsCorrect(const std::string& passport) 
    {
        std::regex expression(PASSPORT_PATTERN);
        if (!std::regex_match(passport, expression)) 
        {
            throw InvalidStudentException("Incorrect passport");
        }
    }

    void StudentValidator::studentCardIsCorrect(const std::string& studentCard) 
    {
        std::regex expression(STUDENT_CARD_PATTERN);
        if (!std::regex_match(studentCard, expression)) 
        {
            throw InvalidStudentException("Incorrect student card");
        }
    }

    void StudentValidator::nameIsCorrect(const std::string& name) 
    {
        std::regex expression(NAME_PATTERN);
        if (!std::regex_match(name, expression)) 
        {
            throw InvalidStudentException("Incorrect name");
        }
    }

    void StudentValidator::surnameIsCorrect(const std::string& surname) 
    {
        std::regex expression(NAME_PATTERN);
        if (!std::regex_match(surname, expression)) 
        {
            throw InvalidStudentException("Incorrect surname");
        }
    }

    void StudentValidator::weightIsCorrect(double weight) 
    {
        if (weight <= MIN_WEIGHT || weight >= MAX_WEIGHT) 
        {
            throw InvalidStudentException("Incorrect weight");
        }
    }

    void StudentValidator::heightIsCorrect(double height) 
    {
        if (height <= MIN_HEIGHT || height >= MAX_HEIGHT) 
        {
            throw InvalidStudentException("Incorrect height");
        }
    }
}

