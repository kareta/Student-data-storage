#include "student_service.h"

#include <string>
#include <sstream>

namespace app_services 
{
    StudentService::StudentService() : studentRepository() {}

    void StudentService::store(app_entities::Student& student) 
    {
        studentRepository << student;
    }

    void StudentService::storeFromString(const std::string& studentData) 
    {
        store(studentFromString(studentData));
    }

    app_entities::Student StudentService::studentFromString(const std::string& studentData) const
    {
        auto values = utils::split(studentData, ' ');
        if (values.size() != StudentValidator::NUMBER_OF_PROPERTIES) {
            throw InvalidStudentException("Incorrect string");
        }
        auto name = values[0];
        auto surname = values[1];
        auto height = std::stod(values[2]);
        auto weight = std::stod(values[3]);
        auto studentCard = values[4];
        auto passport = values[5];
        Student student(name, surname, height, weight, studentCard, passport);
        return student;
    }

    std::vector<Student> StudentService::allStudents() 
    {
        return studentRepository.all();
    }

    std::vector<Student> StudentService::withIdealWeight()
    {
        auto students = studentRepository.all();

        std::vector<Student> withIdealWeight;

        for (const auto& student : students) 
        {
            auto weightIsIdeal = (student.getHeight() - student.getWeight()) == 110;
            if (weightIsIdeal) 
            {
                withIdealWeight.push_back(student);
            }
        }
        return withIdealWeight;
    }

    int StudentService::numberWithIdealWeight() 
    {
        return withIdealWeight().size();
    }

    std::string StudentService::allStudentsToString() 
    {
        std::stringstream stringStream;
        stringStream << studentRepository.all();
        return stringStream.str();
    }
}
