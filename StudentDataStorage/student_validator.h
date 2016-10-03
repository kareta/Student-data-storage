#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

class StudentValidator {
public:

    virtual ~StudentValidator() {}

    static const int NUMBER_OF_PROPERTIES;
    static const std::string NAME_PATTERN;
    static const std::string PASSPORT_PATTERN;
    static const std::string STUDENT_CARD_PATTERN;
    static const double MIN_HEIGHT;
    static const double MAX_HEIGHT;
    static const double MIN_WEIGHT;
    static const double MAX_WEIGHT;

    static bool isPassportCorrect(const std::string& passport);
    static bool isStudentCardCorrect(const std::string& studentCard);   
    static bool isNameCorrect(const std::string& name);
    static bool isSurnameCorrect(const std::string& surname);
    static bool isWeightCorrect(const double& weight);
    static bool isHeightCorrect(const double& height);
};

#endif