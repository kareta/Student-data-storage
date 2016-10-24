#ifndef STUDENT_UI_H
#define STUDENT_UI_H

#include "../data/dao/student_dao_text.h"
#include "../services/student_service.h"

using namespace services;

namespace ui {

    class StudentUi {
        StudentService studentService;
    public:
        void run();

        void inputStudent();
        void inputStudentNTimes(const int& studentsNumber);

        
    };
}

#endif