#include "include/Student.h"
#include "include/Modes.h"
#include "include/Users.h"
#include "include/Utils.h"

using namespace std;

void studentMode(vector<Student> studentList, vector<Subject> subjectList, vector<string> groupList)
{
	cout << "You're now using the GradeBook as a student!" << endl << "=========================================" << endl << "Groups: " << endl;
	
	for(int j = 0; j < groupList.size(); j++)  cout << j << ". " << groupList[j] << endl;
	
	int groupID;
	utils::queryInt(groupID, "Please, select the group you're studying in: ");
	
	printGroup(studentList, groupList[groupID]);
	
	cout << "Please, enter the number corresponding to your name: ";
	int stuID;
	utils::queryVar(stuID);
	
	cout << "The GradeBook of " << studentList[stuID].fullName << endl << "===================" << endl;
	
	for(vector<Subject>::iterator it = subjectList.begin(); it!=subjectList.end(); ++it)
	{
		cout << "| " << (*it).getSubName() << " | ";
		(*it).printGrades(stuID, FORMATTED);
	}
	
	cout << "===================" << endl;
}


void tutorMode(vector<Student>& studentList, vector<Subject>& subjectList, vector<Tutor>& tutorList)
{
	int accID = utils::acc_log_in(tutorList);
	Tutor &currentUser = tutorList[accID];
	
	bool keepCycle = true;
	
	while (keepCycle)
	{
	
	cout << "Welcome, " << currentUser.getFullName() << "!" << endl 
		<< "=========================================" << endl 
		<< "You're now using the GradeBook as a tutor!" << endl 
		<< "=========================================" << endl 
		<< "What would you like to do?" << endl
		<< "1. Print student's grades on your subject" << endl
		<< "2. Grade a student" << endl
		<< "| ";
		
	
	int select;
	cin >> select;
	
	switch (select)
	{
		case 1:
		{
			currentUser.printStudentGrades(studentList);
			break;
		}
		
		case 2:
		{
			currentUser.gradeStudent();
			break;
		}
		default:
			keepCycle = false;
			break;
		}
	}
}

void adminMode(vector<Student>& studentList,vector<Subject>& subjectList,vector<Tutor>& tutorList,vector<Admin>& adminList, vector<string>& groupList)
{
	int accID = utils::acc_log_in(adminList);
	Admin &currentUser = adminList[accID];
	
	bool keepCycle = true;
	
	while (keepCycle)
	{
	
	cout << "Welcome, " << currentUser.getName() << "!" << endl 
		<< "=========================================" << endl 
		<< "You're now using the GradeBook as an admin!" << endl 
		<< "=========================================" << endl 
		<< "What would you like to do?" << endl
		<< "1. Print student list" << endl
		<< "2. Add students" << endl
		<< "3. Remove a student" << endl
		<< "4. Edit student's info" << endl 
		<< endl
		<< "5. Print tutor list" << endl
		<< "6. Add tutors" << endl
		<< "7. Remove a tutor" << endl
		<< "8. Edit tutor's info" << endl 
		<< endl
		<< "9. Print admin list" << endl
		<< "10. Add admin" << endl
		<< "11. Remove this admin account" << endl;
		
		
	
	int select;
	cin >> select;
	
	switch (select)
	{
		case 1:
		{
			currentUser.printStudents(studentList);
			break;
		}
		case 2:
		{
			currentUser.addStudents(studentList, groupList);
			break;
		}
		default:
			keepCycle = false;
			break;
		}
	}
}
