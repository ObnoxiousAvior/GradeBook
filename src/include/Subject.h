#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Student.h"

enum mode{FORMATTED, GENERAL_USE};

void printGroup(std::vector<Student> vecStudent, std::string groupName);

class Subject
{
	std::string subName;
	std::vector<Student>& vecStudent;
	std::vector<std::vector<int>> gradeVec;
	
public:
	Subject(std::string name ,std::vector<Student>& stListRef) : subName(name), vecStudent(stListRef) {};
	
	std::string getSubName(){return subName;};
	std::vector<std::vector<int>> getGradeVec() {return gradeVec;};
	std::vector<Student>& getStudRef() {return vecStudent;};
	
	void setVec(std::vector<std::vector<int>> vec) {gradeVec = vec;};
	
	void printStudents();
	void printGrades(int studentID, int mode);
	void grade(std::string groupName);
	void updateGradeVec();
	
	void operator=(Subject& right)
	{
		subName = right.getSubName();
		vecStudent = right.getStudRef();
	}
};


