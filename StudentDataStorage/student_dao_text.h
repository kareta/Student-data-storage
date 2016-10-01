#ifndef STUDENT_DAO_TEXT_H
#define STUDENT_DAO_TEXT_H

#include <memory>
#include "student_dao.h"
#include "database_engine.h"

class StudentDaoText : public StudentDao {
	std::unique_ptr<DatabaseEngine> databaseEngine;
	std::string tablePath;
	std::vector<std::pair<std::string, std::string>> columns;	
public:
	explicit StudentDaoText(const std::string& tablePath);
	virtual ~StudentDaoText() {};
	std::vector<Student> findWhere(const std::string& propertyName, const std::string& value) override;
	std::vector<Student> all() override;
	void save(const Student& student) override;

	void saveUnsafe(const Student& student) const;
	void closeUnsafeSaving() const;

	StudentDaoText& operator<<(Student& student);
	StudentDaoText& operator>>(std::vector<Student>& students);
}; 

#endif