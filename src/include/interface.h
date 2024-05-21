#pragma once

#include <iostream>
#include <string>

namespace interface {
    //for admin
    void greetingToAdmin();
    void selectionPannelAdmin();
    void removeGroupAdminMode();
    void selectGroupToEdit();
    void optionGroupEdit();
    void selectTutorToEdit();
    void optionTutorEdit();


    //for tutor
    void greetingToTutor();
    void chooseGroupTutorMode();

    //for student
    void greetingToStudent();
    void selectionPannelStudent();

    //program
    void greetingToUser();
    void longDiveder();
    void wrongFlag();
    void removing();
    void selectionRemove();
    void wrongPassword();
    void wrongLogin();
    void creatingDB();
    void exit();
}
