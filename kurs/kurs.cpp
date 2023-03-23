#include <string.h>
#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;



struct Initials {
    char Name[20];
    char Surname[20];
    char FathersName[20];
};

struct Date {
    unsigned short int Day;
    unsigned short int Month;
    unsigned short int Year;
};

struct Subject {
    char SubjectName[30];
    unsigned short int Mark;
};

struct Student {
    Initials Name;
    Date Date;
    unsigned short int JoinYear;
    char Fuck[10];
    char Kaf[10];
    char Group[15];
    char ID[15];
    bool Sex;
    Subject Success;
};



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Student student = { {"Апреликов", "Артемий", "Александрович"},{15,10,1222}, 2003, "ИКб", "афвы", "Baso-02-22", "239875b2", 1, {"matem", 4} };
    ofstream Bazadannih("C:/nigga/Baza.bin", ios::binary | ios::app);
    Bazadannih.write((char*)&student, sizeof (student));
    Student dva;
    ifstream niggamoment("C:/nigga/Baza.bin", ios::binary);
    niggamoment.read((char*)&dva, sizeof(dva));
    cout << dva.Name.Name << " " << dva.Name.FathersName;
    remove("C:/nigga/Baza.bin");
}
