#include <iostream>
#include <vector>
#include <string>
#include <memory>

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
	Admin defaultAdmin("Default Admin", "admin", "admin");
	
	adminList.push_back(defaultAdmin);
	
	Subject Math("Mathematics", studentList), History("History", studentList), English("English Language", studentList);
	
	subjectList.push_back(Math);
	subjectList.push_back(History);
	subjectList.push_back(English);
	
	Student one{"cm", "32-a"}, two{"tw","123-fe"}, three{"asd", "32-a"};

	groupList.push_back("32-a");
	groupList.push_back("123-fe");
	groupList.push_back("j");

	studentList.push_back(one);
	studentList.push_back(two);
	studentList.push_back(three);

	subjectList[0].updateGradeVec();
	subjectList[1].updateGradeVec();
	subjectList[2].updateGradeVec();

	vector<string> group = {{"32-a", "123-fe", "j"}};
	Tutor tOne("Josh", subjectList[0] , group, "josh123" , "asd");

	tutorList.push_back(tOne);

	cout << "Welcome to GradeBook!" << endl << "=======================" << endl << "Log in as:" << endl << "1. Student" << endl << "2. Tutor" << endl << "3. Admin" << endl << "0. Exit"<< endl << "|";

	int select;
	cin >> select;
	
	switch(select)
	{
		case 1:
			studentMode(studentList, subjectList, groupList);
			break;
		case 2:
			tutorMode(studentList, subjectList, tutorList);
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
