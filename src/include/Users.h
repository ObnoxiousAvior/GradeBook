#pragma once

#include <string>
#include <vector>

#include "Student.h"
#include "Subject.h"

class User
{
protected:
	std::string login;
	std::string password;
public:
	std::string getLogin(){return login;};
	std::string getPassword(){return password;};
};

class Tutor : public User
{
	std::string fullName;
	Subject& subject;
	std::vector<std::string> studentGroups;
public:
	Tutor(std::string name, Subject sub, std::vector<std::string> groups, std::string log, std::string pass) : fullName(name), subject(sub), studentGroups(groups)
	{
		login = log;
		password = pass;
	};
	
		std::string getFullName();
		
		int getName(){return 1;};
		
		void printStudentGrades(std::vector<Student> studentList);
		void gradeStudent();
		
		std::string getLogin(){return login;};
};


class Admin : public User
{
	std::string name;
public:
	Admin(std::string clName, std::string log, std::string pass) :
	name(clName) {
		login = log;
		password = pass;
	};
	
	std::string getName();
	
	void addGroups(std::vector<std::string>& groupList);
	
	void printStudents(std::vector<Student> studentList);
	void addStudents(std::vector<Student>& studentList, std::vector<std::string>& groupList);
};




