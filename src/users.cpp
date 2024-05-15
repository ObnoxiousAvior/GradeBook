#include <iostream>

#include "include/Users.h"
#include "include/Subject.h"
#include "include/Utils.h"

using namespace std;

using namespace utils;

// GENERAL USER FUNCTIONS


// TUTOR FUNCTIONS


string Tutor::getFullName() {return fullName;}

void Tutor::printStudentGrades(vector<Student> studentList)
{
	cout << "Please, choose the group: " << endl;
			
	for (int i = 0; i < studentGroups.size(); i++) cout << i << ". " << studentGroups[i] << endl;
	cout << "| ";

	int groupID;
	cin >> groupID;

	printGroup(studentList, studentGroups[groupID]);

	cout << "Please, enter the number corresponding to the student: ";
	int stuID;
	cin >> stuID;
	
	cout << "The GradeBook of " << studentList[stuID].fullName 
		<< endl << "===================" << endl;

	cout << "| " << subject.getSubName() << " |: ";
	subject.printGrades(stuID, FORMATTED);
	cout << endl << "===================" << endl;
}

void Tutor::gradeStudent()
{
	cout << "Please, choose the group: " << endl;
			
	for (int i = 0; i < studentGroups.size(); i++) 
		cout << i << ". " << studentGroups[i] << endl;
	cout << "| ";

	int groupID;
	cin >> groupID;
	
	subject.grade(studentGroups[groupID]);
}

// ADMIN FUNCTIONS

string Admin::getName() {return name;}

void Admin::addGroups(vector<string>& groupList)
{
	cout << "How many groups would you like to add?" << endl << "|";
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cout << "Group " << i << ":" << endl << "Type in a name for a group: ";
		
		std::string name;
		cin >> name;
		
		groupList.push_back(name);
	}
}

void Admin::printStudents(vector<Student> studentList)
{
	cout << "Here's a full student list: " << endl;
	for(int i = 0; i<studentList.size(); i++) cout << i << ". " << studentList[i].fullName << "\tGroup: " << studentList[i].studentGroup << endl; 
	cout << endl;
}

void Admin::addStudents(vector<Student>& studentList, vector<string>& groupList)
{
	cout << "How many students would you like to add?" << endl << "|";
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		cout << "Student " << i+1 << ":" << endl << "Type in the student's full name: ";
		
		string name;
		queryVar(name);
		
		if (groupList.size() == 0) 
		{
			cout << "Looks like the database doesn't have any groups yet!" << endl << "Would you like to add new groups?" << endl << "1. Yes" << endl << "2. No" << endl << "|";
			
			int select;
			cin >> select;
			
			if (select != 1) return;
			else addGroups(groupList);
		}
		
		do	{
		cout << "Select the student's group:" << endl;
		
		for(int j = 0; j <= groupList.size(); j++) 
		{
			if (j < groupList.size()) cout << j << ". " << groupList[j] << endl;
			else cout << j << ". Add the new groups" << endl;
		}
		
		int selectGroup;
		cin >> selectGroup;
		
		if (selectGroup < groupList.size()) 
		{
			Student stud{name, groupList[selectGroup]};
			studentList.push_back(stud);
			break;
		}
		else 
		{
			addGroups(groupList);
		}
		}while(true);
		
		
		cout << "Successfully added " << n << " students" << endl; 
	}
}
