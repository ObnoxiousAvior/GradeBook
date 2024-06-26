#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Student.h"
/**
 * @brief The mode enum
 */
enum mode{FORMATTED, GENERAL_USE};

/**
 * @brief class for working with subjects
 * @author Paul
 * @version 1.0
 * @date 05.20.2024
 */
class Subject
{
    std::string subName;
	std::vector<Student>& vecStudent;
	std::vector<std::vector<int>> gradeVec;
	
public:
	Subject(std::string name ,std::vector<Student>& stListRef) : subName(name), vecStudent(stListRef) {};
	
	std::string getSubName();
	std::vector<std::vector<int>> getGradeVec() {return gradeVec;};
	std::vector<Student>& getStudRef() {return vecStudent;};
	
	void setVec(std::vector<std::vector<int>> vec) {gradeVec = vec;};
	
	void printStudents();
	void printGroup(std::string groupName);
	void printGrades(int studentID, int mode);
	void grade(std::string groupName);
	void updateGradeVec();
	
	void operator=(Subject& right)
	{
		subName = right.getSubName();
		vecStudent = right.getStudRef();
	}
	
};

void printGroup(std::vector<Student> vecStudent, std::string groupName);
