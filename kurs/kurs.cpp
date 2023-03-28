#include <string.h>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

struct Initials {
    char Name[100];
    char Surname[100];
    char FathersName[100];
};

struct Subject {
    char SubjectName[100];
    int Mark;
};

struct Session {
    int Semester;
    Subject Subjects[10];
    int SubjectsCount;
};

struct Student {
    Session session[9];
    Initials Name;
    char Date[100];
    int JoinYear;
    char Fuckultet[100];
    char Kafedra[100];
    char Group[100];
    char ID[100];
    char Sex[100];
    Subject Success;
};

vector<Student> ReadData() {
    ifstream niggamoment("C:/nigga/Baza.bin", ios::binary);
    vector<Student> students;
    Student student;
    for (int i = 0;
        niggamoment.read((char*)&student, sizeof(student)); i++) {
        students.push_back(student);
    }
    niggamoment.close();
    return students;
}

void AddStudent(vector <Student> students) {
    ofstream Bazadannih("C:/nigga/Baza.bin", ios::binary | ios::app);
    for (auto& student : students) {
        Bazadannih.write((char*)&student, sizeof(student));
    }
    Bazadannih.close();
}

void EnterSt() {
    Student student;
    cout << "Введите имя:\n";
    cin >> student.Name.Name;
    cout << "Введите фамилию:\n";
    cin >> student.Name.Surname;
    cout << "Введите отчество:\n";
    cin >> student.Name.FathersName;
    cout << "Введите дату рождения (через точки):\n";
    cin >> student.Date;
    cout << "Введите год поступления:\n";
    cin >> student.JoinYear;
    cout << "Введите факультет:\n";
    getchar();
    gets_s(student.Fuckultet);
    cout << "Введите кафедру:\n";
    gets_s(student.Kafedra);
    cout << "Введите группу:\n";
    cin >> student.Group;
    cout << "Введите студенческий билет:\n";
    cin >> student.ID;
    cout << "Введите пол:\n";
    cin >> student.Sex;
    cout << "Введите название предмета:\n";
    getchar();
    gets_s(student.Success.SubjectName);
    cout << "Введите оценку по предмету:\n";
    cin >> student.Success.Mark;
    ofstream Bazadannih("C:/nigga/Baza.bin", ios::binary | ios::app);
    Bazadannih.write((char*)&student, sizeof(student));
    Bazadannih.close();
}

void niggavivod() {
    vector <Student> students = ReadData();
    for (int i = 0; i < students.size(); i++)
    {
        cout << "Студент номер: "<< i + 1 << endl << "Фамилия: " << students[i].Name.Surname << endl << "Имя: " << students[i].Name.Name << endl << "Отчество: " << students[i].Name.FathersName << endl << "Дата рождения: " << students[i].Date/*.Day << " " << students[i].Date.Month << " " << students[i].Date.Year*/ << endl << "Дата поступления: " << students[i].JoinYear << endl << "Факультет: " << students[i].Fuckultet << endl << "Кафедра: " << students[i].Kafedra << endl << "Группа: " << students[i].Group << endl << "Студенческий билет: " << students[i].ID << endl << "Пол: " << students[i].Sex << endl << "Предмет: " << students[i].Success.SubjectName << endl << "Оценка по предмету выше: " << students[i].Success.Mark << endl << endl;
    }
}

int Search(char StudakNum[]) {
    vector <Student> students = ReadData();
    for (int i = 0; i < students.size(); i++) {
        if (!strcmp(StudakNum, students[i].ID)) {
            return i+1;
        }
    }
    return 0;
}

void Lang() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

void Delete() {
    string filename = "C:/nigga/Baza.bin";
    remove(filename.c_str());
}

void InMain() {
    while (true) {
        int a;
        cout << "1-> Добавить студента\n";
        cout << "2-> Вывод всех студентов\n";
        cout << "3-> Удаление всех студентов\n";
        cout << "4-> Поиск студента по студенческому билету\n";
        cin >> a;
        if (a == 1) {
            EnterSt();
        }
        if (a == 2) {
            niggavivod();
        }
        if (a == 3) {
            Delete();
        }
        if (a == 4) {
            char StudakNum[100];
            cout << "Введите искомый номер студенческого билета:\n";
            cin >> StudakNum;
            cout << "Данный номер студенческого билета принадлежит студенту номер: " << Search(StudakNum) << endl;
        }
        if (a != 1 || 2 || 3 || 4) {
            InMain();
        }
    }
}

int main()
{
    Lang();
    InMain();
}

