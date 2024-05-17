#pragma once
#include <string>
#include <vector>
class Prepod_name{
private:
    int _id;
    std::string _name;
public:
    int id() const;
    void setId( int &id);
    std::string name() const;
    void setName(const std::string &name);
};
class Prepod_pas{
private:
    int _id;
    std::string _pass;
public:
    int id() const;
    void setId( int &id);
    std::string pass() const;
    void setPass(const std::string &pass);
};
class Prepod_sub{
private:
    int _id;
    std::string _subj;
public:
    int id() const;
    void setId( int &id);
    std::string subj() const;
    void setSubj(const std::string &subj);
};
class Prepod_clas{
private:
    int _id;
    std::string _clas;
public:
    int id() const;
    void setId( int &id);
    std::string clas() const;
    void setClas(const std::string &clas);
};
class Student_clas{
private:
    int _id;
    std::string _clas;
public:
    int id() const;
    void setId( int &id);
    std::string clas() const;
    void setClas(const std::string &clas);
};
class Student_mark{
private:
    int _id;
    std::string _mark;
public:
    int id() const;
    void setId( int &id);
    std::string mark() const;
    void setMark(const std::string &mark);
};
class Student_name{
private:
    int _id;
    std::string _name;
public:
    int id() const;
    void setId( int &id);
    std::string name() const;
    void setName(const std::string &name);
};
