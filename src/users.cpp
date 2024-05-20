#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

#include "include/Platform.h"
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

	system(CLEARSCR);

	printGroup(studentList, studentGroups[groupID]);

	cout << "Please, select the student:\n|";

	int stuID;
	utils::queryVar(stuID);
	
	system(CLEARSCR); 
	
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

	system(CLEARSCR);

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

// ADD STUDENTS

void Admin::addSubject(vector<Subject>& subjectList, vector<Student>& studentList)
{
	cout << "Type in the subject name:\n|";
	
	string name;
	std::getline(std::cin, name);
	
	Subject sub(name, studentList);
	subjectList.push_back(sub);
}

void Admin::addStudents(vector<Student>& studentList, vector<string>& groupList)
{
	cout <<  "How many students would you like to add?\n|";
	
	int n;
	utils::queryVar(n);
	
	if (n<=0) return;
	
	cout << "=========================================" << endl;
	
	for(int i = 1; i <= n; i++)
	{
		cout << "Student " << i << ":" << endl << "Type in the student's full name: ";
		
		string stuName;
		std::getline(std::cin, stuName);
	
		
		if (groupList.size() == 0) 
		{
			cout << "Looks like the database doesn't have any groups yet!\nWould you like to add new groups?\n1. Yes\n2. No\n|";
		
			int select;
			utils::queryVar(select);
			
			if (select != 1) return;
			else addGroups(groupList);
		}
		
		cout << "=========================================" << endl;
		
		do	{
		print(groupList);
		
		cout << endl;
		
		cout << "Select: ";
		
		int selectGroup;
		utils::queryVar(selectGroup); 
		
		if (selectGroup < groupList.size()) 
		{
			Student stud{stuName, groupList[selectGroup]};
			studentList.push_back(stud);
			break;
		}
		else 
		{
			addGroups(groupList);
		}
		}while(true);
	}
	
	system(CLEARSCR);
	cout << "Successfully added " << n << " student(s)" << endl;
}

// ADD GROUPS
void Admin::addGroups(vector<string>& groupList)
{
	cout << "How many groups would you like to add?\n|";
	
	int n;
	utils::queryVar(n);
	
	for(int i = 1; i <= n; i++)
	{
		cout << "Group " << i << ":" << endl << "Type in a name for a group: ";

		std::string groupName;
		std::getline(std::cin, groupName);
		
		groupList.push_back(groupName);
	}
	system(CLEARSCR);
	cout << "Successfully added " << n << " group(s)" << endl;
}

//  ADD TUTORS
void Admin::addTutors(vector<Tutor>& tutorList, vector<Subject>& subjectList, vector<string>& groupList, vector<Student>& studentList)
{
	print(tutorList);
	cout << "=========================================" << endl;
	cout << "How many tutors would you like to add?\n|";
	
	int n;
	utils::queryVar(n);
	
	for(int i = 1; i <= n; i++)
	{
		system(CLEARSCR);
		cout << "Tutor " << i << ":" << endl << "Type in the tutor's first name: ";
		
		string tutorName;
		std::getline(std::cin, tutorName);
		
		int selectSub;
		
		do{
		cout << "Here's a full subject list:\n";
		for(int j = 1; j<=subjectList.size(); j++)
		{
			if (j<subjectList.size()) cout << j << ". " << subjectList[j].getSubName() << endl;
			else cout << j << ". Add new subjects" << endl; 
		}
		utils::queryVar(selectSub);
		
		if(selectSub == subjectList.size())
		{
			addSubject(subjectList, studentList);
			continue;
		}
		break;
		}while(true);
		
		system(CLEARSCR);

		vector<int> groupIDvec;
		vector<string> groupVec;
		int choose=1;
		
		print(groupList);
		
		cout <<"===================" << endl;
		cout << "Please, choose the groups your tutor will educate (ex: 1 0 , 2 4 0, 6 2 3 0, etc. 0 to exit): ";

		while(choose)
		{
			cin >> choose;
			groupIDvec.push_back(choose); 
		}
		
		groupIDvec.pop_back();
		
		for(int j = 0; j<groupIDvec.size(); j++) 
		{
			groupVec.push_back(groupList[groupIDvec[j]]);
		}
		
		cout << "Please, enter a login:\n|"; 
		
		while(getchar()!='\n');
		string log;
		std::getline(std::cin, log);
		
		cout << "Please, enter a password:\n|"; 
		string pass;
		std::getline(std::cin, pass);
		
		Tutor newTut(tutorName, subjectList[selectSub], groupVec, log, pass);
		
		tutorList.push_back(newTut);
	}
}

// ADD ADMINISTRATORS

void Admin::addAdmins(vector<Admin>& adminList)
{
	print(adminList);
	cout << "=========================================" << endl;
	cout << "How many administrators would you like to add?\n|";
	
	int n;
	utils::queryVar(n);
	
	for(int i = 1; i <= n; i++)
	{
		system(CLEARSCR);
		cout << "Tutor " << i << ":" << endl << "Type in a name of an admin:\n|";

		std::string adminName;
		std::getline(std::cin, adminName);
		
		system(CLEARSCR);

		cout << "Please, enter a login:\n|"; 

		string log;
		std::getline(std::cin, log);
		
		cout << "Please, enter a password:\n|"; 
		
		string pass;
		std::getline(std::cin, pass);
		
		Admin newAdm(adminName, log, pass);
		
		adminList.push_back(newAdm);
	}
}

// PRINT FUNCTIONS

void print(vector<Student> studentList){
	system(CLEARSCR);
	std::cout << "Here's a full student list: " << std::endl;
	for(int i = 1; i<studentList.size(); i++) std::cout << i << ". " << studentList[i].fullName << " | Group: " << studentList[i].studentGroup << std::endl; 
}

void print(vector<string> groupList){
	system(CLEARSCR);
	cout << "Here's a full group list: " << endl;
	for(int i = 1; i < groupList.size(); i++) std::cout << i << ". " << groupList[i] << std::endl;	
}
void print(vector<Tutor> tutorList){
	system(CLEARSCR);
	cout << "Here's a full tutor list: " << endl;
	for(int i = 1; i < tutorList.size(); i++) 
	{
		cout << i << ". " << tutorList[i].getFullName() << " | Subject: " << tutorList[i].getSub() << endl << "Groups: ";
		for(int j = 1; j<tutorList[i].getGroupVec().size(); j++) cout << tutorList[i].getGroupVec()[j] << ' ';
		cout << endl << "____________________" << endl;
	}	
}
void print(vector<Admin> adminList){
	system(CLEARSCR);
	std::cout << "Here's a full admin list: " << std::endl;
	for(int j = 0; j < adminList.size(); j++) std::cout << j << ". " << adminList[j].getName() << std::endl;
}


void Admin::removeStudent(vector<Student>& studentList)
{
	print(studentList);
	
	cout << "=========================================" << endl << "Choose a student to remove: ";
	
	int select;
	utils::queryVar(select);
	
	studentList.erase(studentList.begin()+select);
	
	system(CLEARSCR);
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
	else if (name_or_group == 1) 
	{
		cout << "Type in the student's full name:\n|";
		
		string name;
		utils::queryVar(name);
		
		studentList[select].fullName = name;
	}
	else if (name_or_group == 2) 
	{
		do	{
		print(groupList);
		cout << groupList.size() << ". Add new groups" << endl;
		
		cout << "Select: ";
		
		int selectGroup;
		utils::queryVar(selectGroup); 
		
		if(!selectGroup) return;
		
		if (selectGroup < groupList.size()) 
		{
			studentList[select].studentGroup = groupList[selectGroup];
			break;
		}
		else 
		{
			addGroups(groupList);
		}
		}while(true);
	}
}

void Admin::removeGroup(vector<string>& groupList, vector<Student>& studentList, vector<Tutor>& tutorList)
{
	print(groupList);
	
	cout << "=========================================" << endl << "Choose a group to remove: ";
	
	int select;
	utils::queryVar(select);
	
	string tempGr = groupList[select];
	
	groupList.erase(groupList.begin()+select);
	
	for(int i = 1; i<studentList.size(); i++)
	{
		if(studentList[i].studentGroup.compare(tempGr) == 0)
		{
			
			
			do	{
			print(groupList);
			cout << groupList.size() << ". Add new groups" << endl;
			
			cout << "=========================================" << endl;
			cout << "Student " << studentList[i].fullName << " has no group.\nSelect a new group for them:\n|";
			cout << "=========================================" << endl;			
			cout << "Select: ";
			
			int selectGroup;
			utils::queryVar(selectGroup); 
			
			if(!selectGroup) return;
			
			if (selectGroup < groupList.size()) 
			{
				studentList[i].studentGroup = groupList[selectGroup];
				break;
			}
			else 
			{
				addGroups(groupList);
			}
			}while(true);
		}
	}
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
	
	system(CLEARSCR);
}

void Admin::removeTutor(vector<Tutor>& tutorList)
{
	print(tutorList);
	
	cout << "=========================================" << endl << "Choose a tutor to remove: ";
	
	int select;
	utils::queryVar(select);
	
	tutorList[select] = tutorList[tutorList.size()-1];
	
	tutorList.pop_back();
	
	system(CLEARSCR);
	cout << "Successfully removed"<< endl;
}

void Admin::editTutor(vector<Tutor>& tutorList, vector<Subject>& subjectList, vector<string>& groupList, vector<Student>& studentList)
{
	print(tutorList);

	cout << "=========================================" << endl << "Select a tutor to edit: ";
	
	int select;
	utils::queryVar(select);
	
	cout << "=========================================" << endl << "Choose:\n1. Edit a full name\n2. Change the subject\n3. Change the educated groups\n0. Exit\n|";
	
	int exit;
	utils::queryVar(exit);
	
	if(exit == 0) return;
	else if (exit == 1) 
	{
		cout << "Type in the tutor's full name:\n|";
		
		string name;
		std::getline(std::cin,name);
		
		tutorList[select].setName(name);
	}
	else if(exit == 2)
	{
		
		int selectSub;
		
		do{
		cout << "Here's a full subject list:\n";
		for(int j = 1; j<=subjectList.size(); j++)
		{
			if (j<subjectList.size()) cout << j << ". " << subjectList[j].getSubName() << endl;
			else cout << j << ". Add new subjects" << endl; 
		}
		utils::queryVar(selectSub);
		
		if(selectSub == subjectList.size())
		{
			addSubject(subjectList, studentList);
			continue;
		}
		}while(false);
		
		tutorList[select].setSub(subjectList[selectSub]);
	}
	else if(exit == 3)
	{
		vector<int> groupIDvec;
		vector<string> groupVec;
		print(groupList);
		
		cout <<"===================" << endl;
		cout << "Please, choose the groups your tutor will educate (ex: 1 0 , 2 4 0, 6 2 3 0, etc. 0 to exit): ";
		
		int choose = 1;

		while(choose)
		{
			cin >> choose;
			groupIDvec.push_back(choose); 
		}
		
		groupIDvec.pop_back();
		
		for(int j = 0; j<groupIDvec.size(); j++) 
		{
			groupVec.push_back(groupList[groupIDvec[j]]);
		}
		tutorList[select].setVec(groupVec);
	}
	system(CLEARSCR);
}

void Admin::removeThisAdmin(vector<Admin>& adminList)
{
	cout << "Are you sure you want to delete this account?\n1.Yes\n2.No\n|";
		
	int select;
	utils::queryVar(select);
	
	if(select != 1) return;
	
	adminList.erase(adminList.begin()+select);
	
	system(CLEARSCR);
	cout << "Successfully removed"<< endl;
}

void save(vector<Subject>& subjectList, vector<Student>& studentList, vector<Tutor>& tutorList, vector<string>& groupList, vector<Admin>& adminList)
{
	ofstream saveFile;
	saveFile.open("save.txt",std::ofstream::out | std::ofstream::trunc);

	saveFile << subjectList.size()-1 << endl << studentList.size()-1 << endl <<  tutorList.size()-1 << endl <<  adminList.size()-1 << endl <<  groupList.size()-1 << endl;
	
	for(int i = 1; i<studentList.size(); i++) saveFile << studentList[i].fullName << endl << studentList[i].studentGroup << endl;

	for(int i = 1; i<subjectList.size(); i++)
	{ 
		saveFile << subjectList[i].getSubName() << endl;
		std::vector<std::vector<int>> gradeVec;
		
		for(int j = 1; j < subjectList[i].getGradeVec().size(); j++)
		{
			for(int k = 0; k < subjectList[i].getGradeVec()[j].size(); k++) 
			{
				saveFile << subjectList[i].getGradeVec()[j][k] << ' ';
			}
			saveFile << endl;
		}		
	}
	
	for(int i = 1; i<tutorList.size(); i++) 
	{
		saveFile << tutorList[i].getFullName() << endl << tutorList[i].getSub() << endl;
		
		saveFile << tutorList[i].getGroupVec().size()-1 << endl;
		
		for(int j = 1; j < tutorList[i].getGroupVec().size(); j++) saveFile << tutorList[i].getGroupVec()[j] << endl;
		saveFile << tutorList[i].getLogin() << endl << tutorList[i].getPassword() << endl;
	}

	for(int i = 1; i<adminList.size(); i++)
	{
		saveFile << adminList[i].getName() << endl << adminList[i].getLogin() << endl << adminList[i].getPassword() << endl;
	}
	
	for(int i = 1; i<groupList.size(); i++)
	{
		saveFile << groupList[i] << endl;
	}
	
	saveFile.close();
}

void load(vector<Subject>& subjectList, vector<Student>& studentList, vector<Tutor>& tutorList, vector<string>& groupList, vector<Admin>& adminList)
{
	ifstream saveFile("save.txt");

	INIT_VECTORS(tutorList, studentList, subjectList, groupList);	
	
	int subCount, stuCount, tutCount, admCount, groCount;
	
	saveFile >> subCount;
	saveFile >> stuCount;
	saveFile >> tutCount;
	saveFile >> admCount;
	saveFile >> groCount;

	string trash;
	getline(saveFile, trash);
	
	for(int i = 1; i <= stuCount; i++)
	{
		string stuName;
		string gruName;
		
		getline(saveFile,stuName);
		getline(saveFile,gruName);
		
		Student stu{stuName, gruName};
		studentList.push_back(stu);
	}
	
	for(int i = 1; i <= subCount; i++)
	{
		string subName;
		getline(saveFile,subName);

		vector<int> temp = {1};
		std::vector<std::vector<int>> gradeVec;
		gradeVec.push_back(temp);
		
		for(int j = 1; j <= stuCount; j++)
		{
			string line;
			getline(saveFile, line);

			vector<int> vecInt;
			
			for(int k = 0; k<line.size(); k++) 
			{
				if(isdigit(line[k])) 
				{	
					vecInt.push_back(line[k]-'0');	
				}
			}
			gradeVec.push_back(vecInt);
		}		
		Subject sub(subName, studentList);
		subjectList.push_back(sub);
		subjectList[i].setVec(gradeVec);
	}	

	for(int i = 1; i <= tutCount; i++)
	{
		string fName;
		getline(saveFile, fName);
		
		string sName;
		getline(saveFile, sName);
		
		int subID;
		
		for(int j = 1; j<subjectList.size(); j++)
		{
			if(sName.compare(subjectList[j].getSubName())==0)
			{
				subID = j;
				break;
			}
		}
		
		vector<string> groupV;
		
		int h;
		saveFile >> h;
		
		getline(saveFile, trash);
		
		for(int j = 1; j<=h; j++)
		{
			string gr;
			getline(saveFile,gr);
			
			groupV.push_back(gr);
		}
		
		string l;
		getline(saveFile, l);
		
		string p;
		getline(saveFile,p);
		
		Tutor tut(fName, subjectList[subID], groupV, l, p);
		tutorList.push_back(tut);
	}
	
	for(int i = 1; i <= admCount; i++)
	{
		string fName;
		getline(saveFile, fName);
		
		string l;
		getline(saveFile, l);
		
		string p;
		getline(saveFile,p);
		
		Admin adm(fName, l, p);
		adminList.push_back(adm);
	}
	
	for(int i = 1; i <= groCount; i++)
	{
		string fName;
		getline(saveFile, fName);
		
		groupList.push_back(fName);
	}
	saveFile.close();
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

void INIT_VECTORS(vector<Tutor>& tutorList, vector<Student>& studentList, vector<Subject>& subjectList, vector<string>& groupList)
{
	subjectList.clear();
	studentList.clear();
	tutorList.clear();
	groupList.clear();
	
	Subject defSub("0", studentList);
	Student defStud{"0", "0"};
	string defGroup = "0";
	Tutor defTut("0", defSub, groupList, "0", "0");
	
	subjectList.push_back(defSub);
	studentList.push_back(defStud);
	groupList.push_back(defGroup);
	tutorList.push_back(defTut);
}

