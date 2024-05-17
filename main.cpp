#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "person.h"
#include "functions.h"
//A.2.3.4.5.6.7.8
using namespace std;
using namespace functions;

int main() {
    std::map<int, std::string> Prepod_pass;
    std::map<int, std::string> Prepod_namee;
    std::map<int, std::string> Student_namee;
    std::map<int, std::string> Prepod_subj;
    std::map<int, std::string> Prepod_class;
    std::map<int, std::string> Student_class;
    std::map<int, std::string> Student_marks;
    int n{};
    int s{};
    int a=0;
    int c,f{};
    int key=0,kay=0;
    int type,d;
    int adm=0;
    int admt;
    int p=0;
    int id,idd;
    string pass,name,subj,clss,name2,marks,mark;
    n=0;
    Prepod_pas * arr2 = nullptr;
    Prepod_name * arr11 = nullptr;
    Student_name * arr12 = nullptr;
    Prepod_sub * arr3 = nullptr;
    Prepod_clas * arr4 = nullptr;
    Student_clas * arr9=nullptr;
    Student_mark * arr10=nullptr;
    cout<<"1-admin,2-teacher,3-student"<<endl;
    cin>>type;

    if(type==1){
        while(1){
        cout<<"1-teachers,2-students,3-exit"<<endl;
        cin>>adm;
        if(adm==1){
            cout<<"1-create full new array of teachers,2-add new teachers,3-delete teachers,4-load list of teachers"<<endl;
            cin>>admt;
                if(admt==1){                                    //NEW ARRAY OF TEATHERS
                    Prepod_pass.clear();
                    Prepod_subj.clear();
                    Prepod_class.clear();
                    Prepod_namee.clear();
                   cout<<"create array for: ";
                   cin>>n;
                   for (int i = 0; i < n; i++)
                     {
                       id=i;
                       cout<<"Enter name:";
                       cin>>name;
                       cout<<"Enter pass:";
                       cin>>pass;
                       cout<<"Enter subject:";
                       cin>>subj;
                       cout<<"Enter class:";
                       cin>>clss;
                       Prepod_pass.insert(pair<int,string>(id,pass));
                       Prepod_subj.insert(pair<int,string>(id,subj));
                       Prepod_class.insert(pair<int,string>(id,clss));
                       Prepod_namee.insert(pair<int,string>(id,name));
                       save_Id(id);
                     }
                   save_Pas(Prepod_pass,n);
                   save_subj(Prepod_subj,n);
                   save_class(Prepod_class,n);
                   save_Name(Prepod_namee,n);
                }
                if(admt==2){                                    //ADD NEW TEACHER
                    arr3 = load_sub(n);
                    arr2 = load_pass(n);
                    arr4=load_clas(n);
                    arr11=load_name(n);
                    load_Id(id);
                    id=id+1;
                    cout << "Name: ";
                    cin >> name;
                    cout << "Pass: ";
                    cin >> pass;
                    cout<<"Subject:";
                    cin>>subj;
                    cout<<"Class:";
                    cin>>clss;
                    for(int i=0;i<n;i++){
                            Prepod_pass.insert(pair<int,string>(arr2[i].id(),arr2[i].pass()));
                            Prepod_subj.insert(pair<int,string>(arr2[i].id(),arr3[i].subj()));
                            Prepod_class.insert(pair<int,string>(arr2[i].id(),arr4[i].clas()));
                            Prepod_namee.insert(pair<int,string>(arr2[i].id(),arr11[i].name()));
                    }
                    Prepod_pass.insert(pair<int,string>(id,pass));
                    Prepod_subj.insert(pair<int,string>(id,subj));
                    Prepod_class.insert(pair<int,string>(id,clss));
                    Prepod_namee.insert(pair<int,string>(id,name));
                    save_Pas(Prepod_pass, n+1);
                    save_subj(Prepod_subj,n+1);
                    save_class(Prepod_class,n+1);
                    save_Name(Prepod_namee,n+1);
                    save_Id(id);
                }
                if(admt==3){                                    //DELETE TEACHER
                    cout<<"Enter name of techer to delete: "<<endl;
                    cin>>name;
                    arr3 = load_sub(n);
                    arr2 = load_pass(n);
                    arr4=load_clas(n);
                    arr11=load_name(n);
                    load_Id(id);
                    for(int i=0;i<n;i++){
                        if(arr11[i].name()==name){
                            cout<<"\nfound:"<<endl;
                            cout << arr11[i].name() << "   ";
                            cout << arr2[i].pass() << "   ";
                            cout << arr4[i].clas() << "   ";
                            cout << arr3[i].subj() << endl;
                            key=1;
                        }
                    }
                    if(key==1){
                        arr11=load_name(n);
                        for(int i=0;i<n;i++){
                            if(arr11[i].name()==name){
                                Prepod_pass.erase(arr11[i].id());
                                Prepod_subj.erase(arr11[i].id());
                                Prepod_class.erase(arr11[i].id());
                                Prepod_namee.erase(arr11[i].id());
                                p++;
                                id=id-1;
                                save_Id(id);
                            }
                        }
                            save_Pas(Prepod_pass, n-p);
                            save_subj(Prepod_subj,n-p);
                            save_class(Prepod_class,n-p);
                            save_Name(Prepod_namee,n-p);
                            p=0;

                    }
                    if(key==0) cout<<"\nnot found"<<endl;
                     key=0;
                }
                if(admt==4){                                    //LOAD LIST OF TEACHERS
                        cout << "\nloading from txt file:" << endl;
                        arr3 = load_sub(n);
                        arr2 = load_pass(n);
                        arr4=load_clas(n);
                        arr11=load_name(n);
                        cout << "loaded n=" << n << endl;
                        if (!arr3) {
                            cout << "arr is null" << endl;
                            return 0;
                        }
                        for (int i = 0; i < n; i++) {
                            cout << arr11[i].name() << "   ";
                            cout << arr2[i].pass() << "   ";
                            cout << arr4[i].clas() << "   ";
                            cout << arr3[i].subj() << endl;
                        }
                    }
            }

        if(adm==2){
        cout<<"1-create full new array of students,2-add new student,3-delete student,4-load list of student"<<endl;
        cin>>admt;
            if(admt==1){                                    //NEW ARRAY OF STUDENTS
               Student_class.clear();
               Student_namee.clear();
               Student_marks.clear();
               load_Id(id);
               cout<<"create array for: ";
               cin>>n;
               for (int i = 0; i < n; i++)
                 {
                   id=id+1;
                   cout<<"Enter name:";
                   cin>>name;
                   cout<<"Enter class:";
                   cin>>clss;
                   marks="-";
                   Student_namee.insert(pair<int,string>(id,name));
                   Student_class.insert(pair<int,string>(id,clss));
                   Student_marks.insert(pair<int,string>(id,marks));
                 }
               save_stdclass(Student_class,n);
               save_stdname(Student_namee,n);
               save_stdmark(Student_marks,n);
               save_Id(id);
            }
            if(admt==2){                                    //ADD NEW STUDENT
                load_Id(id);
                                arr9=load_stdclas(n);
                                arr12=load_stdname(n);
                                arr10=load_stdmark(n);
                                id=id+1;
                                cout << "Name: ";
                                cin >> name;
                                cout<<"Class:";
                                cin>>clss;
                                marks="-";
                                for(int i=0;i<n;i++){
                                        Student_class.insert(pair<int,string>(arr9[i].id(),arr9[i].clas()));
                                        Student_namee.insert(pair<int,string>(arr9[i].id(),arr12[i].name()));
                                        Student_marks.insert(pair<int,string>(arr9[i].id(),arr10[i].mark()));
                                }
                                Student_namee.insert(pair<int,string>(id,name));
                                Student_class.insert(pair<int,string>(id,clss));
                                Student_marks.insert(pair<int,string>(id,marks));
                                save_stdclass(Student_class,n+1);
                                save_stdname(Student_namee,n+1);
                                save_stdmark(Student_marks,n+1);
                                save_Id(id);
            }
            if(admt==3){                                    //DELETE STUDENT
                cout<<"Enter name of student to delete: "<<endl;
                cin>>name;
                arr9=load_stdclas(n);
                arr12=load_stdname(n);
                for(int i=0;i<n;i++){
                    if(arr12[i].name()==name){
                        cout<<"\nfound:"<<endl;
                        cout << arr12[i].name() << "   ";
                        cout<<arr9[i].clas()<<endl;
                        key=1;
                    }
                }
                if(key==1){
                    arr9=load_stdclas(n);
                    for(int i=0;i<n;i++){
                        if(arr12[i].name()==name){
                            Student_class.erase(arr12[i].id());
                            Student_namee.erase(arr12[i].id());
                            Student_marks.erase(arr12[i].id());
                            p++;
                        }
                    }
                        save_stdclass(Student_class, n-p);
                        save_stdname(Student_namee, n-p);
                        save_stdmark(Student_marks,n-p);

                }
                if(key==0) cout<<"\nnot found"<<endl;
                 key=0;
            }
            if(admt==4){                                    //LOAD LIST OF STUDENTS
                    cout << "\nloading from txt file:" << endl;
                    arr9=load_stdclas(n);
                    arr12=load_stdname(n);
                    cout << "loaded n=" << n << endl;
                    if (!arr9) {
                        cout << "arr is null" << endl;
                        return 0;
                    }
                    for (int i = 0; i < n; i++) {
                        cout << arr12[i].name() << "   ";
                        cout << arr9[i].clas() <<endl;
                    }
                }

        }
         if(adm==3) return 0;
        }
    }
    if(type==2){
        cout<<"Enter name:  ";
        cin>>name;
        cout<<"Enter password:  ";
        cin>>pass;
        arr2=load_pass(n);
        arr11=load_name(n);
        for(int i=0;i<n;i++){
            if(arr11[i].name()==name&&arr2[i].pass()==pass){
                cout<<"Welcome "<< arr11[i].name()<<endl;
            a=1;
            }
        }
        if(a==0){
            cout<<"Name or password error"<<endl;
            return 0;
        }
        while(1){
        if(a==1){
            cout<<"1-list of your students,2-change student marks,3-exit"<<endl;
            cin>>c;
            if(c==1){
                arr10=load_stdmark(f);
                arr9=load_stdclas(f);
                arr4=load_clas(s);
                arr11=load_name(s);
                arr12=load_stdname(f);
                for(int i=0;i<s;i++){
                    if(arr11[i].name()==name){
                        for(int g=0;g<f;g++){
                            if(arr4[i].clas()==arr9[g].clas()){
                                cout<<arr12[g].name()<<"   ";
                                for(int q=0;q<f;q++){
                                    if(arr9[g].id()==arr10[q].id()){
                                        cout<<arr10[q].mark()<<endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if(c==2){
                arr4=load_clas(s);
                arr9=load_stdclas(f);
                arr10=load_stdmark(f);
                arr11=load_name(s);
                arr12=load_stdname(f);
                cout<<"Enter student name:   ";
                cin>>name2;
                for(int i=0;i<f;i++){
                    if(arr12[i].name()==name2){
                    idd=arr12[i].id();
                    kay++;
                    }
                }
                if(kay==0) cout<<"Student not found"<<endl;
                if(kay==1){
                    for(int i=0;i<f;i++){
                        if(arr10[i].id()==idd){
                            cout<<"Enter new marks:   ";
                            cin>>marks;
                            Student_namee.insert(pair<int,string>(idd,name2));
                            Student_class.insert(pair<int,string>(idd,arr9[i].clas()));
                            Student_marks.insert(pair<int,string>(idd,marks));
                        }
                        else{
                            Student_namee.insert(pair<int,string>(arr10[i].id(),arr12[i].name()));
                            Student_class.insert(pair<int,string>(arr10[i].id(),arr9[i].clas()));
                            Student_marks.insert(pair<int,string>(arr10[i].id(),arr10[i].mark()));
                        }
                    }
                    save_stdclass(Student_class,f);
                    save_stdname(Student_namee,f);
                    save_stdmark(Student_marks,f);
                    Student_class.clear();
                    Student_namee.clear();
                    Student_marks.clear();
                }
                if(kay>1){
                    for(int i=0;i<f;i++){
                        if(arr12[i].name()==name2)
                        cout<<arr12[i].name()<<"   "<<arr10[i].mark()<<"   "<<arr12[i].id()<<endl;
                    }
                    cout<<"Enter id of student to change marks:  ";
                    cin>>idd;
                    for(int i=0;i<f;i++){
                        if(arr10[i].id()==idd){
                            cout<<"Enter new marks:   ";
                            cin>>marks;
                            Student_namee.insert(pair<int,string>(idd,name2));
                            Student_class.insert(pair<int,string>(idd,arr9[i].clas()));
                            Student_marks.insert(pair<int,string>(idd,marks));
                        }
                        else{
                            Student_namee.insert(pair<int,string>(arr10[i].id(),arr12[i].name()));
                            Student_class.insert(pair<int,string>(arr10[i].id(),arr9[i].clas()));
                            Student_marks.insert(pair<int,string>(arr10[i].id(),arr10[i].mark()));
                        }
                    }
                    save_stdclass(Student_class,f);
                    save_stdname(Student_namee,f);
                    save_stdmark(Student_marks,f);
                    Student_class.clear();
                    Student_namee.clear();
                    Student_marks.clear();
                }

            }
            if(c==3) return 0;
            }
        }
    }
    if(type==3){
        cout<<"Enter your name:  "<<endl;
        cin>>name2;
        arr10=load_stdmark(n);
        arr12=load_stdname(n);
        arr9=load_stdclas(n);
        for(int i=0;i<n;i++){
            if(name2==arr12[i].name()){
                kay++;
            }
        }
        if(kay==0) cout<<"Student not found"<<endl;
        if(kay==1){
            for(int i=0;i<n;i++){
                if(name2==arr12[i].name()){
                    cout<<arr12[i].name()<<"   "<<arr10[i].mark()<<endl;
                    break;
                }
            }
        }
        if(kay>1){
            cout<<"Enter your class:   ";
            cin>>clss;
            for(int i=0;i<n;i++){
                if(name2==arr12[i].name()&&clss==arr9[i].clas()){
                    cout<<arr12[i].name()<<"   "<<arr10[i].mark()<<endl;
                }
            }
        }
    }

    return 0;
    }

