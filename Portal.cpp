#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
void menu(); 
class Student
{
    char suserName[20];
    char spassword[20];
    char section[10];
    int id, n;

  public:
    Student() {}
    static int Studentcount; 
    void FromFile();
    void getFile();
    void updateData(long int idd);
    void deleteSectionassignment(char *k);
    void StudentData();
    char *getName();
    char *getSPassword();
    char *sec();
    int getIdOfStudent();
    void display();
    void storeDataInFile();
};
void Student::storeDataInFile()
{
    Student a;
    a.StudentData();
    ofstream fout;
    fout.open("studentData.bin", ios::app | ios::binary);
    fout.write((char *)&a, sizeof(class Student));
    fout.close();
}
void Student::getFile()
{
    Student a;
    ifstream fin;
    fin.open("studentData.bin", ios::in | ios::binary);
    fin.read((char *)&a, sizeof(class Student));
    while (!fin.eof())
    {
        a.display();
        fin.read((char *)&a, sizeof(class Student));
    }
    fin.close();
}
inline void Student::display() 
{
    cout << suserName << " " << section << " " << id << endl;
}

void Student::StudentData()
{
    Student s3;
    cout << "USERNAME OF STUDENT : " << endl;
    cin.getline(suserName, 19);
    cin.ignore();
    cout << "DESIRED PASSWORD : " << endl;
    cin.getline(spassword, 19);
    cin.ignore();
    cout << "SECTION : " << endl;
    cin.getline(section, 10);
    cin.ignore();
    cout << "STUDENT ID : " << endl;
    cin >> id;
    cin.ignore(1);
    s3.Studentcount = s3.Studentcount + 1;
}

inline char *Student::getSPassword() 
{
    return spassword;
}

inline char *Student::getName() 
{
    return suserName;
}

inline int Student::getIdOfStudent() 
{
    return id;
}

class Lecturer
{
    char password[20];
    char userName[20];
    int lecturerId;

  public:
    
    static int LecturerCount; 
    Lecturer() {}
    void getData();
    char *getPassword();
    char *getUserName();
    void display();
    void storeDataInFile();
    void getDataFromFile();
    void FromFile();
};
class AssignmentForAll
{
    char section[10];
    char assignmentforall[200];

  public:
    void getDataForAssignForAll();
    char *getSec();
    void display();
    void storeDataInFile();
    void searchDataInFile(char *s);
    int getDataFromFile();
};
void AssignmentForAll::searchDataInFile(char *s)
{
    AssignmentForAll a;
    ifstream fin;
    fin.open("AssignmentForAll.bin", ios::in | ios::binary);
    fin.read((char *)&a, sizeof(class AssignmentForAll));

    while (!fin.eof())
    {
        if (!strcasecmp(a.section, s))
        {
            a.display();
        }
        fin.read((char *)&a, sizeof(class AssignmentForAll));
    }
    fin.close();
}
inline void AssignmentForAll::display() 
{
    cout << section << endl;
    cout << assignmentforall << endl;
};
char *AssignmentForAll::getSec() { return section; }
void AssignmentForAll::getDataForAssignForAll()
{
    cout << "SECTION ID/NAME : " << endl;
    cin.getline(section, 9);
    cin.ignore();
    cout << "ENTER ASSIGNMENT DETAILS (200 WORDS) : " << endl;
    cin.getline(assignmentforall, 199);
    cin.ignore();
}
void AssignmentForAll::storeDataInFile()
{
    AssignmentForAll obj;
    obj.getDataForAssignForAll();
    ofstream fout;
    fout.open("AssignmentForAll.bin", ios::app | ios::binary);
    fout.write((char *)&obj, sizeof(class AssignmentForAll));
    fout.close();
}
int AssignmentForAll::getDataFromFile()
{
    AssignmentForAll a;
    ifstream fin;
    fin.open("AssingnmentForAll.bin", ios::in | ios::binary);
    if (!fin)
    {
        cerr << "FILE NOT CREATED" << endl;
        return -1;
    }
    fin.read((char *)&a, sizeof(class AssignmentForAll));
    while (!fin.eof())
    {
        a.display();
        fin.read((char *)&a, sizeof(class AssignmentForAll));
    }
    fin.close();
    return 1;
}

class AssignmentForOne
{
    int id;
    char assignment[200];

  public:
    int getId();
    void getData();
    void display();
    void storeDataInFile();
    void searchFromFile(int idd);
    int getDataFromFile();
    int iddd();
};
void AssignmentForOne::searchFromFile(int idd)
{
    AssignmentForOne a;
    ifstream fin;
    fin.open("assignmentforone.bin", ios::in | ios::binary);
    fin.read((char *)&a, sizeof(class AssignmentForOne));
    while (!fin.eof())
    {
        if (a.id == idd)
        {
            a.display();
        }
        fin.read((char *)&a, sizeof(class AssignmentForOne));
    }
}

inline int AssignmentForOne::getId() { return id; } 

void AssignmentForOne::getData()
{
    cout << "ENTER ASSIGNMENT DETAILS (200 WORDS) : " << endl;
    cin.getline(assignment, 199);
    cin.ignore();
    cout << "ENTER THE ID OF THE STUDENT TO ASSIGN TO : " << endl;
    cin >> id;
    cin.ignore();
}
inline void AssignmentForOne::display() 
{
    cout << assignment << id << endl;
}

void AssignmentForOne::storeDataInFile()
{
    ofstream fout;
    AssignmentForOne a;
    a.getData();
    fout.open("assignmentforone.bin", ios::app | ios::binary);
    fout.write((char *)&a, sizeof(class AssignmentForOne));
    fout.close();
}
int AssignmentForOne::getDataFromFile()
{
    AssignmentForOne a;
    ifstream fin;
    fin.open("assignmentforone.bin", ios::in | ios::binary);
    if (!fin)
    {
        cerr << "that file is not created" << endl;
        return -1;
    }
    fin.read((char *)&a, sizeof(class AssignmentForOne));
    while (!fin.eof())
    {
        a.display();
        fin.read((char *)&a, sizeof(class AssignmentForOne));
    }
    fin.close();
    return 1;
}

int Student::Studentcount = 0;

int AssignmentForOne::iddd()
{
    return id;
}
void DeleteDataForOne()
{
    ofstream file;
    file.open("assignmentforone.bin", ios::out | ios::binary | ios::trunc);
    file.close();
    cout << "FILE CONTENTS HAVE BEEN ERASED SUCCESSFULLY";
    exit(-1);
}
void DeleteDataForAll()
{
    ofstream file1;
    file1.open("AssignmentForAll.bin", ios::out | ios::binary | ios::trunc);
    file1.close();
    cout << "FILE CONTENTS HAVE BEEN ERASED SUCCESSFULLY";
    exit(-1);
}
char *Student::sec() { return section; }
void Student::FromFile()
{
    Student a;
    AssignmentForAll b;
    AssignmentForOne c;
    char ch;
    int i;
    char nameOfStudent[20];
    char passwordOfStudent[20];
    cout << "ENTER USERNAME : " << endl;
    cin.getline(nameOfStudent, 19);
    cin.ignore();
    ifstream fin;
    fin.open("studentData.bin", ios::in | ios::binary);
    fin.read((char *)&a, sizeof(class Student));
    while (!fin.eof())
    {
        if (!strcasecmp(a.suserName, nameOfStudent))
        {
            cout << "ENTER PASSWORD : " << endl;
            cin.getline(passwordOfStudent, 19);
            cin.ignore();
            if (!strcmp(a.spassword, passwordOfStudent))
            {
                cout << "WELCOME TO YOUR PORTAL !!!" << endl;
                cout << "------- -- ---- ------ ---" <<endl <<endl ;

                do
                {
                    cout << "1) CHECK FOR CLASS ASSIGNMENTS" << endl;
                    cout << "2) CHECK FOR INDIVIDUAL ASSIGNMENTS" << endl;
                    cin >> i;
                    cin.ignore();

                    switch (i)
                    {
                    case 1:
                        b.searchDataInFile(a.sec());
                        break;
                    case 2:
                        c.searchFromFile(a.id);
                        break;
                    default:
                        break;
                    }
                    cout << "DO YOU WANT TO CONTINUE ? " << endl
                         << "Y/N" << endl;
                    cin >> ch;
                    cin.ignore(2);
                } while (ch == 'y' || ch == 'Y');
            }
        }
        fin.read((char *)&a, sizeof(class Student));
    }
    if (ch == 'n' || ch == 'N')
    {
        cout << "LOGGED OUT" << endl;
        menu();
    }
    fin.close();
}

class RemoveTeacher
{
  public:
    void RemoveTeacher_()
    {
        ofstream file;
        file.open("LecturerData.bin", ios::out | ios::binary | ios::trunc);
        file.close();
        cout << "TEACHERS REMOVED SUCCESSFULLY";
        exit(-1);
    }
};
class Removestudent : public RemoveTeacher 
{
  public:
    void RemoveStudent()
    {
        ofstream file;
        file.open("studentData.bin", ios::out | ios::binary | ios::trunc);
        file.close();
        cout << endl
             << "STUDENTS REMOVED SUCCESSFULLY";
        exit(-1);
    }
};
class printdata 
{
    Student s;

  public:
    void print(int i)
    {
        cout << "total no.  is-";
        exit(-1);
    }
};

int Lecturer::LecturerCount = 0;
void Student::deleteSectionassignment(char *k)
{
    AssignmentForAll a;
    fstream file;
    file.open("AssignmentForAll.bin", ios::in | ios::out | ios::ate | ios::binary);
    file.seekg(0);
    file.read((char *)&a, sizeof(class AssignmentForAll));
    while (!file.eof())
    {
        if (k == a.getSec())
        {
            file.seekp(file.tellp() - sizeof(class AssignmentForAll));
            cin.ignore();
            a.getDataForAssignForAll();
            file.write((char *)&a, sizeof(class AssignmentForAll));
            file.close();
            cout << "ASSIGNMENT SUCCESSFULLY UPDATED" << endl;
        }
        file.read((char *)&a, sizeof(class AssignmentForAll));
    }
}
void Student::updateData(long int idd)
{
    AssignmentForOne a;
    fstream file;
    file.open("assignmentforone.bin", ios::in | ios::out | ios::ate | ios::binary);
    file.seekg(0);
    file.read((char *)&a, sizeof(class AssignmentForOne));
    while (!file.eof())
    {
        if (idd == a.iddd())
        {
            file.seekp(file.tellp() - sizeof(class AssignmentForOne));
            cin.ignore();
            a.getData();
            file.write((char *)&a, sizeof(class AssignmentForOne));
            file.close();
            cout << "ASSIGNMENT SUCCESSFULLY UPDATED" << endl;
        }
        file.read((char *)&a, sizeof(class AssignmentForOne));
    }
}
void Decide(int i)
{
    printdata p1; 
    AssignmentForAll a1;
    AssignmentForOne a2;
    Student s1;
    Lecturer L1;
    if (i == 13)
    {
        p1.print(s1.Studentcount);
    }
    else if (i == 14)
    {
        p1.print(L1.LecturerCount);
    }
}
int GetIdStudent()
{
    int m;
    cout << "ENTER THE STUDENT ID TO UPDATE : " << endl;
    cin >> m;
    return m;
}
void Lecturer::FromFile()
{
    Lecturer c;
    Student s;
    AssignmentForAll a;
    AssignmentForOne b;

    char currPass[20];
    char currUsername[20];
    char ch;
    cout << "ENTER USERNAME : " << endl;
    cin.getline(currUsername, 20);
    cin.ignore();
    int swi;

    ifstream fin;
    fin.open("LecturerData.bin", ios::in | ios::binary);
    fin.read((char *)&c, sizeof(class Lecturer));

    while (!fin.eof())
    {

        if (!strcasecmp(c.userName, currUsername))
        {
            cout << "ENTER PASSWORD" << endl;
            cin.getline(currPass, 20);
            cin.ignore();

            if (!strcmp(c.password, currPass))
            {
                cout << "LOGIN SUCCESSFUL !!!" << endl;
                cout << endl;

                do
                {
                    cout << "1) ASSIGN WORK FOR WHOLE CLASS" << endl;
                    cout << "2) ASSIGN WORK FOR SINGLE STUDENT" << endl;
                    cout << "3) DELETE ALL THE INDIVIDUAL ASSIGNMENTS" << endl;
                    cout << "4) DELETE ALL THE CLASSWISE ASSIGNMENTS" << endl;
                    cout << "5) DELETE SAVED STUDENT FROM THE SYSTEM" << endl;
                    cout << "6) DELETE SAVED TEACHER FROM SYSTEM" << endl;

                    cout << "7) UPDATE THE INDIVIDUAL ASSIGNMENT" << endl;
                    cout << "8) UPDATE CLASSWISE ASSIGNMENT" << endl;
                    cout << "9) EXIT" << endl << endl;
                    cout << "ENTER YOUR CHOICE : " << endl;
                    cin >> swi;
                    cin.ignore();
                    switch (swi)
                    {
                    case 1:

                        a.storeDataInFile();
                        break;
                    case 2:
                        b.storeDataInFile();
                        break;
                    case 3:
                        DeleteDataForOne();
                        break;
                    case 4:
                        DeleteDataForAll();
                        break;
                    case 5:
                        Removestudent r;
                        r.RemoveStudent();
                        break;
                    case 6:
                        r.RemoveTeacher_();
                    case 8:
                        s.deleteSectionassignment(a.getSec());
                        break;
                    case 9:
                        exit(-1);
                    case 7:
                        s.updateData(GetIdStudent());
                        break;
                    default:
                        break;
                    }
                    cout << "CONTINUE ? (Y/N)" << endl;
                    cin >> ch;
                    cin.ignore(2);
                } while (ch == 'Y' || ch == 'y');
            }
        }
        fin.read((char *)&c, sizeof(class Lecturer));
    }

    if (ch == 'n' || ch == 'N')
    {
        cout << "LOGGED OUT" << endl;
        menu();
    }
    fin.close();
}
inline void Lecturer::display() 
{
    cout << userName << " " << lecturerId << password << endl;
}
void Lecturer::getDataFromFile()
{
    Lecturer a;
    ifstream fin;
    fin.open("LecturerData.bin", ios::in | ios::binary);
    fin.read((char *)&a, sizeof(class Lecturer));
    while (!fin.eof())
    {
        a.display();
        fin.read((char *)&a, sizeof(class Lecturer));
    }
    fin.close();
}
void Lecturer::storeDataInFile()
{
    LecturerCount++;
    Lecturer a;
    a.getData();
    ofstream fout;
    fout.open("LecturerData.bin", ios::app | ios::binary);
    fout.write((char *)&a, sizeof(class Lecturer));
    fout.close();
}
inline char *Lecturer::getPassword() { return password; }
inline char *Lecturer::getUserName() { return userName; }
void Lecturer::getData()
{
    LecturerCount++;
    cout << "ENTER USERNAME : " << endl;
    cin.getline(userName, 19);
    cout << "ENTER PASSWORD : " << endl;
    cin.getline(password, 19);
    cout << "ENTER LECTURER ID : " << endl;
    cin >> lecturerId;
    cin.ignore();
}
void menu()
{
    Student s;
    Lecturer l;
    
    cout << "1) REGISTER NEW STUDENT" << endl;
    cout << "2) REGISTER NEW TEACHER" << endl;
    cout << "3) EXISTING STUDENT SIGN IN"<< endl;
    cout << "4) TEACHER SIGN IN"<< endl;
    cout << "5) EXIT"<< endl;
    int i;
    cin >> i;
    cin.ignore();
    switch (i)
    {
    case 1:
        s.storeDataInFile();
        break;
    case 2:
        l.storeDataInFile();
    case 3:
        s.FromFile();
        break;
    case 4:
        l.FromFile();
        break;
    case 5:
        exit(-1);
    default:
        break;
    }
}
int main()
{
    cout<<"/*---------------------------------------------------------------------*/"<<endl;
    cout<<"/*-=-=-=-=-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-=-=-=-=-*/"<<endl;
    cout<<"/*-=-=-=-x                                                     x-=-=-=-*/"<<endl;
    cout<<"/*-=-=-=-x                      EDUHUB                         x-=-=-=-*/"<<endl;
    cout<<"/*-=-=-=-x             C++ PACKAGE (2ND SEMESTER)              x-=-=-=-*/"<<endl;
    cout<<"/*-=-=-=-x                                                     x-=-=-=-*/"<<endl;
    cout<<"/*-=-=-=-x                                                     x-=-=-=-*/"<<endl;
    cout<<"/*-=-=-=-=-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-=-=-=-=-*/"<<endl;
    cout<<"/*---------------------------------------------------------------------*/"<<endl;
    cout<<"/*||                                                                 ||*/"<<endl;
    cout<<"/*||                                                                 ||*/"<<endl;
    cout<<"/*||                                                                 ||*/"<<endl;
    cout<<"/*||                            Nithish R                            ||*/"<<endl;
    cout<<"/*||                                                                 ||*/"<<endl;
    cout<<"/*||              Topic : STUDENT ASSIGNMENT PORTAL                  ||*/"<<endl;
    cout<<"/*||                                                                 ||*/"<<endl;
    cout<<"/*||                                                                 ||*/"<<endl;
    cout<<"/*---------------------------------------------------------------------*/"<<endl;
    menu();
    return 0;
}
