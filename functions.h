#pragma once
#include<map>
#include <map>
#include <string>
#include <vector>
#include "person.h"

namespace functions {
void save_Pas(std::map<int, std::string> Prepod_pass, const int &n);
void save_Name(std::map<int, std::string> Prepod_name, const int &n);
void save_class(std::map<int, std::string> Prepod_class, const int &n);
void save_subj(std::map<int, std::string> Prepod_subj, const int &n);
void save_stdclass(std::map<int, std::string> Student_class, const int &n);
void save_stdmark(std::map<int,std::string> Student_mark, const int &n);
void save_stdname(std::map<int,std::string> Student_name, const int &n);
void save_Id(int &id);
void load_Id(int &id);
Prepod_pas * load_pass(int &n);
Prepod_sub * load_sub(int &n);
Prepod_clas * load_clas(int &n);
Student_clas * load_stdclas(int &s);
Student_mark * load_stdmark(int &n);
Prepod_name * load_name(int &n);
Student_name * load_stdname(int &n);
}
