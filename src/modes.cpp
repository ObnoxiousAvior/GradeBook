#include "include/Student.h"
#include "include/Modes.h"
#include "include/Users.h"
#include "include/Utils.h"

using namespace std;

void studentMode(vector<Student> studentList, vector<Subject> subjectList, vector<string> groupList)
{
	cout << "You're now using the GradeBook as a student!" << endl << "=========================================" << endl << "Groups: " << endl;
	
	print(groupList);
	
	cout <<"Please, select the group you're studying in: ";
	
	int groupID;
	utils::queryVar(groupID);

	printGroup(studentList, groupList[groupID]);
	
	cout << "Please, enter the number corresponding to your name: ";
	
	int stuID;
	utils::queryVar(stuID);
	
	cout << "The GradeBook of " << studentList[stuID].fullName << endl << "===================" << endl;
	
	for(int i = 1; i<subjectList.size(); ++i)
	{
		cout << "| " << subjectList[i].getSubName() << " | ";
		subjectList[i].printGrades(stuID, FORMATTED);
	}
	
	cout << "===================" << endl;
}


void tutorMode(vector<Student> studentList, vector<Tutor> tutorList)
{
	int accID = utils::acc_log_in(tutorList);
	Tutor &currentTutor = tutorList[accID];
	
	bool keepCycle = true;
	
	while (keepCycle)
	{
	
	cout << "Welcome, " << currentTutor.getFullName() << "!" << endl 
		<< "=========================================" << endl 
		<< "You're now using the GradeBook as a tutor!" << endl 
		<< "=========================================" << endl 
		<< "What would you like to do?" << endl
		<< "1. Print student's grades on your subject" << endl
		<< "2. Print group's grades on your subject" << endl
		<< "3. Grade a student" << endl
		<< "| ";
		
	
	int select;
	cin >> select;
	
	switch (select)
	{
		case 1:
			currentTutor.printStudentGrades(studentList);
			break;
		case 2:
			currentTutor.printGroupGrades(studentList);
			break;
		case 3:
			currentTutor.gradeStudent();
			cout << endl;
			break;
		default:
			keepCycle = false;
			break;
		}
	}
}

void adminMode(vector<Student>& studentList,vector<Subject>& subjectList,vector<Tutor>& tutorList,vector<Admin>& adminList, vector<string>& groupList)
{
	int accID = utils::acc_log_in(adminList);
	Admin &currentAdmin = adminList[accID];
	
	bool keepCycle = true;
	
	while (keepCycle)
	{
	
	cout << "=========================================" << endl 
		<< "Welcome, " << currentAdmin.getName() << "!" << endl 
		<< "=========================================" << endl 
		<< "You're now using the GradeBook as an admin!" << endl 
		<< "=========================================" << endl 
		<< "What would you like to do?" << endl
		<< "1. Print student list" << endl
		<< "2. Add students" << endl
		<< "3. Remove a student" << endl
		<< "4. Edit student's info" << endl 
		<< endl
		<< "5. Print groups" << endl
		<< "6. Add groups" << endl
		<< "7. Remove group" << endl 
		<< "8. Edit group" << endl
		<< endl
		<< "9. Print tutor list" << endl
		<< "10. Add tutors" << endl
		<< "11. Remove a tutor" << endl
		<< "12. Edit tutor's info" << endl 
		<< endl
		<< "13. Print admin list" << endl
		<< "14. Add admin" << endl
		<< "15. Remove this admin account" << endl;
		
		
	
	int select;
	cin >> select;
	
	system("clear");
	
	switch (select)
	{
		case 1:
			print(studentList);
			break;
		case 2:
			currentAdmin.add(studentList, groupList);
			break;
		case 3:
			currentAdmin.removeStudent(studentList);
			break;
		case 4:
			currentAdmin.editStudent(studentList, groupList);
			break;
		case 5:
			print(groupList);
			break;
		case 6:
			currentAdmin.add(groupList);
			break;
		case 7:
			break;
		case 8:
			currentAdmin.editGroup(studentList, groupList);
			break;
		case 9:
			print(tutorList);
			break;
		case 13:
			print(adminList);
			break;
		case 20:
			currentAdmin.debugLoadDefault(subjectList, studentList, tutorList, groupList);
			break;
		default:
			keepCycle = false;
			break;
		}
		for(int i = 1; i < subjectList.size(); i++) subjectList[i].updateGradeVec();
	}
}
