#include <iostream>
#include <vector>
#include <string>

#include "include/Platform.h"
#include "include/Student.h"
#include "include/Users.h"
#include "include/Subject.h"
#include "include/Modes.h"
#include "include/interface.h"
#include "include/Utils.h"

using namespace std;
using namespace interface;


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

    // new admin
    adminList[0].debugLoadDefault(subjectList, studentList, tutorList, groupList);

    // Interface initialization
    greetingToUser();
    selectionPannelAdmin();

	int select;
    utils::queryVar(select);
	
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
            exit();
			break;
	}
	return 0;
}
