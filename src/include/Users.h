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
	std::vector<std::string> studentGroups = {"0"};
public:
	Tutor(std::string name, Subject& sub, std::vector<std::string> groups, std::string log, std::string pass) : fullName(name), subject(sub)
	{
		for(int i=0; i<groups.size(); i++) studentGroups.push_back(groups[i]);
		login = log;
		password = pass;
	};
		std::string getFullName() {return fullName;};
		std::string getSub() {return subject.getSubName();};
		Subject& getSubRef(){return subject;};
		std::vector<std::string> getGroupVec() {return studentGroups;};
		
		void setName(std::string str){fullName = str;};
		void setSub(Subject& sub){subject = sub;};
		void setVec(std::vector<std::string> vec){
			studentGroups.clear();
			studentGroups.push_back(" ");
			for(int i = 0; i<vec.size(); i++) studentGroups.push_back(vec[i]);
		}
		
		void printGroupGrades(std::vector<Student> studentList);
		void printStudentGrades(std::vector<Student> studentList);
		void gradeStudent();
		
		void operator=(Tutor& right)
		{
			fullName = right.getFullName();
			subject = right.getSubRef();
			studentGroups = right.getGroupVec();
			login = right.getLogin();
			password = right.getPassword();
		}
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
	
	std::string getName(){return name;};

	void addSubject(std::vector<Subject>& subjectList, std::vector<Student>& studentList);

	void addStudents(std::vector<Student>& studentList, std::vector<std::string>& groupList);
	void removeStudent(std::vector<Student>& studentList);
	void editStudent(std::vector<Student>& studentList, std::vector<std::string>& groupList);
	
	void addGroups(std::vector<std::string>& groupList);	
	void removeGroup(std::vector<std::string>& groupList, std::vector<Student>& studentList, std::vector<Tutor>& tutorList);
	void editGroup(std::vector<Student>& studentList, std::vector<std::string>& groupList);
	
	void addTutors(std::vector<Tutor>& tutorList, std::vector<Subject>& subjectList, std::vector<std::string>& groupList,std::vector<Student>& studentList);	
	void removeTutor(std::vector<Tutor>& tutorList);
	void editTutor(std::vector<Tutor>& tutorList, std::vector <Subject>& subjectList, std::vector<std::string>& groupList, std::vector<Student>& studentList);
	
	void addAdmins(std::vector<Admin>& adminList);	
	void removeThisAdmin(std::vector<Admin>& adminList);
	
	void debugLoadDefault(std::vector<Subject>& subjectList, std::vector<Student>& studentList, std::vector<Tutor>& tutorList, std::vector<std::string>& groupList);
};

void print(std::vector<Student> studentList);
void print(std::vector<std::string> groupList);
void print(std::vector<Tutor> tutorList);
void print(std::vector<Admin> adminList);

void save(std::vector<Subject>& subjectList, std::vector<Student>& studentList, std::vector<Tutor>& tutorList, std::vector<std::string>& groupList, std::vector<Admin>& adminList);	
void load(std::vector<Subject>& subjectList, std::vector<Student>& studentList, std::vector<Tutor>& tutorList, std::vector<std::string>& groupList, std::vector<Admin>& adminList);	
	
void INIT_VECTORS(std::vector<Tutor>& tutorList, std::vector<Student>& studentList, std::vector<Subject>& subjectList, std::vector<Admin>& adminList, std::vector<std::string>& groupList);


