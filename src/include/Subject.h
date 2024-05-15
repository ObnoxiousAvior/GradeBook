#pragma once

#include <string>
#include <vector>

#include "Student.h"

enum mode{FORMATTED, GENERAL_USE};

class Subject
{
	std::string subName;
	std::vector<Student>& vecStudent;
	std::vector<std::vector<int>> gradeVec;
	
public:
	Subject(std::string name ,std::vector<Student>& stListRef) : subName(name), vecStudent(stListRef) {};
	
	std::string getSubName();
	
	void printStudents();
	void printGroup(std::string groupName);
	void printGrades(int studentID, int mode);
	void grade(std::string groupName);
	void updateGradeVec();
};

void printGroup(std::vector<Student> vecStudent, std::string groupName);
