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
    int sessioncount;
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

void FileChanges(vector <Student> students) {
    remove("C:/nigga/Baza.bin");
    AddStudent(students);
}

void EditStudent() {
    int p,k;
    int sessionnum;
    int sessionparam;
    int subjcount;
    int subjnum;
    int subjparam;
    vector <Student> students = ReadData();
    for (int i = 0; i < students.size(); i++) {
        cout << i + 1 << ") " << students[i].ID << endl;
    }
    cout << "Введите номер студента для редактирования:\n";
    cin >> k;
    cout << "1-> Имя\n2-> Фамилия\n3-> Отчество\n4-> Дата рождения\n5-> Год поступления\n6-> Факультет\n7-> Кафедра\n8-> Группа\n9-> Студенческий билет\n10-> Пол\n11-> Название предмета\n12-> Оценка по предмету\n13-> Добавить предмет\n";
    cout << "Введите номер параметра:\n";
    cin >> p;
    switch (p) {
    case 1:
        cout << "Введите новое имя студента:\n";
        cin >> students[k - 1].Name.Name;
        break;
    case 2:
        cout << "Введите новую фамилию студента:\n";
        cin >> students[k - 1].Name.Surname;
        break;
    case 3:
        cout << "Введите новое отчество студента:\n";
        cin >> students[k - 1].Name.FathersName;
        break;
    case 4:
        cout << "Введите новую дату рождения студента:\n";
        cin >> students[k - 1].Date;
        break;
    case 5:
        cout << "Введите новую год поступления студента:\n";
        cin >> students[k - 1].JoinYear;
        break;
    case 6:
        cout << "Введите новый факультет студента:\n";
        cin >> students[k - 1].Fuckultet;
        break;
    case 7:
        cout << "Введите новую кафедру студента:\n";
        cin >> students[k - 1].Kafedra;
        break;
    case 8:
        cout << "Введите новую группу студента:\n";
        cin >> students[k - 1].Group;
        break;
    case 9:
        cout << "Введите новый студенческий билет студента:\n";
        cin >> students[k - 1].ID;
        break;
    case 10:
        cout << "Введите новый пол студента:\n";
        cin >> students[k - 1].Sex;
        break;
    case 11:
        cout << "Введите новое название предмета студента:\n";
        cin >> students[k - 1].Success.SubjectName;
        break;
    case 12:
        cout << "Введите новую оценку по предмету студента:\n";
        cin >> students[k - 1].Success.Mark;
        break;
    case 13:
        cout << "Введите номер сессии:\n";
        cin >> sessionnum;
        subjcount = students[k - 1].session[sessionnum - 1].SubjectsCount++;
        sessionparam = 1;
        switch (sessionparam) {
        case 1:
            cout << "Введите название предмета:\n";
            cin >> students[k - 1].session[sessionnum - 1].Subjects[subjcount].SubjectName;
            cout << "Введите оценку за предмет:\n";
            cin >> students[k - 1].session[sessionnum - 1].Subjects[subjcount].Mark;
            break;
        }
    }
    FileChanges(students);
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
    cout << "Введите количество сданных сессий (максимум 9):\n";
    cin >> student.sessioncount;
    for (int i = 0; i < student.sessioncount; i++) {
        student.session[i].Semester = i + 1;
        cout << "Введите количество предметов в " << i + 1 << "-й сессии (Максимум 10)\n";
        cin >> student.session[i].SubjectsCount;
        for (int j = 0; j < student.session[i].SubjectsCount; j++) {
            cout << "Введите название " << j + 1 << "-го предмета в " << i + 1 << "-й сессии\n";
            getchar();
            gets_s (student.session[i].Subjects[j].SubjectName);
            cout << "Введите оценку за " << j + 1 << "-й предмет в " << i + 1 << "-й сессии\n";
            cin >> student.session[i].Subjects[j].Mark;
        }
    }
    ofstream Bazadannih("C:/nigga/Baza.bin", ios::binary | ios::app);
    Bazadannih.write((char*)&student, sizeof(student));
    Bazadannih.close();
}

void niggavivod() {
    vector <Student> students = ReadData();
    Student student;
    for (int i = 0; i < students.size(); i++)
        //фор для вывода сессий
    {
        cout << "Студент номер: " << i + 1 << endl;
        cout << "Фамилия: " << students[i].Name.Surname << endl;
        cout << "Имя: " << students[i].Name.Name << endl;
        cout << "Отчество: " << students[i].Name.FathersName << endl;
        cout << "Дата рождения: " << students[i].Date << endl;
        cout << "Дата поступления: " << students[i].JoinYear << endl;
        cout << "Факультет: " << students[i].Fuckultet << endl;
        cout << "Кафедра: " << students[i].Kafedra << endl;
        cout << "Группа: " << students[i].Group << endl;
        cout << "Студенческий билет: " << students[i].ID << endl;
        cout << "Пол: " << students[i].Sex << endl;
        for (int j = 0; j < students[i].sessioncount; j++) {
            students[i].session[j].Semester = j + 1;
            cout << "Номер сессии: " << students[i].session[j].Semester << endl;
            for (int k = 0; k < students[i].session[j].SubjectsCount; k++) {
                cout << "Название предмета в этой сессии: " << students[i].session[j].Subjects[k].SubjectName << endl;
                cout << "Оценка по этому предмету: " << students[i].session[j].Subjects[k].Mark << endl;
            }
        }
    }
}

int Search(char StudakNum[]) {
    vector <Student> students = ReadData();
    for (int i = 0; i < students.size(); i++) {
        if (!strcmp(StudakNum, students[i].ID)) {
            return i + 1;
        }
    }
    return 0;
}

void Delete() {
    string filename = "C:/nigga/Baza.bin";
    remove(filename.c_str());
}

void InMain() {
    while (true) {
        int a;
        cout << "1-> Добавить студента\n";
        cout << "2-> Редакция студентов\n";
        cout << "3-> Удаление всех студентов\n";
        cout << "4-> Поиск студента по студенческому билету\n";
        cout << "5-> Вывод всех студентов\n";
        cin >> a;
        if (a == 1) {
            EnterSt();
        }
        if (a == 2) {
            EditStudent(); niggavivod();
        }
        if (a == 3) {
            Delete();
        }
        if (a == 4) {
            char StudakNum[100];
            cout << "Введите искомый номер студенческого билета:\n" << endl;
            cin >> StudakNum;
            cout << "Данный номер студенческого билета принадлежит студенту номер: " << Search(StudakNum) << endl << endl;
        }
        if (a == 5) {
            niggavivod(); 
        }
    }
}

void Lang() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

int main()
{
    Lang();
    InMain();
}

