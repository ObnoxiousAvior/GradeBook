#include <iostream>
#include <string>
#include <vector>

#include "include/Users.h"
#include "include/Subject.h"
#include "include/Utils.h"

using namespace std;
// GENERAL USER FUNCTIONS

// TUTOR FUNCTIONS

void Tutor::printStudentGrades(vector<Student> studentList)
{
	print(studentGroups);
	
	cout << "===================" << endl;
	
	cout << "Please, choose the group:\n|";

	int groupID;
	utils::queryVar(groupID);

	system("clear");

	printGroup(studentList, studentGroups[groupID]);

	cout << "Please, select the student:\n|";

	int stuID;
	utils::queryVar(stuID);
	
	system("clear"); 
	
	cout << "The GradeBook of " << studentList[stuID].fullName 
		<< endl << "===================" << endl;

	cout << "| " << subject.getSubName() << " |: ";
	subject.printGrades(stuID, FORMATTED);
	cout << "===================" << endl;
}

void Tutor::printGroupGrades(vector<Student> studentList)
{
	print(studentGroups);
	
	cout << "===================" << endl;

	cout << "Please, choose the group:\n|";

	int groupID;
	utils::queryVar(groupID);

	system("clear");

	cout << "The GradeBook of " << studentGroups[groupID] 
		<< endl << "===================" << endl;



	for (int i = 1; i < studentList.size(); i++) 
	{	 
		if (studentList[i].studentGroup.compare(studentGroups[groupID]) == 0)
		{
			cout << "| " << subject.getSubName() << " |: ";
			subject.printGrades(i, FORMATTED);
		}
	}
	cout <<"===================" << endl;
}

void Tutor::gradeStudent()
{
	print(studentGroups);

	cout <<"===================" << endl;
	cout << "Please, choose the group: ";

	int groupID;
	utils::queryVar(groupID);
	
	subject.grade(studentGroups[groupID]);
}

// ADMIN FUNCTIONS

string Admin::getName() {return name;}

// ADD FUNCTIONS

// ADD STUDENTS
void Admin::add(vector<Student>& studentList, vector<string>& groupList)
{
	cout <<  "How many students would you like to add?\n|";

	int n;
	utils::queryVar(n);
	
	if (n<=0) return;
	
	cout << "=========================================" << endl;
	
	for(int i = 1; i <= n; i++)
	{
		cout << "Student " << i << ":" << endl << "Type in the student's full name: ";
		print(groupList);

		string name;
		utils::queryVar(name);
		
		if (groupList.size() == 0) 
		{
			cout << "Looks like the database doesn't have any groups yet!\nWould you like to add new groups?\n1. Yes\n2. No\n|";
		
			int select;
			utils::queryVar(select);
			
			if (select != 1) return;
			else add(groupList);
		}
		
		cout << "=========================================" << endl;
		
		do	{
		cout << "Groups:" << endl;
		
		for(int j = 1; j <= groupList.size(); j++) 
		{
			if (j < groupList.size()) cout << j << ". " << groupList[j] << endl;
			else cout << j << ". Add the new groups" << endl;
		}
		
		cout << endl;
		
		cout << "Select: ";
		
		int selectGroup;
		utils::queryVar(selectGroup); 
		
		if (selectGroup < groupList.size()) 
		{
			Student stud{name, groupList[selectGroup]};
			studentList.push_back(stud);
			break;
		}
		else 
		{
			add(groupList);
		}
		}while(true);
	}
	
	system("clear");
	cout << "Successfully added " << n << " student(s)" << endl;
}

// ADD GROUPS
void Admin::add(vector<string>& groupList)
{
	cout << "How many groups would you like to add?\n|";
	
	int n;
	utils::queryVar(n);
	
	for(int i = 1; i <= n; i++)
	{
		cout << "Group " << i << ":" << endl << "Type in a name for a group: ";

		std::string groupName;
		utils::queryVar(groupName);
		
		groupList.push_back(groupName);
	}
	system("clear");
	cout << "Successfully added " << n << " group(s)" << endl;
}

// PRINT FUNCTIONS

void print(vector<Student> studentList){
	system("clear");
	std::cout << "Here's a full student list: " << std::endl;
	for(int i = 1; i<studentList.size(); i++) std::cout << i << ". " << studentList[i].fullName << " | Group: " << studentList[i].studentGroup << std::endl; 
}

void print(vector<string> groupList){
	system("clear");
	cout << "Here's a full group list: " << endl;
	for(int i = 1; i < groupList.size(); i++) std::cout << i << ". " << groupList[i] << std::endl;	
}
void print(vector<Tutor> tutorList){
	system("clear");
	cout << "Here's a full tutor list: " << endl;
	for(int i = 1; i < tutorList.size(); i++) 
	{
		cout << i << ". " << tutorList[i].getFullName() << " | Subject: " << tutorList[i].getSub() << endl << "____________________" << endl << "Groups: ";
		//for(int j = 0; j<tutorList[i].getGroupVec().size(); j++) cout << tutorList[i].getGroupVec()[j] << ' ';
		cout << endl << "____________________" << endl;
	}	
}
void print(vector<Admin> adminList){
	system("clear");
	std::cout << "Here's a full admin list: " << std::endl;
	for(int j = 1; j < adminList.size(); j++) std::cout << j << ". " << adminList[j].getName() << std::endl;
}


void Admin::removeStudent(vector<Student>& studentList)
{
	print(studentList);
	
	cout << "=========================================" << endl << "Choose a student to remove: ";
	
	int select;
	utils::queryVar(select);
	
	studentList.erase(studentList.begin()+select);
	
	system("clear");
	cout << "Successfully removed"<< endl;
}

void Admin::editStudent(vector<Student>& studentList, vector<std::string>& groupList)
{
	print(studentList);
		
	cout << "Choose a student to edit: ";
	
	int select;
	utils::queryVar(select); 
	
	cout << "1. Edit a name\n2. Edit a group\n0. Exit\n"; 
	
	int name_or_group;
	utils::queryVar(name_or_group);
	
	if(name_or_group == 0) return;
	
	std::string buffer;
	cout << "|";
	utils::queryVar(buffer);
	
	if(name_or_group == 1) studentList[select].fullName = buffer;
	else if (name_or_group == 2) studentList[select].studentGroup = buffer;
}


void Admin::editGroup(vector<Student>& studentList, vector<std::string>& groupList)
{
	print(groupList);

	cout << "=========================================" << endl << "Select a group to edit: ";
	
	int selectGroup;
	utils::queryVar(selectGroup);
	
	cout << "=========================================" << endl << "Choose:\n1. Edit a name\n0. Exit\n|";
	
	int exit;
	utils::queryVar(exit);
	
	if(exit == 0) return;
	
	std::string buffer;
	cout << "The new name for " << groupList[selectGroup] << ": ";
	utils::queryVar(buffer);
	
	string prevName = groupList[selectGroup];
	groupList[selectGroup] = buffer;
	
	for(int i = 1; i<studentList.size(); i++)
	{
		if(studentList[i].studentGroup.compare(prevName) == 0) studentList[i].studentGroup = buffer;
	}
	
	system("clear");
}


void Admin::debugLoadDefault(vector<Subject>& subjectList, vector<Student>& studentList, vector<Tutor>& tutorList, vector<string>& groupList)
{
	Subject Math("Mathematics", studentList), History("History", studentList), English("English", studentList);
	
	subjectList.push_back(Math);
	subjectList.push_back(History);
	subjectList.push_back(English);

	Student one{"Andy Robinson", "32-AM"}, two{"James Lovejoy","12-FE"}, three{"Marin Kitagawa", "32-AM"};

	groupList.push_back("32-AM");
	groupList.push_back("12-FE");
	groupList.push_back("73-JK");

	studentList.push_back(one);
	studentList.push_back(two);
	studentList.push_back(three);

	subjectList[1].updateGradeVec();
	subjectList[2].updateGradeVec();
	subjectList[3].updateGradeVec();
	
	
	vector<string> group = {{"32-AM", "12-FE", "73-JK"}};
	Tutor tOne("John Gacy", subjectList[1] , group, "john123" , "qwerty");

	tutorList.push_back(tOne);
}

void INIT_VECTORS(vector<Tutor>& tutorList, vector<Student>& studentList, vector<Subject>& subjectList, vector<Admin>& adminList, vector<string>& groupList)
{
	Subject defSub("0", studentList);
	Student defStud{"0", "0"};
	Admin defAdm("0", "0", "0");
	string defGroup = "0";
	Tutor defTut("0", defSub, groupList, "0", "0");
	
	subjectList.push_back(defSub);
	studentList.push_back(defStud);
	adminList.push_back(defAdm);
	groupList.push_back(defGroup);
	tutorList.push_back(defTut);
}

