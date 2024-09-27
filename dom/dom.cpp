/*Курс
«Объектно-ориентированное
программирование на C++»
Встреча №8
Тема: КонсТрукТор Переноса
Задания для самостоятельной работы:
Задание 2
Добавить в уже существующий проект многоквартирного
дома с класса Дом, Квартира, Человек конструктор переноса в те
классы, где это необходимо. Память под поля класса выделять динамически.
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
	//Конструкторы по умолчанию 
	Person() {
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
	};;
	//Конструктор копирования
	Person(const Person& person1) {
		// cout << "Конструктор копирования Person\n";
		strcpy_s(this->surname, strlen(person1.surname) + 1, person1.surname);
		strcpy_s(this->name, strlen(person1.name) + 1, person1.name);
		strcpy_s(this->name2, strlen(person1.name2) + 1, person1.name2);
		strcpy_s(this->mob_tel, strlen(person1.mob_tel) + 1, person1.mob_tel);
		this->other = person1.other;
	};;
	//Конструктор с параметрами
	Person(const char* surname, const char* name, const char* name2, const char* mob_tel, const string other) {
		// cout << "Конструктор с параметрами Person\n";
		strcpy_s(this->surname, strlen(surname) + 1, surname);
		strcpy_s(this->name, strlen(name) + 1, name);
		strcpy_s(this->name2, strlen(name2) + 1, name2);
		strcpy_s(this->mob_tel, strlen(mob_tel) + 1, mob_tel);
		this->other = other;
	}
	// Деструктор
	~Person() {
		delete[]surname;
		delete[]name;
		delete[]name2;
		delete[]mob_tel;
		//cout << "Деструктор Percon" << this << " \n\n";
	}
	//Конструктор перемещающий
	Person(Person&& obj) :surname{ obj.surname }, name{ obj.name }, name2{ obj.name2 }, mob_tel{ obj.mob_tel }, other{ obj.other }
	{
		cout << "\nЗапустился контруктор перемещения " << this << "\n";
		obj.surname = nullptr;
		obj.name = nullptr;
		obj.name2 = nullptr;
		obj.mob_tel = nullptr;		
	};
	// Перегрузка оператора = перемещения
	Person& operator =(Person&& obj) {
		//cout << "Перегрузка оператора = перемещения Person\n";
		if (this == &obj) return *this;
		delete[]surname;
		delete[]name;
		delete[]name2;
		delete[]mob_tel;
		this->surname = obj.surname;
		this->name = obj.name;
		this->name2 = obj.name2;
		this->mob_tel = obj.mob_tel;
		this->other = obj.other;
		obj.surname = nullptr;
		obj.name = nullptr;
		obj.name2 = nullptr;
		obj.mob_tel = nullptr;
		return *this;
	}
	// Перегрузка оператора =
	Person& operator =(const Person& person1) { // проверить!!!
		//cout << "Перегрузка оператора = Person\n";
		if (this == &person1) return *this;
		strcpy_s(this->surname, strlen(person1.surname) + 1, person1.surname);
		strcpy_s(this->name, strlen(person1.name) + 1, person1.name);
		strcpy_s(this->name2, strlen(person1.name2) + 1, person1.name2);
		strcpy_s(this->mob_tel, strlen(person1.mob_tel) + 1, person1.mob_tel);
		this->other = person1.other;
		return *this;
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
// Заполнение данных // Правостороннее значение объекта
Person factoryPerson() {
	Person temp("Temp", "Temp", "Temp", "Russian", "andrey");
	return temp;
}

class Rooms
{
private:
public:
	Person* students;
	int resident{ 2 };

	// Конструкторы по умолчанию
	Rooms() {
		// cout << "Конструктор: комната\n";
		students = new Person[resident];
	};
	//Конструктор с параметрами
	Rooms(int colich) {
		//cout << "Конструктор: комната с параметрами\n";
		students = new Person[colich];
		this->resident = colich;
	};
	//Конструктор копирования
	Rooms(Rooms& room1) {
		//cout << "Конструктор копирования: Rooms\n";
		this->resident = room1.resident;
		students = new Person[resident];
		for (size_t i = 0; i < resident; i++)
		{
			students[i] = room1.students[i];
		}
	};
	//Конструктор перемещающий
	Rooms(Rooms&& obj) {
		cout << "\nЗапустился контруктор перемещения Rooms" << this << "\n";
		if (this == &obj) return;
		delete[]students;
		this->resident = obj.resident;
		students = obj.students;
		obj.students = nullptr;
	}
	// Деструктор
	~Rooms() {
		//cout << "Деструктор Rooms начало" << this << " \n\n";		
		delete[]students;
		students = nullptr;
		//cout << "Деструктор Rooms конец" << this << " \n\n";
	};
	// Перегрузка оператора = перемещения
	Rooms& operator =(Rooms&& obj) {
		//cout << "Перегрузка оператора = перемещения Rooms\n";
		if (this == &obj) return*this;
		delete[]students;
		this->resident = obj.resident;
		students = obj.students;
		obj.students = nullptr;
		return *this;
	}
	// Перегрузка оператора =
	Rooms& operator =(const Rooms& room1) {
		if (this == &room1) return *this;
		this->resident = room1.resident;
		delete[]students;
		students = new Person[resident];
		for (size_t i = 0; i < resident; i++)
		{
			students[i] = room1.students[i];
		}
		return *this;
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
// Заполнение данных // Правостороннее значение объекта
Rooms factoryRooms() {
	Rooms temp1(2);
	return temp1;
}

class Dom
{
private:
public:
	Rooms* room;
	int colich{ 4 };

	// Конструкторы по умолчанию
	Dom() {
		//cout << "Конструктор: дом\n";
		room = new Rooms[colich];
	};
	//Конструктор с параметрами
	Dom(int colich) {
		//cout << "Конструктор: дом с параметрами\n";
		room = new Rooms[colich];
		this->colich = colich;
	};
	//Конструктор копирования
	Dom(Dom& dom1) {
		//cout << "Конструктор копирования дом\n";
		this->colich = dom1.colich;
		room = new Rooms[colich];
		for (size_t i = 0; i < colich; i++)
		{
			room[i] = dom1.room[i];
		}
	};
	//Конструктор перемещающий
	Dom(Dom&& obj) {
		cout << "\nЗапустился контруктор перемещения Дом" << this << "\n";
		if (this == &obj) return;
		delete[]room;
		this->colich = obj.colich;
		room = obj.room;
		obj.room = nullptr;
	}
	// Деструктор
	~Dom() {
		//cout << "Деструктор Dom начало" << this << " \n\n";
		delete[]room;
		room = nullptr;
		//cout << "Деструктор Dom конец" << this << " \n\n";
	};
	// Перегрузка оператора =
	Dom& operator =(const Dom& dom1) {
		//cout << "Перегрузка оператора = Dom\n";
		if (this == &dom1) return *this;
		delete[]room;
		this->colich = dom1.colich;
		room = dom1.room;
		for (size_t i = 0; i < colich; i++)
		{
			room[i] = dom1.room[i];
		}
		return *this;
	}
	// Перегрузка оператора = перемещения
	Dom& operator =(Dom&& obj) {
		//cout << "Перегрузка оператора = перемещения дом\n";
		if (this == &obj) return*this;
		delete[]room;
		this->colich = obj.colich;
		room = obj.room;
		obj.room = nullptr;
		return *this;
	}
	// Напечатать жильцов дома
	void printDom() {
		cout << "Дом\n";
		for (int i = 0; i < colich; i++) {
			room[i].printRooms();
		}
		cout << "\n";
	}
};
// Заполнение данных // Правостороннее значение объекта
Dom factoryDom() {
	Dom temp1(2);
	return temp1;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	
	Dom dom1;
	dom1.printDom();
	cout << "\n";
	return 0;
}