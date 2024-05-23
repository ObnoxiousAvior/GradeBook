#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

#include "include/Platform.h"
#include "include/Users.h"
#include "include/Subject.h"
#include "include/Utils.h"
#include "include/interface.h"

using namespace std;
using namespace interface;
// GENERAL USER FUNCTIONS

// TUTOR FUNCTIONS

void Tutor::printStudentGrades(vector<Student> studentList) //Выводит оценки студента(функция для преподователя)
{
	print(studentGroups);
    chooseGroupTutorMode();

	int groupID;
	utils::queryVar(groupID);

	system(CLEARSCR);

	printGroup(studentList, studentGroups[groupID]);

    cout << "\n| Please, select the student:\n> ";

	int stuID;
	utils::queryVar(stuID);
	
	system(CLEARSCR); 
	
    cout << "+-----------------------------------------------------+" << endl
         << "| The GradeBook page of " << studentList[stuID].fullName << endl
         << "+-----------------------------------------------------+" << endl;

	cout << "| " << subject.getSubName() << " |: ";
	subject.printGrades(stuID, FORMATTED);
    cout << "+-----------------------------------------------------+" << endl;
}

void Tutor::printGroupGrades(vector<Student> studentList) //Выводит оценки группы(функция для преподователя)
{
	print(studentGroups);
    chooseGroupTutorMode();

	int groupID;
	utils::queryVar(groupID);

	system(CLEARSCR);

    cout << "+-----------------------------------------------------+" << endl
         << "| The GradeBook page of " <<  studentGroups[groupID] << endl
         << "+-----------------------------------------------------+" << endl;

	for (int i = 1; i < studentList.size(); i++) 
	{	 
		if (studentList[i].studentGroup.compare(studentGroups[groupID]) == 0)
		{
			cout << "| " << subject.getSubName() << " |: ";
			subject.printGrades(i, FORMATTED);
		}
	}
    cout << "+-----------------------------------------------------+" << endl;
}

void Tutor::gradeStudent() //Выставляет оценку ученику(для преподователя)
{
    print(studentGroups);
    chooseGroupTutorMode();

	int groupID;
	utils::queryVar(groupID);
	
	subject.grade(studentGroups[groupID]);
}

// ADMIN FUNCTIONS

void Admin::addSubject(vector<Subject>& subjectList, vector<Student>& studentList) //Добавляет новый предмет(функция для администратора)
{
    cout << "| Type in the subject name:\n> ";
	
	string name;
	std::getline(std::cin, name);
	
	Subject sub(name, studentList);
	subjectList.push_back(sub);
}

void Admin::addStudents(vector<Student>& studentList, vector<string>& groupList) //Добавляет новых студентов(функция для администратора)
{
    cout <<  "| How many students would you like to add?\n> ";
	
	int n;
	utils::queryVar(n);
	
	if (n<=0) return;
	
    cout << "+-----------------------------------------------------+" << endl;
	
	for(int i = 1; i <= n; i++)
	{
        cout << "| Student " << i << ":" << endl << "| Type in the student's full name: ";
		
		string stuName;
		std::getline(std::cin, stuName);
	
		
		if (groupList.size() == 0) 
		{
            creatingDB();
		
			int select;
			utils::queryVar(select);
			
			if (select != 1) return;
			else addGroups(groupList);
		}
		
        cout << "+-----------------------------------------------------+" << endl;
		
		do	{
		print(groupList);
		
		cout << endl;
        cout << "| Select: ";
		
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
    cout << "S| uccessfully added " << n << " student(s)" << endl;
}


void Admin::addGroups(vector<string>& groupList) //Добавляет новых студентов(функция для администратора)
{
    cout << "| How many groups would you like to add?\n> ";
	
	int n;
	utils::queryVar(n);
	
	for(int i = 1; i <= n; i++)
	{
        cout << "| Group " << i << ":" << endl << "| Type in a name for a group: ";

		std::string groupName;
		std::getline(std::cin, groupName);
		
		groupList.push_back(groupName);
	}
	system(CLEARSCR);
	cout << "Successfully added " << n << " group(s)" << endl;
}


void Admin::addTutors(vector<Tutor>& tutorList, vector<Subject>& subjectList, vector<string>& groupList, vector<Student>& studentList) //Добавляет новых преподователей(функция для администратора)
{
	print(tutorList);
    cout << "\n| How many tutors would you like to add?\n> ";
	
	int n;
	utils::queryVar(n);
	
	for(int i = 1; i <= n; i++)
	{
		system(CLEARSCR);
        cout << "| Tutor " << i << ":" << endl << "| Type in the tutor's first name: ";
		
		string tutorName;
		std::getline(std::cin, tutorName);
		
		int selectSub;
		
		do{
        cout << "| Here's a full subject list:\n";
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
		
        cout << "+--------------------------------------------------------------------------------------------+" << endl;
        cout << "Please, choose the groups your tutor will educate (ex: 1 0 , 2 4 0, 6 2 3 0, etc. 0 to exit):";
        cout << "> ";

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
		
        cout << "| Please, enter a login:\n|";
		
		while(getchar()!='\n');
		string log;
		std::getline(std::cin, log);
		
        cout << "| Please, enter a password:\n|";
		string pass;
		std::getline(std::cin, pass);
		
		Tutor newTut(tutorName, subjectList[selectSub], groupVec, log, pass);
		
		tutorList.push_back(newTut);
	}
}



void Admin::addAdmins(vector<Admin>& adminList) //Добавляет новых администраторов(функция для администратора)
{
	print(adminList);
    cout << "+-----------------------------------------------------+" << endl;
    cout << "| How many administrators would you like to add?\n> ";
	
	int n;
	utils::queryVar(n);
	
	for(int i = 1; i <= n; i++)
	{
		system(CLEARSCR);
        cout << "| Tutor " << i << ":" << endl << "| Type in a name of an admin:\n|";

		std::string adminName;
		std::getline(std::cin, adminName);
		
		system(CLEARSCR);

        cout << "| Please, enter a login:\n|";

		string log;
		std::getline(std::cin, log);
		
        cout << "| Please, enter a password:\n|";
		
		string pass;
		std::getline(std::cin, pass);
		
		Admin newAdm(adminName, log, pass);
		
		adminList.push_back(newAdm);
	}
}

// PRINT FUNCTIONS

void print(vector<Student> studentList){ //функция вывода студентов
	system(CLEARSCR);
    std::cout << "| Here's a full student list: " << std::endl;
	for(int i = 1; i<studentList.size(); i++) std::cout << i << ". " << studentList[i].fullName << " | Group: " << studentList[i].studentGroup << std::endl; 
}

void print(vector<string> groupList){ //функция вывода групп
	system(CLEARSCR);
    cout << "| Here's a full group list: " << endl;
	for(int i = 1; i < groupList.size(); i++) std::cout << i << ". " << groupList[i] << std::endl;	
}
void print(vector<Tutor> tutorList){ //функция вывода преподователей
	system(CLEARSCR);
    cout << "| Here's a full tutor list: " << endl;
	for(int i = 1; i < tutorList.size(); i++) 
	{
		cout << i << ". " << tutorList[i].getFullName() << " | Subject: " << tutorList[i].getSub() << endl << "Groups: ";
		for(int j = 1; j<tutorList[i].getGroupVec().size(); j++) cout << tutorList[i].getGroupVec()[j] << ' ';
        cout << endl << "_______________________________________________________" << endl;
	}	
}
void print(vector<Admin> adminList){ //функция вывода администраторов
	system(CLEARSCR);
    std::cout << "| Here's a full admin list: " << std::endl;
	for(int j = 1; j < adminList.size(); j++) std::cout << j << ". " << adminList[j].getName() << std::endl;
}


void Admin::removeStudent(vector<Student>& studentList)  //Удаление студента(функция для администратора)
{
	print(studentList);
	
    cout << "+-----------------------------------------------------+" << endl
         << "| Choose a student to remove" << endl
         << "> ";
	
	int select;
	utils::queryVar(select);
	
	studentList.erase(studentList.begin()+select);
	
	system(CLEARSCR);
    removing();
}

void Admin::editStudent(vector<Student>& studentList, vector<std::string>& groupList) //Изменение информации о студенте(функция для администратора)
{
	print(studentList);
		
    cout << "+-----------------------------------------------------+" << endl
         << "| Choose a student to edit" << endl
         << "> ";
	
	int select;
	utils::queryVar(select); 
	
	cout << "1. Edit a name\n2. Edit a group\n0. Exit\n"; 
	
	int name_or_group;
	utils::queryVar(name_or_group);
	
	if(name_or_group == 0) return;
	else if (name_or_group == 1) 
	{
        cout << "| Type in the student's full name:\n> ";
		
		string name;
		utils::queryVar(name);
		
		studentList[select].fullName = name;
	}
	else if (name_or_group == 2) 
	{
		do	{
		print(groupList);
		cout << groupList.size() << ". Add new groups" << endl;
		
        cout << "| Select: ";
		
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

void Admin::removeGroup(vector<string>& groupList, vector<Student>& studentList, vector<Tutor>& tutorList) //Удаление группы(функция для администратора)
{
	print(groupList);
    removeGroupAdminMode();
	
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
			
            cout << "+-----------------------------------------------------+" << endl;
            cout << "| Student " << studentList[i].fullName << " has no group.\n| Select a new group for them:\n> ";
			
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

void Admin::editGroup(vector<Student>& studentList, vector<std::string>& groupList) //Изменение информации о группе(функция для администратора)
{
	print(groupList);
    selectGroupToEdit();
	
	int selectGroup;
	utils::queryVar(selectGroup);
	
    optionGroupEdit();
	
	int exit;
	utils::queryVar(exit);
	
	if(exit == 0) return;
	
	std::string buffer;
    cout << "| The new name for " << groupList[selectGroup] << ": ";
	utils::queryVar(buffer);
	
	string prevName = groupList[selectGroup];
	groupList[selectGroup] = buffer;
	
	for(int i = 1; i<studentList.size(); i++)
	{
		if(studentList[i].studentGroup.compare(prevName) == 0) studentList[i].studentGroup = buffer;
	}
	
	system(CLEARSCR);
}

void Admin::removeTutor(vector<Tutor>& tutorList) //Удаление преподователя(функция для администратора)
{
	print(tutorList);
    selectionRemove();
	
	int select;
	utils::queryVar(select);
	
	tutorList[select] = tutorList[tutorList.size()-1];
	
	tutorList.pop_back();
	
    system(CLEARSCR);
    removing();
}

void Admin::editTutor(vector<Tutor>& tutorList, vector<Subject>& subjectList, vector<string>& groupList, vector<Student>& studentList) //Изменение информации о преподователе(функция для администратора)
{
	print(tutorList);
    selectTutorToEdit();
	
	int select;
	utils::queryVar(select);
	
    optionTutorEdit();
	
	int exit;
	utils::queryVar(exit);
	
	if(exit == 0) return;
	else if (exit == 1) 
	{
        cout << "| Type in the tutor's full name:\n> ";
		
		string name;
		std::getline(std::cin,name);
		
		tutorList[select].setName(name);
	}
	else if(exit == 2)
	{
		
		int selectSub;
		
		do{
        cout << "| Here's a full subject list:\n";
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
		
        longDiveder();
        cout << "| Please, choose the groups your tutor will educate \n(ex: 1 0 , 2 4 0, 6 2 3 0, etc. 0 to exit): ";
		
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

void Admin::removeThisAdmin(vector<Admin>& adminList) //Удаление данного администратора(функция для администратора)
{
    selectionRemove();
		
	int select;
	utils::queryVar(select);
	
	if(select != 1) return;
	
	adminList.erase(adminList.begin()+select);
	
	system(CLEARSCR);
    removing();
}

void save(vector<Subject>& subjectList, vector<Student>& studentList, vector<Tutor>& tutorList, vector<string>& groupList, vector<Admin>& adminList) //Функция сохранения
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

void load(vector<Subject>& subjectList, vector<Student>& studentList, vector<Tutor>& tutorList, vector<string>& groupList, vector<Admin>& adminList) //Функция загрузки
{
    ifstream saveFile("save.txt");

    INIT_VECTORS(tutorList, studentList, subjectList, adminList, groupList);

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

void INIT_VECTORS(vector<Tutor>& tutorList, vector<Student>& studentList, vector<Subject>& subjectList, vector<Admin>& adminList, vector<string>& groupList) //Начальная инициализация векторов
{

    subjectList.clear();
    studentList.clear();
    tutorList.clear();
    groupList.clear();
    adminList.clear();

	Subject defSub("0", studentList);
	Student defStud{"0", "0"};
	string defGroup = "0";
	Tutor defTut("0", defSub, groupList, "0", "0");
    Admin defaultAdmin("Default Admin", "admin", "admin");

	subjectList.push_back(defSub);
	studentList.push_back(defStud);
	groupList.push_back(defGroup);
	tutorList.push_back(defTut);
    adminList.push_back(defaultAdmin);
}

