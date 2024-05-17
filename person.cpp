#include "person.h"

using namespace std;
string Student_name::name() const {
    return _name;
}
int Student_name::id() const {
    return _id;
}
void Student_name::setId( int &id) {
    if (_id != id)
        _id = id;
}
void Student_name::setName(const string &name) {
    if (_name != name)
        _name = name;
}
string Prepod_name::name() const {
    return _name;
}
int Prepod_name::id() const {
    return _id;
}
void Prepod_name::setId( int &id) {
    if (_id != id)
        _id = id;
}
void Prepod_name::setName(const string &name) {
    if (_name != name)
        _name = name;
}
string Prepod_pas::pass() const {
    return _pass;
}
int Prepod_pas::id() const {
    return _id;
}
void Prepod_pas::setId(int &id) {
    if (_id != id)
        _id = id;
}
void Prepod_pas::setPass(const string &pass) {
    if (_pass != pass)
        _pass = pass;
}
string Prepod_sub::subj() const {
    return _subj;
}
int Prepod_sub::id() const {
    return _id;
}
void Prepod_sub::setId(int &id) {
    if (_id != id)
        _id = id;
}
void Prepod_sub::setSubj(const string &subj) {
    if (_subj != subj)
        _subj = subj;
}
string Prepod_clas::clas() const {
    return _clas;
}
int Prepod_clas::id() const {
    return _id;
}
void Prepod_clas::setId(int &id) {
    if (_id != id)
        _id = id;
}
void Prepod_clas::setClas(const string &clas) {
    if (_clas != clas)
        _clas = clas;
}
string Student_clas::clas() const {
    return _clas;
}
int Student_clas::id() const {
    return _id;
}
void Student_clas::setId(int &id) {
    if (_id != id)
        _id = id;
}
void Student_clas::setClas(const string &clas) {
    if (_clas != clas)
        _clas = clas;
}
std::string Student_mark::mark() const {
    return _mark;
}
int Student_mark::id() const {
    return _id;
}
void Student_mark::setId(int &id) {
    if (_id != id)
        _id = id;
}
void Student_mark::setMark(const std::string &mark) {
    if (_mark != mark)
        _mark = mark;
}
