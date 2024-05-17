#include <iostream>
#include <string>

#include "include/interface.h"

using namespace std;

// interface functions

void interface::greetingToUser(){
    cout << "+-----------------------------------------------------+" << endl;
    cout << "|                Welcome to GradeBook!                |" << endl;
    cout << "+-----------------------------------------------------+" << endl;
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

void interface::admin_menu() {
    cout << "+---------------------------------------+" << endl;
    cout << "| What database would you like to edit? |" << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "| 1. Tutors db                        |" << endl;
    cout << "| 2. Students db                        |" << endl;
    cout << "| 3. Exit                               |" << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "> ";
}

void interface::exit() {
    cout << "+-----------------------------------------------------+" << endl;
    cout << "|                   See you next time                 |" << endl;
    cout << "+-----------------------------------------------------+" << endl;
}

