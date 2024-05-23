#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Student.h"
#include "Subject.h"
#include "Users.h"

/**
 * @brief studentMode
 * @param [in] studentList
 * @param [in] subjectList
 * @param [in] groupList
 */
void studentMode(std::vector<Student> studentList,
					  std::vector<Subject> subjectList,
					  std::vector<std::string> groupList);

void tutorMode(std::vector<Student>& studentList,
					std::vector<Subject>& subjectList,
					std::vector<Tutor>& tutorList,
					std::vector<Admin>& adminList,
					std::vector<std::string>& groupList);

void adminMode(std::vector<Student>& studentList,
					std::vector<Subject>& subjectList,
					std::vector<Tutor>& tutorList,
					std::vector<Admin>& adminList,
					std::vector<std::string>& groupList);
					


