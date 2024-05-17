#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "functions.h"

using namespace std;

void functions::save_Name(std::map<int, string> Prepod_name, const int &n) {
    ofstream file("Name.txt");
    if (!file.is_open()) {
        cout << "save: file error" << endl;
        return;
    }
    file << n << endl;
    for (auto it = Prepod_name.begin(); it != Prepod_name.end(); ++it)
      {
         file << it->first << "   "<< it->second << endl;
      }
}
void functions::save_Id(int &id) {
    ofstream file("Counter.txt");
    if (!file.is_open()) {
        cout << "save: file error" << endl;
        return;
    }
    file << id << endl;
}
void functions::save_stdname(std::map<int, string> Student_name, const int &n) {
    ofstream file("Stdname.txt");
    if (!file.is_open()) {
        cout << "save: file error" << endl;
        return;
    }
    file << n << endl;
    for (auto it = Student_name.begin(); it != Student_name.end(); ++it)
      {
         file << it->first << "   "<< it->second << endl;
      }
}
void functions::save_Pas(std::map<int, string> Prepod_pass, const int &n) {
    ofstream file("Pass.txt");
    if (!file.is_open()) {
        cout << "save: file error" << endl;
        return;
    }
    file << n << endl;
    for (auto it = Prepod_pass.begin(); it != Prepod_pass.end(); ++it)
      {
         file << it->first << "   "<< it->second << endl;
      }
}
void functions::save_subj(std::map<int, string> Prepod_subj, const int &n) {
    ofstream file("Subj.txt");
    if (!file.is_open()) {
        cout << "save: file error" << endl;
        return;
    }
    file << n << endl;
    for (auto it = Prepod_subj.begin(); it != Prepod_subj.end(); ++it)
      {
         file << it->first << "   "<< it->second << endl;
      }
}
void functions::save_class(std::map<int, string> Prepod_class, const int &n) {
    ofstream file("Class.txt");
    if (!file.is_open()) {
        cout << "save: file error" << endl;
        return;
    }
    file << n << endl;
    for (auto it = Prepod_class.begin(); it != Prepod_class.end(); ++it)
      {
         file << it->first << "   "<< it->second << endl;
      }
}
void functions::save_stdclass(std::map<int, string> Student_class, const int &n) {
    ofstream file("stdclass.txt");
    if (!file.is_open()) {
        cout << "save: file error" << endl;
        return;
    }
    file << n << endl;
    for (auto it = Student_class.begin(); it != Student_class.end(); ++it)
      {
         file << it->first << "   "<< it->second << endl;
      }
}
void functions::save_stdmark(std::map<int, std::string> Student_mark, const int &n) {
    ofstream file("Marks.txt");
    if (!file.is_open()) {
        cout << "save: file error" << endl;
        return;
    }
    file << n << endl;
    for (auto it = Student_mark.begin(); it != Student_mark.end(); ++it)
      {

         file << it->first << "   "<< it->second << endl;
      }
}
void functions::load_Id(int &id){
    ifstream file("Counter.txt");
    if (!file.is_open()) {
        cout << "load: file error" << endl;
    }
    file >> id;
    if (id < 0) {
        cout << "load: id error" << endl;
    }
    file.close();
}
Prepod_name * functions::load_name(int &n) {
    ifstream file("Name.txt");
    if (!file.is_open()) {
        cout << "load: file error" << endl;
        return nullptr;
    }
    file >> n;
    if (n <= 0) {
        cout << "load: n error" << endl;
        return nullptr;
    }
    Prepod_name * arr= new Prepod_name[n];
    for (int i = 0; i < n; i++) {
        int id;
        string name;
        file >> id >> name;
        arr[i].setId(id);
        arr[i].setName(name);
    }
    file.close();
    return arr;
}
Student_name * functions::load_stdname(int &n) {
    ifstream file("Stdname.txt");
    if (!file.is_open()) {
        cout << "load: file error" << endl;
        return nullptr;
    }
    file >> n;
    if (n <= 0) {
        cout << "load: n error" << endl;
        return nullptr;
    }
    Student_name * arr= new Student_name[n];
    for (int i = 0; i < n; i++) {
        int id;
        string name;
        file >> id >> name;
        arr[i].setId(id);
        arr[i].setName(name);
    }
    file.close();
    return arr;
}
Prepod_pas * functions::load_pass(int &n) {
    ifstream file("Pass.txt");
    if (!file.is_open()) {
        cout << "load: file error" << endl;
        return nullptr;
    }
    file >> n;
    if (n <= 0) {
        cout << "load: n error" << endl;
        return nullptr;
    }
    Prepod_pas * arr= new Prepod_pas[n];
    for (int i = 0; i < n; i++) {
        int id;
        string pass;
        file >> id >> pass;
        arr[i].setId(id);
        arr[i].setPass(pass);
    }
    file.close();
    return arr;
}
Prepod_sub * functions::load_sub(int &n) {
    ifstream file("Subj.txt");
    if (!file.is_open()) {
        cout << "load: file error" << endl;
        return nullptr;
    }
    file >> n;
    if (n <= 0) {
        cout << "load: n error" << endl;
        return nullptr;
    }
    Prepod_sub * arr= new Prepod_sub[n];
    for (int i = 0; i < n; i++) {
        int id;
        string pass;
        file >> id >> pass;
        arr[i].setId(id);
        arr[i].setSubj(pass);
    }
    file.close();
    return arr;
}
Prepod_clas * functions::load_clas(int &n) {
    ifstream file("Class.txt");
    if (!file.is_open()) {
        cout << "load: file error" << endl;
        return nullptr;
    }
    file >> n;
    if (n <= 0) {
        cout << "load: n error" << endl;
        return nullptr;
    }
    Prepod_clas * arr= new Prepod_clas[n];
    for (int i = 0; i < n; i++) {
        int id;
        string pass;
        file >> id >> pass;
        arr[i].setId(id);
        arr[i].setClas(pass);
    }
    file.close();
    return arr;
}
Student_clas * functions::load_stdclas(int &n) {
    ifstream file("stdclass.txt");
    if (!file.is_open()) {
        cout << "load: file error" << endl;
        return nullptr;
    }
    file >> n;
    if (n <= 0) {
        cout << "load: n error" << endl;
        return nullptr;
    }
    Student_clas * arr= new Student_clas[n];
    for (int i = 0; i < n; i++) {
        int id;
        string clas;
        file >> id >> clas;
        arr[i].setId(id);
        arr[i].setClas(clas);
    }
    file.close();
    return arr;
}
Student_mark * functions::load_stdmark(int &n) {
    ifstream file("Marks.txt");
    if (!file.is_open()) {
        cout << "load: file error" << endl;
        return nullptr;
    }
    file >> n;
    if (n <= 0) {
        cout << "load: n error" << endl;
        return nullptr;
    }
    Student_mark * arr= new Student_mark[n];
    for (int i = 0; i < n; i++) {
        int id;
        string mark;
        file >> id >> mark;
        arr[i].setId(id);
        arr[i].setMark(mark);
    }
    file.close();
    return arr;
}
