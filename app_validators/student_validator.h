#ifndef VALIDATOR_H
#define VALIDATOR_H

namespace app_validators 
{

    class StudentValidator 
    {
    public:

        static const int NUMBER_OF_PROPERTIES;
        static const std::string NAME_PATTERN;
        static const std::string PASSPORT_PATTERN;
        static const std::string STUDENT_CARD_PATTERN;
        static const double MIN_HEIGHT;
        static const double MAX_HEIGHT;
        static const double MIN_WEIGHT;
        static const double MAX_WEIGHT;

        static void dataIsCorrect(const std::string& studentData);
        static void passportIsCorrect(const std::string& passport);
        static void studentCardIsCorrect(const std::string& studentCard);
        static void nameIsCorrect(const std::string& name);
        static void surnameIsCorrect(const std::string& surname);
        static void weightIsCorrect(double weight);
        static void heightIsCorrect(double height);
    };
}


#endif