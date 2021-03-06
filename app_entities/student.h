#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>


namespace app_entities {

    class Student {
        std::string name;
        std::string surname;
        double height;
        double weight;
        std::string studentCard;
        std::string passport;
    public:
        explicit Student(
            const std::string& name, const std::string& surname, double height,
            double weight, const std::string& studentCard, const std::string& passport
        );
        explicit Student();
        explicit Student(const std::string& studentData);

        std::string getName() const;
        void setName(const std::string& name);

        std::string getSurname() const;
        void setSurname(const std::string& surname);

        double getHeight() const;
        void setHeight(double height);

        double getWeight() const;
        void setWeight(double weight);

        std::string getStudentCard() const;
        void setStudentCard(const std::string& studentCard);

        std::string getPassport() const;
        void setPassport(const std::string& passport);

        void operator=(const Student& student);

        friend std::ostream& operator<<(std::ostream& output, const Student& student);
        friend std::ostream& operator<<(std::ostream& output, const std::vector<Student>& students);
        friend std::istream& operator>>(std::istream& input, Student& student);

        std::string toString() const;
    };
}

#endif