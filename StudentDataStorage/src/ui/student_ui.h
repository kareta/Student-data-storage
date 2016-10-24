#ifndef STUDENT_UI_H
#define STUDENT_UI_H

#include "../data/dao/student_dao_text.h"

namespace ui {

    class StudentUi {
    public:
        void run();

        void inputStudent(data::dao::StudentDaoText& dao);
        void inputStudentNTimes(data::dao::StudentDaoText& dao, const int& studentsNumber);
    };
}

#endif