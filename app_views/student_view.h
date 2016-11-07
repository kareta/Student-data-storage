#ifndef STUDENT_VIEW_H
#define STUDENT_VIEW_H

#include <app_services/student_service.h>

using namespace app_services;

namespace app_views {

    class StudentView {
        StudentService studentService;
    public:
        void run();

        void inputStudent();
        void inputStudents();     
        void outputResults();
    };
}

#endif