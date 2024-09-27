// Fraction2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Fraction // Дробь
{
private:
	int numerator; // Числитель
	int denominater; // Знаменатель
public:
	Fraction() { numerator = denominater = 1; cout << "DefaultConstructop: \t" << this << "\n"; }
	Fraction(int numerator, int denominater)
	{
		setNumerator(numerator);
		setDenominater(denominater);
	}
	Fraction(int numerator)
	{
		setNumerator(numerator);
		denominater = 1;
	}
	Fraction(const Fraction& obg)
	{
		this->numerator = obg.numerator;
		this->denominater = obg.denominater;
		cout << "2ArgConstructop: \t" << this << "\n";
	}
	~Fraction() { cout << "Destructop: \t\t" << this << "\n"; }

	// Геттеры и сеттеры
	double getNumerator() const { return numerator; }
	void setNumerator(double numerator) { this->numerator = numerator; }
	double getDenominater() const { return denominater; }
	void setDenominater(double denominater)
	{
		if (denominater != 0) {
			this->denominater = denominater;
		}
		else
		{
			cout << " Error \n denominater should not be equal 0 (!=0) (Не должен быть равен 0)\n";
			this->denominater = 1;
		}
	}

	//Операторы
	Fraction& operator =(const Fraction& obg)
	{
		this->numerator = obg.numerator;
		this->denominater = obg.denominater;
		cout << "CopyAssigment: \t\t" << this << "\n";
		return *this;
	}
	Fraction& operator ++()
	{
		reduceFraction();
		numerator += denominater;
		cout << "Assigment++: \t\t" << this << "\n";
		return *this;
	}
	Fraction operator ++(int)
	{
		reduceFraction();
		Fraction old = *this;
		this->numerator += this->denominater;
		cout << "++Assigment: \t\t" << &old << "\n";
		return old;
	}
	Fraction& operator --()
	{
		reduceFraction();
		numerator -= denominater;
		cout << "Assigment++: \t\t" << this << "\n";
		return *this;
	}
	Fraction operator --(int)
	{
		reduceFraction();
		Fraction old = *this;
		this->numerator -= this->denominater;
		cout << "++Assigment: \t\t" << &old << "\n";
		return old;
	}

	//Методы
	// дробь на экран
	void printFraction() const { cout << numerator << "/" << denominater << " \n"; }
	void printProperFraction() //Преобразование в правильную дробь для печати
	{
		reduceFraction();
		cout << "Правильная дробь с целой частью:\t";
		if (numerator / denominater > 0) 
			cout << numerator / denominater << " ";
		if (numerator - numerator / denominater != 0) {
			if (numerator / denominater > 0) {
				cout << "(";
			}
			cout << numerator % denominater << "/" << denominater;
			if (numerator / denominater > 0) { cout << ")"; 
			}
		}
		cout << " \n";
	}
	//сокращение дроби
	void reduceFraction()
	{
		//cout << " " << (this->denominater < 0) << "\n";
		//убираем отрицательность
		if (this->denominater < 0) {
			numerator *= -1;
			denominater *= -1;
		}
		for (int i = 2; (i <= numerator && i <= denominater); i++) //сокращаем
		{
			//printFraction();
			//cout << "\ti=" << i << "\t";
			if ((numerator % i == 0) && (denominater % i == 0)) {
				//cout << numerator % i << "\t";
				//cout << denominater % i << "\t";
				numerator /= i;
				denominater /= i;
				i = 1;
			}
			/* else {
				 cout << numerator % i << "\t";
				 cout << denominater % i << "\t";
			 }
			 printFraction();
			 cout << "\n";*/
		}
		//cout << "reduceFraction: \t\t" << this << "\n";
	}
};

//Внешние функции
bool operator ==(Fraction& obg1, Fraction& obg2) //дроби будем изменять - сокращать
{
	obg1.reduceFraction();
	obg2.reduceFraction();
	return obg1.getNumerator() == obg2.getNumerator() && obg1.getDenominater() == obg2.getDenominater();
	cout << "Assigment==: \t\t\n";
}
// функция, которая возвращает дробь, результат сложения дробей
Fraction operator +(const Fraction& obg1, const Fraction& obg2)
{
	Fraction Result;
	// числитель и знаменатель: по математическому правилу
	Result.setNumerator(obg1.getNumerator() * obg2.getDenominater() + obg2.getNumerator() * obg1.getDenominater());
	Result.setDenominater(obg1.getDenominater() * obg2.getDenominater());
	Result.reduceFraction(); //сокращаем
	cout << "+Assigment: \t\t" << &Result << "\n";
	return Result;
}
// результат вычитания дробей
Fraction operator -(const Fraction& obg1, const Fraction& obg2)
{
	Fraction Result;
	// числитель и знаменатель: по математическому правилу
	Result.setNumerator(obg1.getNumerator() * obg2.getDenominater() - obg2.getNumerator() * obg1.getDenominater());
	Result.setDenominater(obg1.getDenominater() * obg2.getDenominater());
	Result.reduceFraction(); //сокращаем
	cout << "-Assigment: \t\t" << &Result << "\n";
	return Result;
}
// результат произведения дробей
Fraction operator *(const Fraction& obg1, const Fraction& obg2)
{
	Fraction Result;
	// числитель и знаменатель: по математическому правилу
	Result.setNumerator(obg1.getNumerator() * obg2.getNumerator());
	Result.setDenominater(obg1.getDenominater() * obg2.getDenominater());
	Result.reduceFraction(); //сокращаем    
	cout << "*Assigment: \t\t" << &Result << "\n";
	return Result;
}
// результат деления дробей
Fraction operator /(const Fraction& obg1, const Fraction& obg2)
{
	Fraction Result;
	if (obg2.getNumerator() == 0)
	{
		cout << " Error \n division by zero (Деление на ноль - операция не выполнена)\n";
	}
	// числитель и знаменатель: по математическому правилу
	else
	{
		Result.setNumerator(obg1.getNumerator() * obg2.getDenominater());
		Result.setDenominater(obg1.getDenominater() * obg2.getNumerator());
		Result.reduceFraction(); //сокращаем    
	}
	cout << "/Assigment: \t\t" << &Result << "\n";
	return Result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Первая, вторая и третья дроби.\n";
	Fraction drob1;
	drob1.printFraction();
	drob1.printProperFraction();
	Fraction drob2(1, 2);
	drob2.printFraction();
	drob2.printProperFraction();
	Fraction drob3(2, 3);
	drob3.printFraction();
	drob3.printProperFraction();

	//cout << "Четвертая дробь.\n";
	Fraction drob4 = drob3 + drob2;
	cout << "\nЧетвертая дробь, как сумма третьей и второй.\n";
	drob4.printFraction();
	drob4.printProperFraction();

	//cout << "Пятая дробь.\n";
	Fraction drob5 = drob4 - drob1;
	cout << "\nПятая дробь, как разность четвертой и первой.\n";
	drob5.printFraction();
	drob5.printProperFraction();

	//cout << "Шестая дробь.\n";
	Fraction drob6 = drob3 * drob2;
	cout << "\nШестая дробь, как произведение третьей и второй.\n";
	drob6.printFraction();

	//cout << "Седьмая дробь.\n";
	Fraction drob7;
	drob7 = drob4 / drob5;
	cout << "\nСедьмая дробь, как частное четвертой и пятой.\n";
	drob7.printFraction();

	cout << "\nВосьмая дробь.\n";
	Fraction drob8(-200, -40);
	drob8.printFraction();
	cout << "сокращаем\n";
	drob8.reduceFraction();
	drob8.printFraction();

	cout << "\nДевятая дробь, без дробной части.\n";
	Fraction drob9(-200, -200);
	drob9.printFraction();
	drob9.printProperFraction();

	cout << "\n\n";
}