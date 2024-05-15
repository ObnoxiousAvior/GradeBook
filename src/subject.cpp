#include <iostream>

#include "include/Student.h"
#include "include/Subject.h"

using namespace std;

std::string Subject::getSubName()
{
	return subName;
}

void Subject::printStudents()
{
	int i = 0;
	for(vector<Student>::iterator it = vecStudent.begin(); it!=vecStudent.end(); ++it) {
		cout << i << ": " << (*it).fullName << "Group: "<< (*it).studentGroup << endl;
		i++;
	}
	cout << endl;
}


void Subject::printGroup(string groupName)
{
	cout << "Group " << groupName << ":" << endl;
	
	for(int i = 0; i<vecStudent.size(); i++)
	{
		if (groupName.compare(vecStudent[i].studentGroup) == 0) cout << i << ". " << vecStudent[i].fullName<< endl;
	}
}

void printGroup(vector<Student> vecStudent, string groupName)
{
	cout << "Group " << groupName << ":" << endl;
	
	for(int i = 0; i<vecStudent.size(); i++)
	{
		if (groupName.compare(vecStudent[i].studentGroup) == 0) cout << i << ". " << vecStudent[i].fullName<< endl;
	}
}

void Subject::printGrades(int studentID, int mode)
{

	switch(mode)
	{
		case GENERAL_USE:
			if(gradeVec[studentID].size()>1)
			{
			cout << "The " << subName <<" grades of " << vecStudent[studentID].fullName << ": ";
			for(vector<int>::iterator it = gradeVec[studentID].begin()+1; it!=gradeVec[studentID].end(); ++it) 
				cout << *it << ' ';
			}
			else 
			{
				cout << "Oops! " << vecStudent[studentID].fullName << " doesn't have any grades at the moment." << endl;
			}
			break;
	
		case FORMATTED:
			if(gradeVec[studentID].size()>1)
			{
				for(vector<int>::iterator it = gradeVec[studentID].begin()+1; it!=gradeVec[studentID].end(); ++it) 
					cout << *it << ' ';
			}
			else cout << "No grades at the moment" << endl; 
			break;
	}
}

void Subject::grade(string groupName)
{
	if (gradeVec.size() != vecStudent.size()) updateGradeVec();
	
	printGroup(groupName);
	
	cout << "Which student would you like to give a mark to?" << endl << "| ";
	int select;
	cin >> select;
	
	if (vecStudent[select].studentGroup.compare(groupName)!=0) return; // needs polishing
	
	cout << "Type in the mark to give to " << vecStudent[select].fullName << " (An integer from 2 to 5)" << endl << "| ";
	
	int gradeNum;
	cin >> gradeNum;

	gradeVec[select].push_back(gradeNum);
}
	
void Subject::updateGradeVec()
{
	vector<int> temp = {0};
	gradeVec.resize(vecStudent.size(), temp);
}
