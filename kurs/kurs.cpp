#include <string.h>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <string>
#include "iostream"
#include <type_traits>
#include <typeinfo>
#include <cstring>
#ifndef _MSC_VER
#include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "Source.cpp"

#define string List<char>

using namespace std;

char PATH[105] = "C:/Users/Aprelixon/Desktop/Университет/Курсовая работа/Bazadannih.bin";

/*
class Subject {
public:
char SubjectName[100];
int Mark;
};

class Session {
public:
int Semester;
Subject Subjects[10];
int SubjectsCount;
};


class Student {
public:
Session session[9];
Subject Success;
char Name[100];
char Surname[100];
char FathersName[100];
int sessioncount;
char Date[100];
int JoinYear;
char Fuckultet[100];
char Kafedra[100];
char Group[100];
char ID[100];
char Sex[100];
};

*/
/*
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
*/
/*
vector<Student> ReadData() {
ifstream file("D:/Программы/Visual Studio/Мои проекты/!Курсовая Работа ЯП/Данные ТЕСТ КУРСАЧ/данныеТЕСТ.bin", ios::binary);
vector<Student> students;
Student student;
for (int i = 0;
file.read((char*)&student, sizeof(student)); i++) {
students.push_back(student);
}
file.close();
return students;
}
*/


template <typename K>
K GetValue(K& value) {
    while (!(cin >> value) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введено не числовое значение!\n";
    }
    return value;
}

void GetValue(char value[], bool afterInt) {
    char inputValue[100];
    if (afterInt) {
        getchar();
    }

    while (!gets_s(inputValue, 100)) {
        cout << "Неверное строковое значение\n";
    }
    strcpy_s(value, 100, inputValue);
}

bool DateCheck(int choice, int value) {
    switch (choice) {
        case 1:
            if ((value > 31) || (value < 1)) {
                return false;
            }
            else {
                return value;
            }
        case 2:
            if ((value > 12) || (value < 1)) {
                return false;
            }
            else {
                return value;
            }
        case 3:
            if ((value > 2005) || (value < 1933)) {
                return false;
            }
            else {
                return value;
            }
    }
}
/*
int DataChecker(int a, int value) {
b3: GetValue(value);
if (DateCheck(a, value) == false) {
cout « "Значение больше или меньше, чем это возможно!\n";
goto b3;
}
return value;
}
*/

bool correctName(char value[]) {
    string badChars = "0123456789,./|№;:?!@#$%^&*()_+==*-<>'~{}[]";
    for (int i = 0; i < strlen(value); i++) {
        if (badChars.contains(value[i])) return false;
    }
}

List <Student> ReadData() {
    ifstream file(PATH, ios::binary);
    Student student;

    List<Student> students;

    for (int i = 0; file.read((char*)&student, sizeof(student)); i++) {
        students.add(student);
    }
    file.close();
    return students;
}

void Delete() {
    const char* filename = PATH;
    remove(filename);
    system("cls");
    cout << "Все студенты успешно удалены!\n";
}



void PrintDate(unsigned short day, unsigned short month, unsigned short year) {
    if (day < 10) {
        cout << "0" << day;
    }
    else {
        cout << day;
    }
    cout << ".";
    if (month < 10) {
        cout << "0" << month;
    }
    else {
        cout << month;
    }
    cout << ".";
    cout << year;
}

void DrawLine(int value) {
    for (int i = 0; i < value; i++) {
        cout << "-";
    }
    cout << endl;
}

void AddStudent(List<Student> students) {
    ofstream Bazadannih(PATH, ios::binary | ios::app);
    for (auto& student : students) {
        Bazadannih.write((char*)&student, sizeof(student));
    }
    Bazadannih.close();
}
void DeleteOne(int id) {
    List<Student> students = ReadData();
    students.remove(id);
    remove(PATH);
    AddStudent(students);
}

void FileChanges(List<Student> students) {
    remove(PATH);
    AddStudent(students);
}

void EnterSt() {
    Student student = {};

    cout << "Введите имя:\n";
    a1: cin >> student.Name;
    if (correctName(student.Name) == false) {
        cout << "В имени могут быть только буквы!\n";
        goto a1;
    };
    cout << "Введите фамилию:\n";
    a2: cin >> student.Surname;
    if (correctName(student.Surname) == false) {
        cout << "В фамилии могут быть только буквы!\n";
        goto a2;
    };
    cout << "Введите отчество:\n";
    a3: cin >> student.FathersName;
    if (correctName(student.FathersName) == false) {
        cout << "В отчестве могут быть только буквы!\n";
        goto a3;
    };
    cout << "Введите дату рождения:\n";
    cout << "Введите день » ";
    b1: GetValue(student.date.day);
    if (DateCheck(1, student.date.day) == false) {
        cout << "Значение больше или меньше, чем это возможно!\n";
        goto b1;
    }
    cout << "Введите месяц » ";
    b2: GetValue(student.date.month);
    if (DateCheck(2, student.date.month) == false) {
        cout << "Значение больше или меньше, чем это возможно!\n";
        goto b2;
    }
    cout << "Введите год » ";
    b3: GetValue(student.date.year);
    if (DateCheck(3, student.date.year) == false) {
        cout << "Значение больше или меньше, чем это возможно!\n";
        goto b3;
    }
    cout << "Введите год поступления:\n";
    GetValue(student.JoinYear);
    cout << "Введите факультет:\n";
    getchar();
    gets_s(student.Fuckultet);
    cout << "Введите кафедру:\n";
    getchar();
    gets_s(student.Kafedra);
    cout << "Введите группу:\n";
    getchar();
    gets_s(student.Group);
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
            gets_s(student.session[i].Subjects[j].SubjectName);
            cout << "Введите оценку за " << j + 1 << "-й предмет в " << i + 1 << "-й сессии\n";
            cin >> student.session[i].Subjects[j].Mark;
        }
    }
    ofstream Bazadannih(PATH, ios::binary | ios::app);
    Bazadannih.write((char*)&student, sizeof(student));
    Bazadannih.close();
    system("cls");
    cout << "Студент успешно добавлен!\n";
}

void SessionChanges(int a, int k) {
    int sessionnum;
    int sessionparam;
    int subjcount;
    int subjnum;
    int subjparam;
    List<Student> students = ReadData();
    subjcount = students[k - 1].session[a - 1].SubjectsCount++;


}


/*
void StudWrite() {
List<Student> students = ReadData();
Student student = {};
if (!students.size()) {
system("cls");
cout « "Студентов в базе данных нет!\n";
}
else {
system("cls");
for (int i = 0; i < students.size(); i++)
{
DrawLine(65);
cout « i + 1 « " Студент" « endl;
cout « "ФИО: " « students[i].Surname « " " « students[i].Name « " " « students[i].FathersName « endl;
cout « "Пол: " « students[i].Sex « " | ";
//cout « "Дата рождения: " « students[i].Date « endl;
cout « "Год поступления: " « students[i].JoinYear « " | ";
cout « "Номер зачётной книжки: " « students[i].ID « endl;
cout « "Факультет: " « students[i].Fuckultet « " | ";
cout « "Кафедра: " « students[i].Kafedra « endl;
cout « "Группа: " « students[i].Group « endl;
for (int j = 0; j < students[i].sessioncount; j++) {
students[i].session[j].Semester = j + 1;
cout « " " « students[i].session[j].Semester « " Семестр:" « endl;
for (int k = 0; k < students[i].session[j].SubjectsCount; k++) {
cout « " " « students[i].session[j].Subjects[k].SubjectName « ": " «
students[i].session[j].Subjects[k].Mark « endl;
}
}
}
}
}
*/
void StudWrite(int choice) {
    List<Student> students = ReadData();
    Student student = {};
    if (!students.size()) {
        system("cls");
        cout << "Студентов в базе данных нет!\n";
    }
    else {
        system("cls");
        DrawLine(65);
        cout << choice << " Студент" << endl;
        cout << "ФИО: " << students[choice - 1].Surname << " " << students[choice - 1].Name << " " << students[choice - 1].FathersName << endl;
        cout << "Пол: " << students[choice - 1].Sex << " | ";
        cout << "Дата рождения: ";
        PrintDate(students[choice - 1].date.day, students[choice - 1].date.month, students[choice - 1].date.year);
        cout << endl;
        cout << "Год поступления: " << students[choice - 1].JoinYear << " | ";
        cout << "Номер зачётной книжки: " << students[choice - 1].ID << endl;
        cout << "Факультет: " << students[choice - 1].Fuckultet << " | ";
        cout << "Кафедра: " << students[choice - 1].Kafedra << endl;
        cout << "Группа: " << students[choice - 1].Group << endl;
        for (int j = 0; j < students[choice - 1].sessioncount; j++) {
            students[choice - 1].session[j].Semester = j + 1;
            cout << " " << students[choice - 1].session[j].Semester << " Семестр:" << endl;
            for (int k = 0; k < students[choice - 1].session[j].SubjectsCount; k++) {
                cout << " " << students[choice - 1].session[j].Subjects[k].SubjectName << ": " << students[choice - 1].session[j].Subjects[k].Mark << endl;
            }
        }
    }
}

void EditStudent(int k) {
    int p, a;
    int sessionnum;
    int sessionparam;
    int subjcount;
    int subjnum;
    int subjparam;
    int izmen;
    List<Student> students = ReadData();
    if (!students.size()) {
        system("cls");
        cout << "Студентов в базе данных нет!\n";
    }
    else {
        system("cls");
        StudWrite(k);
        cout << "Введите номер параметра, который необходимо изменить:\n";
        cout << "1. Имя\n2. Фамилия\n3. Отчество\n4. Дата рождения\n5. Год поступления\n6. Факультет\n7. Кафедра\n8. Группа\n9. Студенческий билет\n10. Пол\n11. Изменить данные о сессии\n12. Добавить предмет к сессии\n";
        cin >> p;

        switch (p) {
            case 1:
                cout << "Введите новое имя студента:\n";
                cin >> students[k - 1].Name;
                break;
            case 2:
                cout << "Введите новую фамилию студента:\n";
                cin >> students[k - 1].Surname;
                break;
            case 3:
                cout << "Введите новое отчество студента:\n";
                cin >> students[k - 1].FathersName;
                break;
            case 4:
                cout << "Введите новую дату рождения студента:\n";
                cout << "Введите день » ";
            b1: GetValue(students[k - 1].date.day);
                if (DateCheck(1, students[k - 1].date.day) == false) {
                    cout << "Значение больше или меньше, чем это возможно!\n";
                    goto b1;
                }
                cout << "Введите месяц » ";
            b2: GetValue(students[k - 1].date.month);
                if (DateCheck(2, students[k - 1].date.month) == false) {
                    cout << "Значение больше или меньше, чем это возможно!\n";
                    goto b2;
                }
                cout << "Введите год » ";
            b3: GetValue(students[k - 1].date.year);
                if (DateCheck(3, students[k - 1].date.year) == false) {
                    cout << "Значение больше или меньше, чем это возможно!\n";
                    goto b3;
                }
                break;
            case 5:
                cout << "Введите новую год поступления студента:\n";
                cin >> students[k - 1].JoinYear;
                break;
            case 6:
                cout << "Введите новый факультет студента:\n";
                getchar();
                gets_s(students[k - 1].Fuckultet);
                break;
            case 7:
                cout << "Введите новую кафедру студента:\n";
                getchar();
                gets_s(students[k - 1].Kafedra);
                break;
            case 8:
                cout << "Введите новую группу студента:\n";
                getchar();
                gets_s(students[k - 1].Group);
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
                cout << "Введите номер сессии:\n";
                cin >> sessionnum;
                cout << "Введите номер предмета:\n";
                cin >> izmen;
                cout << "Введите новое название предмета студента:\n";
                cin >> students[k - 1].session[sessionnum - 1].Subjects[izmen - 1].SubjectName;
                cout << "Введите новую оценку по предмету студента:\n";
                cin >> students[k - 1].session[sessionnum - 1].Subjects[izmen - 1].Mark;
                break;
            case 12:
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
        system("cls");
        cout << "Изменения успешно внесены!\n";
        FileChanges(students);
    }
}


void StudWriteTable() {
    List<Student> students = ReadData();
    Student student = {};
    int a;
    int b;
    int count = 0;
    if (!students.size()) {
        system("cls");
        cout << "Студентов в базе данных нет!\n";
    }
    else {
        system("cls");
        cout << "Введите '1', чтобы узнать подробную информацию о студенте.\n";
        cout << "Введите '2', чтобы редактировать данные о студенте.\n";
        cout << "Введите '3', чтобы удалить данные о студенте.\n";
        cout << "Введите любое числовое значение, чтобы вернуться в главное меню.\n";
        DrawLine(75);
        cout << "|n/n|" << setw(26) << "ФИО Студента" << setw(44) << "|Дата рождения|Номер зачётки|" << endl;
        DrawLine(75);
        for (int i = 0; i < students.size(); i++) {
            cout << "|" << setw(2) << i + 1 << " |" << students[i].Surname << " " << students[i].Name << " " << students[i].FathersName << setw(40 - strlen(students[i].Surname) - strlen(students[i].Name) - strlen(students[i].FathersName)) << "|";
            PrintDate(students[i].date.day, students[i].date.month, students[i].date.year);
            cout << setw(4) << "|" << students[i].ID << setw(14 - strlen(students[i].ID)) << "|" << endl;
            DrawLine(75);
        }
        cout << "» ";
        GetValue(b);
        switch (b) {
            case 1:
                students = ReadData();
                count = students.size();
                cout << "Введите порядковый номер студента, чтобы узнать подробную информацию.\n";
                cout << "» ";
            x1: cin >> a;
                if (a > count || a < 0) {
                    cout << "Студента с таким порядковым номером нет в базе!\n";
                    goto x1;
                }
                else {
                    StudWrite(a);
                }
                break;
            case 2:
                students = ReadData();
                count = students.size();
                cout << "Введите порядковый номер студента, данные о котором необходимо изменить.\n";
                cout << "» ";
            x2: cin >> a;
                if (a > count || a < 0) {
                    cout << "Студента с таким порядковым номером нет в базе!\n";
                    goto x2;
                }
                else {
                    EditStudent(a);
                }
                break;
            case 3:
                students = ReadData();
                count = students.size();
                cout << "Введите порядковый номер студента, данные о котором необходимо удалить\n";
                cout << "» ";
            x3: cin >> a;
                if (a > count || a < 0) {
                    cout << "Студента с таким порядковым номером нет в базе!\n";
                    goto x3;
                }
                else {
                    DeleteOne(a - 1);
                    system("cls");
                    cout << "Студент успешно удалён!\n";
                }
                break;
            default:
                system("cls");
        }
    }
}

/*
int Search(char StudakNum[]) {
List<Student> students = ReadData();
for (int i = 0; i < students.size(); i++) {
if (!strcmp(StudakNum, students[i].ID)) {
return i + 1;
}
}
return 0;
}
*/


int InMain() {
    while (true) {
        int a;
        DrawLine(65);
        cout << "|Выберите действие (Необходимо ввести порядковый номер действия)|\n";
        DrawLine(65);
        cout << "1. Добавить студента\n";
        cout << "2. Удаление всех студентов\n";
        cout << "3. Вывод всех студентов\n";
        cout << "» ";
        GetValue(a);
        switch (a) {
            case 1:
                system("cls");
                EnterSt();
                break;
            case 2:
                Delete();
                break;
            case 3:
                StudWriteTable();
                break;
            case 0:
                return 0;
            default:
                system("cls");
                cout << "Такого пункта в меню нет!\n";
        }
        /*
        if (a == 4) {
        char StudakNum[100];
        cout « "Введите искомый номер студенческого билета:\n" « endl;
        cin » StudakNum;
        // cout « "Данный номер студенческого билета принадлежит студенту номер: " « Search(StudakNum) « endl « endl;
        }
        */
    }
}

void
Lang() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

int main()
{
    Lang();
    InMain();

}
