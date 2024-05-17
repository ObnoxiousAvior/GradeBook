#include <iostream>
#include <vector>
#include <string>

#include "include/Platform.h"
#include "include/Student.h"
#include "include/Users.h"
#include "include/Subject.h"
#include "include/Modes.h"

using namespace std;


vector<Tutor> tutorList;
vector<Student> studentList;
vector<Subject> subjectList;
vector<Admin> adminList;
vector<string> groupList;

int main()
{
	system(CLEARSCR);

	INIT_VECTORS(tutorList, studentList, subjectList, adminList, groupList);
	
	Admin defaultAdmin("Default Admin", "admin", "admin");
	adminList.push_back(defaultAdmin);

	cout << "Welcome to GradeBook!" << endl << "=======================" << endl << "Log in as:" << endl << "1. Student" << endl << "2. Tutor" << endl << "3. Admin" << endl << "0. Exit"<< endl << "|";

	int select;
	cin >> select;
	
	system(CLEARSCR);
	
	switch(select)
	{
		case 1:
			studentMode(studentList, subjectList, groupList);
			break;
		case 2:
			tutorMode(studentList, subjectList, tutorList, adminList, groupList);
			break;
		case 3:
			adminMode(studentList, subjectList, tutorList, adminList, groupList);
			break;
		default:
			cout << "See you next time!" << endl;
			break;
	}
	return 0;
}
