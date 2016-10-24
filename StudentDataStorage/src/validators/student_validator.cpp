#include <regex>
#include "student_validator.h"

namespace validators {

    const int StudentValidator::NUMBER_OF_PROPERTIES = 6;
    const std::string StudentValidator::NAME_PATTERN = "^[a-zA-ZА-Яа-яàáâäãåąčćęèéêëėįìíîïłńòóôöõøùúûüųūÿýżźñçčšžÀÁÂÄÃÅĄĆČĖĘÈÉÊËÌÍÎÏĮŁŃÒÓÔÖÕØÙÚÛÜŲŪŸÝŻŹÑßÇŒÆČŠŽ∂ð,.'-]+$";
    const std::string StudentValidator::PASSPORT_PATTERN = "^[АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦШЧЩЬЮЯ]{2}\\d{6}$";
    const std::string StudentValidator::STUDENT_CARD_PATTERN = "^[АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦШЧЩЬЮЯ]{2}\\d{8}$";
    const double StudentValidator::MIN_HEIGHT = 30;
    const double StudentValidator::MAX_HEIGHT = 300;
    const double StudentValidator::MIN_WEIGHT = 2;
    const double StudentValidator::MAX_WEIGHT = 1000;

    bool StudentValidator::isPassportCorrect(const std::string& passport) {
        std::regex expression(PASSPORT_PATTERN);
        return std::regex_match(passport, expression);
    }

    bool StudentValidator::isStudentCardCorrect(const std::string& studentCard) {
        std::regex expression(STUDENT_CARD_PATTERN);
        return std::regex_match(studentCard, expression);
    }

    bool StudentValidator::isNameCorrect(const std::string& name) {
        std::regex expression(NAME_PATTERN);
        return std::regex_match(name, expression);
    }

    bool StudentValidator::isSurnameCorrect(const std::string& surname) {
        std::regex expression(NAME_PATTERN);
        return std::regex_match(surname, expression);
    }

    bool StudentValidator::isWeightCorrect(const double& weight) {
        return weight >= MIN_WEIGHT && weight <= MAX_WEIGHT;
    }

    bool StudentValidator::isHeightCorrect(const double& height) {
        return height >= MIN_HEIGHT && height <= MAX_HEIGHT;
    }
}

