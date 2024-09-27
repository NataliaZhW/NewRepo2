/*Курс
«Объектно-ориентированное
программирование на C++»
Встреча №4
Человек Квартира Дом
*/

#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

class Person
{
private:
    char* surname{ new char[50] };
    char* name{ new char[50] };
    char* name2{ new char[50] };
    char* mob_tel{ new char[50] };
    string other;
public:
    Person();
    Person(Person& person1);
    Person(const char* surname, const char* name, const char* name2, const char* mob_tel, const string other);
    ~Person();
    // Перегрузка оператора =
    void operator =(Person& person1) {
        //cout << "Перегрузка оператора = Person\n";
        strcpy_s(this->surname, strlen(person1.surname) + 1, person1.surname);
        strcpy_s(this->name, strlen(person1.name) + 1, person1.name);
        strcpy_s(this->name2, strlen(person1.name2) + 1, person1.name2);
        strcpy_s(this->mob_tel, strlen(person1.mob_tel) + 1, person1.mob_tel);
        this->other = person1.other;
    }
    // Вывод на экран: длинный и однострочный варианты
    void printPerson()
    {
        cout << "фамилия: " << surname;
        cout << "\n имя: " << name;
        cout << "\n отчество: " << name2;
        cout << "\n мобильный телефон: " << mob_tel;
        cout << "\n Дополнительная информация: " << other;
        cout << "\n";
    };
    void printPersonLite()
    {
        cout << "Человек: " << surname;
        cout << "\t" << name;
        cout << "\t" << name2;
        cout << "\t" << mob_tel;
        cout << "\t" << other;
        cout << "\n";
    };
    // сеттеры и геттеры
    void setSurname(const char* surname) {
        strcpy_s(this->surname, strlen(surname) + 1, surname);
    }
    char* getSurname() {
        return this->surname;
    }
    void setName(const char* name) {
        strcpy_s(this->name, strlen(name) + 1, name);
    }
    char* getName() {
        return this->name;
    }
    void setName2(const char* name2) {
        strcpy_s(this->name2, strlen(name2) + 1, name2);
    }
    char* getName2() {
        return this->name2;
    }
    void setMob_tel(const char* mob_tel) {
        strcpy_s(this->mob_tel, strlen(mob_tel) + 1, mob_tel);
    }
    char* getMob_tel() {
        return this->mob_tel;
    }
    void setOther(string other) {
        this->other = other;
    }
    string getOther() {
        return this->other;
    }
};
// Конструкторы по умолчанию, копирования, с параметрами, деструктор
Person::Person()
{
    strcpy_s(this->surname, strlen("Ivanov") + 1, "Ivanov");
    strcpy_s(this->name, strlen("Ivan") + 1, "Ivan");
    strcpy_s(this->name2, strlen("Ivanovich") + 1, "Ivanovich");
    strcpy_s(this->mob_tel, strlen("111111") + 1, "11111");
    this->other = "other";
    /*  cout << "Введите фамилию: ";
      cin.getline(surname, 50);
      if (strlen(surname) < 2)
          cin.getline(surname, 50);
      cout << "\nВведите имя: ";
      cin.getline(name, 50);
      cout << "\nВведите отчество: ";
      cin.getline(name2, 50);
      cout << "\nВведите мобильный телефон: ";
      cin.getline(mob_tel, 50);
      cout << "\nДополнительная информация: ";
      cin >> other;*/

      //cout << "\nКонструктор Person " << this << " \n\n";
};
Person::Person(Person& person1)
{
    // cout << "Конструктор копирования Person\n";

    strcpy_s(this->surname, strlen(person1.surname) + 1, person1.surname);
    strcpy_s(this->name, strlen(person1.name) + 1, person1.name);
    strcpy_s(this->name2, strlen(person1.name2) + 1, person1.name2);
    strcpy_s(this->mob_tel, strlen(person1.mob_tel) + 1, person1.mob_tel);
    this->other = person1.other;
};
Person::Person(const char* surname, const char* name, const char* name2,
    const char* mob_tel, const string other)
{
    // cout << "Конструктор с параметрами Person\n";

    strcpy_s(this->surname, strlen(surname) + 1, surname);
    strcpy_s(this->name, strlen(name) + 1, name);
    strcpy_s(this->name2, strlen(name2) + 1, name2);
    strcpy_s(this->mob_tel, strlen(mob_tel) + 1, mob_tel);
    this->other = other;
};
Person::~Person()
{
    delete[]surname;
    delete[]name;
    delete[]name2;
    delete[]mob_tel;
    //cout << "Деструктор Percon" << this << " \n\n";
}

class Rooms
{
private:
public:
    Person* students;
    int resident{ 2 };

    // Конструкторы по умолчанию, с параметром, копирования, деструктор
    Rooms() {
        // cout << "Конструктор: комната\n";
        students = new Person[resident];
    };
    Rooms(int colich) {
        //cout << "Конструктор: комната с параметрами\n";
        students = new Person[resident];
        this->resident = resident;
    };
    Rooms(Rooms& room1) {
        //cout << "Конструктор копирования: Rooms\n";
        this->resident = room1.resident;
        students = new Person[resident];
        for (size_t i = 0; i < resident; i++)
        {
            students[i] = room1.students[i];
        }
    };
    ~Rooms() {
        //cout << "Деструктор Rooms начало" << this << " \n\n";

        /*for (size_t i = 0; i < resident; i++)
        {
            cout << "students" << i << " \t";
            students[i].~Person();
        }*/
        delete[]students;
        students = nullptr;
        //cout << "Деструктор Rooms конец" << this << " \n\n";

    };
    // Перегрузка оператора =
    void operator =(Rooms& room1) {
        // cout << "Перегрузка оператора = Rooms\n";

        this->resident = room1.resident;
        /*for (size_t i = 0; i < resident; i++)
        {
            students[i].~Person();
        }     */
        delete[]students;
        students = new Person[resident];
        for (size_t i = 0; i < resident; i++)
        {
            students[i] = room1.students[i];
        }
    }

    // Напечатать жильцов комнаты
    void printRooms() {
        cout << "Комната\n";
        for (int i = 0; i < 2; i++) {
            students[i].printPersonLite();
        }
        cout << "\n";
    }
};

class Dom
{
private:
public:
    Rooms* room;
    int colich{ 4 };

    // Конструкторы по умолчанию, с параметром, копирования, деструктор
    Dom() {
        //cout << "Конструктор: дом\n";
        room = new Rooms[colich];
    };
    Dom(int colich) {
        //cout << "Конструктор: комната с параметрами\n";
        room = new Rooms[colich];
        this->colich = colich;
    };
    Dom(Dom& dom1) {
        //cout << "Конструктор копирования: комната\n";
        this->colich = dom1.colich;
        room = new Rooms[colich];
        for (size_t i = 0; i < colich; i++)
        {
            room[i] = dom1.room[i];
        }
    };
    ~Dom() {
        //cout << "Деструктор Dom начало" << this << " \n\n";

        /*for (size_t i = 0; i < colich; i++)
        {
            room[i].~Rooms();
        } */
        delete[]room;
        room = nullptr;
        //cout << "Деструктор Dom конец" << this << " \n\n";

    };
    // Перегрузка оператора =
    void operator =(Dom& dom1) {
        //cout << "Перегрузка оператора = Dom\n";

        this->colich = dom1.colich;
        /* for (size_t i = 0; i < colich; i++)
         {
             room[i].~Rooms();
         }*/
        delete[]room;
        room = new Rooms[colich];
        for (size_t i = 0; i < colich; i++)
        {
            room[i] = dom1.room[i];
        }
    }

    // Напечатать жильцов комнаты
    void printDom() {
        cout << "Дом\n";
        for (int i = 0; i < colich; i++) {
            room[i].printRooms();
        }
        cout << "\n";
    }

};


int main()
{
    setlocale(LC_ALL, "Russian");
    //Person person1("Russian", "Russian", "Russian", "Russian", "andrey");
    ////person1.printPerson();
    //Person person2(person1);
    ///*person1.printPersonLite();
    //person2.printPersonLite();*/
    //Person person3("Russian", "Russian", "11111", "222222", "andrey");
    //person3.printPersonLite();
    //person2 = person3;
    //person2.printPersonLite();

    /*Rooms room1;
    room1.printRooms();
    Rooms room2(room1);
    room2.printRooms();*/

    Dom dom1;
    //dom1.room[0].printRooms();
    dom1.printDom();
    cout << "\n";
    return 0;
}