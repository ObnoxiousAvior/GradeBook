#include <iostream>
#include <string>

#include "include/interface.h"
#include "include/Modes.h"

using namespace std;

// interface functions

//for admin
void interface::greetingToAdmin(){
    cout << "+-----------------------------------------------------+" << endl
         //<< "|      Welcome, " << currentAdmin.getName() << "!     |" << endl
         << "|         Welcome, you've logged in as Admin!         |" << endl
         << "+-----------------------------------------------------+" << endl
         << "| What would you like to do?                          |" << endl
         << "| 1. Print student list                               |" << endl
         << "| 2. Add students                                     |" << endl
         << "| 3. Remove a student                                 |" << endl
         << "| 4. Edit student's info                              |" << endl
         << "+-----------------------------------------------------+" << endl
         << "| 5. Print groups                                     |" << endl
         << "| 6. Add groups                                       |" << endl
         << "| 7. Remove group                                     |" << endl
         << "| 8. Edit group                                       |" << endl
         << "+-----------------------------------------------------+" << endl
         << "| 9. Print tutor list                                 |" << endl
         << "| 10. Add tutors                                      |" << endl
         << "| 11. Remove a tutor                                  |" << endl
         << "| 12. Edit tutor's info                               |" << endl
         << "+-----------------------------------------------------+" << endl
         << "| 13. Print admin list                                |" << endl
         << "| 14. Add admin                                       |" << endl
         << "| 15. Remove this admin account                       |" << endl
         << "+-----------------------------------------------------+" << endl
         << "| 16. Save progress                                   |" << endl
         << "| 17. Load from file                                  |" << endl
         << "+-----------------------------------------------------+" << endl
         << "> ";
}

void interface::selectionPannelAdmin() {
    cout << "+-----------------------------------------------------+" << endl
         << "|          How would you like to log in as?           |" << endl
         << "+-----------------------------------------------------+" << endl
         << "| 1. Student                                          |" << endl
         << "| 2. Tutor                                            |" << endl
         << "| 3. Admin                                            |" << endl
         << "| 0. Exit                                             |" << endl
         << "+-----------------------------------------------------+" << endl
         << "> ";
}

//for tutor
void interface::greetingToTutor(){
    cout << "+-----------------------------------------------------+" << endl
         //<< "Welcome, " << currentTutor.getFullName() << "!" << endl
         << "|          Welcome, you've logged in as Tutor!        |" << endl
         << "+-----------------------------------------------------+" << endl
         << "| 1. Print student's grades on your subject           |" << endl
         << "| 2. Print group's grades on your subject             |" << endl
         << "| 3. Grade a student                                  |" << endl
         << "+-----------------------------------------------------+" << endl
         << "> ";
}

void interface::chooseGroupTutorMode(){
    cout << "+-----------------------------------------------------+" << endl
         << "|               Please, choose the group              |" << endl
         << "+-----------------------------------------------------+" << endl
         << "> ";
}

//for student
void interface::greetingToStudent(){
    cout << "+-----------------------------------------------------+" << endl
         << "|    You're now using the GradeBook as a student!     |" << endl
         << "+-----------------------------------------------------+" << endl
         << "| Groups:" << endl;
}

void interface::selectionPannelStudent(){
    cout << "+-----------------------------------------------------+" << endl
         << "|    Please, select the group you're studying in:     |" << endl
         << "+-----------------------------------------------------+" << endl
         << "> ";
}

//programm
void interface::removing(){
    cout << "+-----------------------------------------------------+" << endl
         << "|                 Successfully removed                |"<< endl
         << "+-----------------------------------------------------+" << endl;
}

void interface::selectionRemove(){
    cout << "+-----------------------------------------------------+" << endl
         << "|    Are you sure you want to delete this account?    |" << endl
         << "+-----------------------------------------------------+" << endl
         << "| 1. Yes                                              |" << endl
         << "| 2. No                                               |" << endl
         << "+-----------------------------------------------------+" << endl
         << "> ";
}

void interface::greetingToUser(){
    cout << "+=====================================================+" << endl
         << "|                Welcome to GradeBook!                |" << endl
         << "+=====================================================+" << endl;
}

void interface::wrongLogin(){
    cout << "+-----------------------------------------------------+" << endl
         << "|        Couldn't find the account. Try again!        |" << endl
         << "+-----------------------------------------------------+" << endl;
}

void interface::wrongPassword(){
    cout << "+-----------------------------------------------------+" << endl
         << "|              Wrong password. Try again!             |" << endl
         << "+-----------------------------------------------------+" << endl;
}

void interface::longDiveder(){
    cout << "+----------------------------------------------------------------------------+" << endl;
}

void interface::wrongFlag(){
    std::cout << "+=====================================================+" << std::endl
              << "|           It has to be an INTEGER NUMBER!           |" << std::endl
              << "+=====================================================+" << std::endl;
}

void interface::creatingDB(){

    cout << "\nLooks like the database doesn't have any groups yet!\n" << endl
         << "+-----------------------------------------------------+" << endl
         << "|          Would you like to add new groups?          |" << endl
         << "+-----------------------------------------------------+" << endl
         << "| 1. Yes                                              |"
         << "| 2. No                                               |"
         << "+-----------------------------------------------------+" << endl
         << "> ";
}

void interface::exit() {
    cout << "+=====================================================+" << endl
         << "|                   See you next time                 |" << endl
         << "+=====================================================+" << endl;
}

