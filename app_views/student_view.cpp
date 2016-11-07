#include "student_view.h"

#include <iostream>
#include <app_exceptions/invalid_student_exception.h>
#include "app_validators/student_validator.h"

using namespace app_validators;
using namespace app_exceptions;

namespace app_views
{

    void StudentView::run() 
    {     
        inputStudents(); 
        outputResults();
        getchar();

    }

    void StudentView::inputStudent()
    {
        std::string studentData;
        getline(std::cin, studentData);
        StudentValidator::dataIsCorrect(studentData);
        studentService.storeFromString(studentData);
    }

    void StudentView::inputStudents() 
    {
        std::cout << "Students number to input: ";
        std::string input;
        getline(std::cin, input);
        auto studentsNumber = 0;
        try
        {
            studentsNumber = std::stoi(input);
        }
        catch (std::exception)
        {
            //students number remains 0
        }

        if (studentsNumber > 0)
        {
            std::cout << "Type student data\n";
            std::cout << "Format <name> <surname> <height> <weight> <student-card> <passport>\n";
        }
      
        for (auto i = 0; i < studentsNumber; i++) 
        {
            try 
            {
                inputStudent();
            }
            catch (InvalidStudentException& e) 
            {
                std::cout << e.what() << "\n";
                std::cout << "Try another one\n";
            } 
            catch (std::exception)
            {
                std::cout << "Incorrect data";
                std::cout << "Try another one\n";
            }
        }
    }

    void StudentView::outputResults() {
        auto numberWithIdealWeight = studentService.numberWithIdealWeight();

        if (numberWithIdealWeight > 0) {
            std::cout << "There are " << numberWithIdealWeight << " students with ideal weight\n\n";
        } else {
            std::cout << "No students with ideal weight\n\n";
        }

        auto studentsData = studentService.allStudentsToString();

        if (studentsData.empty()) {
            std::cout << "No students in the database\n";          
        } else {
            std::cout << "List of all students in the database:\n";
            std::cout << studentsData;
        }   
    }
}
