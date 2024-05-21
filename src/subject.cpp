#include <iostream>

#include "include/Platform.h"
#include "include/Student.h"
#include "include/Subject.h"
#include "include/Utils.h"

using namespace std;

std::string Subject::getSubName()
{
	return subName;
}

void Subject::printStudents()
{
    for(unsigned int i = 1; i < vecStudent.size(); ++i) {
        cout << i << ": " << vecStudent[i].fullName << "\n| Group: "<< vecStudent[i].studentGroup << endl;
	}
	cout << endl;
}


void Subject::printGroup(string groupName)
{
    cout << "\n| Group " << groupName << ":" << endl;
	
    for(unsigned int i = 1; i<vecStudent.size(); i++)
	{
		if (groupName.compare(vecStudent[i].studentGroup) == 0) cout << i << ". " << vecStudent[i].fullName<< endl;
	} 	
}

void printGroup(vector<Student> vecStudent, string groupName)
{
    cout << "\n| Group " << groupName << ":" << endl;
	
    for(unsigned int i = 1; i<vecStudent.size(); i++)
	{
		if (groupName.compare(vecStudent[i].studentGroup) == 0) cout << i << ". " << vecStudent[i].fullName<< endl;
	}
}

void Subject::printGrades(int studentID, int mode)
{
	updateGradeVec();
	
	if(gradeVec[studentID].size()>1)
	{
		if(mode == GENERAL_USE) cout << vecStudent[studentID].fullName << ": ";
        for(unsigned int i = 1; i < gradeVec[studentID].size(); ++i)
			cout << gradeVec[studentID][i] << ' ';
		cout << endl;
	} 
	else
	{
        cout << "Oops! " << vecStudent[studentID].fullName << " doesn't have any grades at the moment." << endl;
	}
}

void Subject::grade(string groupName)
{
	system(CLEARSCR);
	printGroup(groupName);

    cout << "\n| Which student would you like to give a mark to?\n|";

	int select;
	utils::queryVar(select);
	
	system(CLEARSCR);
	
    cout << "\n| Type in the mark to give to " << vecStudent[select].fullName << " (An integer from 2 to 5)" << endl << "> ";
	
	int gradeNum;
	cin >> gradeNum;

	gradeVec[select].push_back(gradeNum);
	
	system(CLEARSCR);
	
	printGrades(select, GENERAL_USE);
}
	
void Subject::updateGradeVec()
{
	vector<int> temp = {1};
	gradeVec.resize(vecStudent.size(), temp);
}
