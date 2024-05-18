#include <iostream>
#include <string>

#include "include/interface.h"
#include "include/Modes.h"

using namespace std;

// interface functions

void interface::greetingToUser(){
    cout << "+=====================================================+" << endl;
    cout << "|                Welcome to GradeBook!                |" << endl;
    cout << "+=====================================================+" << endl;
}

void interface::wrongLogin(){
    cout << "+-----------------------------------------------------+" << endl;
    cout << "|        Couldn't find the account. Try again!        |" << endl;
    cout << "+-----------------------------------------------------+" << endl;
}

void interface::wrongPassword(){
    cout << "+-----------------------------------------------------+" << endl;
    cout << "|              Wrong password. Try again!             |" << endl;
    cout << "+-----------------------------------------------------+" << endl;
}

void interface::greetingToTutor(){
    cout << "+-----------------------------------------------------+" << endl
         //<< "Welcome, " << currentTutor.getFullName() << "!" << endl
         << "|          Welcome, you've logged in as Tutor!        |" << endl
         << "+-----------------------------------------------------+" << endl
         << "|             What would you like to do?              |" << endl
         << "+-----------------------------------------------------+" << endl
         << "| 1. Print student's grades on your subject           |" << endl
         << "| 2. Print group's grades on your subject             |" << endl
         << "| 3. Grade a student                                  |" << endl
         << "+-----------------------------------------------------+" << endl
         << "> ";
}

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
         << "+-----------------------------------------------------+" << endl
         << "> ";
}

void interface::selectionPannel() {
    cout << "+-----------------------------------------------------+" << endl;
    cout << "|                     Log in as?                      |" << endl;
    cout << "+-----------------------------------------------------+" << endl;
    cout << "| 1. Student                                          |" << endl;
    cout << "| 2. Tutor                                            |" << endl;
    cout << "| 3. Admin                                            |" << endl;
    cout << "| 0. Exit                                             |" << endl;
    cout << "+-----------------------------------------------------+" << endl;
    cout << "> ";
}

void interface::exit() {
    cout << "+=====================================================+" << endl;
    cout << "|                   See you next time                 |" << endl;
    cout << "+=====================================================+" << endl;
}

