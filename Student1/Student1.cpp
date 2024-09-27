/*Курс
«Объектно-ориентированное
программирование на C++»
Встреча №8
Тема: КонсТрукТор Переноса
Задания для самостоятельной работы:
Задание 1
Добавить в уже существующий класс Student конструктор переноса. Память под поля класса выделять динамически.
*/

#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

class Student
{
private:
	char* surname{ new char[50] };
	char* name{ new char[50] };
	char* name2{ new char[50] };
	char* mob_tel{ new char[50] };
	string other;
public:
	//Конструкторы по умолчанию 
	Student() {
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
	Student(const Student& person1) {
		// cout << "Конструктор копирования Person\n";
		strcpy_s(this->surname, strlen(person1.surname) + 1, person1.surname);
		strcpy_s(this->name, strlen(person1.name) + 1, person1.name);
		strcpy_s(this->name2, strlen(person1.name2) + 1, person1.name2);
		strcpy_s(this->mob_tel, strlen(person1.mob_tel) + 1, person1.mob_tel);
		this->other = person1.other;
	};;
	//Конструктор с параметрами
	Student(const char* surname, const char* name, const char* name2, const char* mob_tel, const string other) {
		// cout << "Конструктор с параметрами Person\n";
		strcpy_s(this->surname, strlen(surname) + 1, surname);
		strcpy_s(this->name, strlen(name) + 1, name);
		strcpy_s(this->name2, strlen(name2) + 1, name2);
		strcpy_s(this->mob_tel, strlen(mob_tel) + 1, mob_tel);
		this->other = other;
	}
	// Деструктор
	~Student() {
		delete[]surname;
		delete[]name;
		delete[]name2;
		delete[]mob_tel;
		//cout << "Деструктор Percon" << this << " \n\n";
	}
	//Конструктор перемещающий
	Student(Student&& obj) :surname{ obj.surname }, name{ obj.name }, name2{ obj.name2 }, mob_tel{ obj.mob_tel }, other{ obj.other }
	{
		cout << "\nЗапустился контруктор перемещения " << this << "\n";
		obj.surname = nullptr;
		obj.name = nullptr;
		obj.name2 = nullptr;
		obj.mob_tel = nullptr;
	};
	// Перегрузка оператора = перемещения
	Student& operator =(Student&& obj) {
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
	Student& operator =(const Student& person1) { // проверить!!!
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
	void printStudent()
	{
		cout << "фамилия: " << surname;
		cout << "\n имя: " << name;
		cout << "\n отчество: " << name2;
		cout << "\n мобильный телефон: " << mob_tel;
		cout << "\n Дополнительная информация: " << other;
		cout << "\n";
	};
	void printStudentLite()
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
Student factoryStudent() {
	Student temp("Temp", "Temp", "Temp", "Russian", "andrey");
	return temp;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Student student1;
	student1.printStudent();
	cout << "\n";
	Student student2{ factoryStudent()};
	student2.printStudent();
	cout << "\n";
	return 0;
}