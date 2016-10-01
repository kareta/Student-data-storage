#include <regex>
#include "validator.h"

const std::string Validator::NAME_PATTERN = "^[a-zA-ZА-Яа-яàáâäãåąčćęèéêëėįìíîïłńòóôöõøùúûüųūÿýżźñçčšžÀÁÂÄÃÅĄĆČĖĘÈÉÊËÌÍÎÏĮŁŃÒÓÔÖÕØÙÚÛÜŲŪŸÝŻŹÑßÇŒÆČŠŽ∂ð,.'-]+$";
const std::string Validator::PASSPORT_PATTERN = "^[АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦШЧЩЬЮЯ]{2}\\d{6}$";
const std::string Validator::STUDENT_CARD_PATTERN = "^[АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦШЧЩЬЮЯ]{2}\\d{8}$";
const double Validator::MIN_HEIGHT = 30;
const double Validator::MAX_HEIGHT = 300;
const double Validator::MIN_WEIGHT = 2;
const double Validator::MAX_WEIGHT = 1000;

bool Validator::isPassportCorrect(const std::string& passport) {
	std::regex expression(PASSPORT_PATTERN);
	return std::regex_match(passport, expression);
}

bool Validator::isStudentCardCorrect(const std::string& studentCard) {
	std::regex expression(STUDENT_CARD_PATTERN);
	return std::regex_match(studentCard, expression);
}  

bool Validator::isNameCorrect(const std::string& name) {
	std::regex expression(NAME_PATTERN);
	return std::regex_match(name, expression);
} 

bool Validator::isSurnameCorrect(const std::string& surname) {
	std::regex expression(NAME_PATTERN);
	return std::regex_match(surname, expression);
} 

bool Validator::isWeightCorrect(const double& weight) {
	return weight >= MIN_WEIGHT && weight <= MAX_WEIGHT;
} 

bool Validator::isHeightCorrect(const double& height) {
	return height >= MIN_HEIGHT && height <= MAX_HEIGHT;
}