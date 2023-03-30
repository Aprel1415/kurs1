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
    cout << "Введите количество сессий:\n";
    cin >> student.session->Semester;
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
        cout << "Студент номер: " << i + 1 << endl << "Фамилия: " << students[i].Name.Surname << endl << "Имя: " << students[i].Name.Name << endl << "Отчество: " << students[i].Name.FathersName << endl << "Дата рождения: " << students[i].Date << endl << "Дата поступления: " << students[i].JoinYear << endl << "Факультет: " << students[i].Fuckultet << endl << "Кафедра: " << students[i].Kafedra << endl << "Группа: " << students[i].Group << endl << "Студенческий билет: " << students[i].ID << endl << "Пол: " << students[i].Sex << endl << "Количество сессий:" << students[i].session->Semester << endl << "Предмет: " << students[i].Success.SubjectName << endl << "Оценка по предмету выше: " << students[i].Success.Mark << endl << endl;
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
        cout << "2-> Вывод всех студентов\n";
        cout << "3-> Удаление всех студентов\n";
        cout << "4-> Поиск студента по студенческому билету\n";
        cout << "5-> Редакция студентов\n";
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
            cout << "Введите искомый номер студенческого билета:\n" << endl;
            cin >> StudakNum;
            cout << "Данный номер студенческого билета принадлежит студенту номер: " << Search(StudakNum) << endl << endl;
        }
        if (a == 5) {
            EditStudent();
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
    //Фигня какая то с добавлением предметов и оценок по ним, а также какая то суета с семестрами.
}

