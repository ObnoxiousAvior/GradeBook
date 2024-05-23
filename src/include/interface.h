#pragma once

#include <iostream>
#include <string>

namespace interface {
    //for admin
    /**
     * @brief greetingToAdmin
     */
    void greetingToAdmin();

    /**
     * @brief selectionPannelAdmin
     */
    void selectionPannelAdmin();///< OK

    /**
     * @brief removeGroupAdminMode
     */
    void removeGroupAdminMode();


    /**
     * @brief selectGroupToEdit
     */
    void selectGroupToEdit();

    /**
     * @brief optionGroupEdit
     */
    void optionGroupEdit();


    /**
     * @brief selectTutorToEdit
     */
    void selectTutorToEdit();

    /**
     * @brief optionTutorEdit
     */
    void optionTutorEdit();


    //for tutor
    /**
     * @brief greetingToTutor
     */
    void greetingToTutor();

    /**
     * @brief chooseGroupTutorMode
     */
    void chooseGroupTutorMode();

    //for student
    /**
     * @brief greetingToStudent
     */
    void greetingToStudent();
    /**
     * @brief selectionPannelStudent
     */
    void selectionPannelStudent();

    //program
    /**
     * @brief greetingToUser
     */
    void greetingToUser();
    /**
     * @brief longDiveder
     */
    void longDiveder();

    /**
     * @brief wrongFlag
     */
    void wrongFlag();

    /**
     * @brief removing
     */
    void removing();

    /**
     * @brief selectionRemove
     */
    void selectionRemove();

    /**
     * @brief wrongPassword
     */
    void wrongPassword();

    /**
     * @brief wrongLogin
     */
    void wrongLogin();

    /**
     * @brief creatingDB
     */
    void creatingDB();

    /**
     * @brief exit
     */
    void exit();
}
