#include "include/Platform.h"
#include "include/Student.h"
#include "include/Modes.h"
#include "include/Users.h"
#include "include/Utils.h"
#include "include/interface.h"

using namespace std;
using namespace interface;

void studentMode(vector<Student> studentList, vector<Subject> subjectList, vector<string> groupList) //Открывает функции студента
{
    // interface for student
    greetingToStudent();
	print(groupList);
	
    // option pannel for student
    selectionPannelStudent();
	
	int groupID;
	utils::queryVar(groupID);

	printGroup(studentList, groupList[groupID]);
	
    cout << "\n| Please, enter the number corresponding to your name: ";
	
	int stuID;
	utils::queryVar(stuID);
	
    cout << "\n| The GradeBook profile of " << studentList[stuID].fullName << endl;
    // interface element
    longDiveder();
	
    for(unsigned int i = 1; i<subjectList.size(); ++i)
	{
		cout << "| " << subjectList[i].getSubName() << " | ";
		subjectList[i].printGrades(stuID, FORMATTED);
	}
	
    // interface element
    longDiveder();
}


void tutorMode(vector<Student>& studentList,vector<Subject>& subjectList,vector<Tutor>& tutorList,vector<Admin>& adminList, vector<string>& groupList) //Открывает функции преподователя
{
	int accID = utils::acc_log_in(tutorList);
	Tutor &currentTutor = tutorList[accID];
	
	bool keepCycle = true;
	
	while (keepCycle)
	{
	
    // interface for Tutor
    greetingToTutor();
		
	
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
		save(subjectList, studentList, tutorList, groupList, adminList);
	}
}

void adminMode(vector<Student>& studentList,vector<Subject>& subjectList,vector<Tutor>& tutorList,vector<Admin>& adminList, vector<string>& groupList) //Открывает функции администратора
{
	int accID = utils::acc_log_in(adminList);
	Admin &currentAdmin = adminList[accID];
	
	bool keepCycle = true;
	
	while (keepCycle)
	{
	
    // interface for admin
    greetingToAdmin();
		
		
	int select;
	cin >> select;
	
	system(CLEARSCR);
	
	switch (select)
	{
		case 1:
			print(studentList);
			break;
		case 2:
			currentAdmin.addStudents(studentList, groupList);
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
			currentAdmin.addGroups(groupList);
			break;
		case 7:
			currentAdmin.removeGroup(groupList, studentList, tutorList);
			break;
		case 8:
			currentAdmin.editGroup(studentList, groupList);
			break;
		case 9:
			print(tutorList);
			break;
		case 10:
			currentAdmin.addTutors(tutorList, subjectList, groupList, studentList); // IMPLEMENT ADD SUBJECT
			break;
		case 11:
			currentAdmin.removeTutor(tutorList);
			break;
		case 12:
			currentAdmin.editTutor(tutorList, subjectList, groupList, studentList); // IMPLEMENT ADD SUBJECT
			break;
		case 13:
			print(adminList);
			break;
		case 14: 
			currentAdmin.addAdmins(adminList);
			break;
		case 15:
			currentAdmin.removeThisAdmin(adminList);
			keepCycle = false;
			break;
		case 16:
			save(subjectList, studentList, tutorList, groupList, adminList);
			break;
		case 17:
			load(subjectList, studentList, tutorList, groupList, adminList);
			break;
		case 20:
			currentAdmin.debugLoadDefault(subjectList, studentList, tutorList, groupList);
			break;
		default:
			keepCycle = false;
			break;
		}
        for(unsigned int i = 1; i < subjectList.size(); i++) subjectList[i].updateGradeVec();
	}
}
