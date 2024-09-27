// Fraction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Fraction // Дробь
{
private:
	int numerator; // Числитель
	int denominater; // Знаменатель
public:
	//конструкторы и деструктор
	Fraction() { numerator = denominater = 1;  } //cout << "DefaultConstructop: \t" << this << "\n";
	Fraction(int numerator)
	{
		setNumerator(numerator);
		denominater = 1;
	}
	Fraction(double numeratorObg)
	{
		this->denominater = 1;
		for (; (int)numeratorObg != numeratorObg; denominater *= 10, numeratorObg *= 10) {};
		numerator = (int)numeratorObg;//в этот момент уже нет дробной части
		reduceFraction();
	}
	Fraction(int numerator, int denominater)
	{
		setNumerator(numerator);
		setDenominater(denominater);
	}
	Fraction(const Fraction& obg)
	{
		this->numerator = obg.numerator;
		this->denominater = obg.denominater;
		//cout << "2ArgConstructop: \t" << this << "\n";
	}
	~Fraction() {} //cout << "Destructop: \t\t" << this << "\n"; 

	// Геттеры и сеттеры
	int getNumerator() const { return numerator; }
	void setNumerator(int numerator) { this->numerator = numerator; }
	int getDenominater() const { return denominater; }
	// с проверкой на 0
	void setDenominater(int denominater)
	{
		if (denominater != 0) {
			this->denominater = denominater;
		}
		else
		{
			cout << " Error:  denominater should not be equal 0 (!=0) (Не должен быть равен 0)\n";
			this->denominater = 1;
		}
	}

	//Операторы
	Fraction& operator =(const Fraction& obg)
	{
		this->numerator = obg.numerator;
		this->denominater = obg.denominater;
		//cout << "CopyAssigment: \t\t" << this << "\n";
		return *this;
	}
	Fraction& operator =(int obg)
	{
		this->numerator = obg;
		this->denominater = 1;
		//cout << "CopyAssigment: \t\t" << this << "\n";
		return *this;
	}
	Fraction& operator =(double obg)
	{
		Fraction temp(obg);
		return *this;
	}


	Fraction& operator +=(int obg)
	{
		numerator += (denominater * obg);
		reduceFraction();
		//cout << "Assigment +=: \t\t" << this << "\n";
		return *this;
	}
	Fraction& operator -=(int obg)
	{
		reduceFraction();
		numerator -= denominater * obg;
		//cout << "Assigment -=: \t\t" << this << "\n";
		return *this;
	}
	Fraction& operator *=(int obg)
	{
		reduceFraction();
		numerator = numerator * obg;
		//cout << "Assigment *=: \t\t" << this << "\n";
		return *this;
	}
	// с проверкой на 0
	Fraction& operator /=(int obg)
	{
		if (obg != 0) {
			reduceFraction();
			denominater = denominater * obg;
			//cout << "Assigment /*: \t\t" << this << "\n";			
		}
		else
		{
			cout << " Error: divizion by zero \n Деление на ноль, операция не выполнена!\n";
		}
		return *this;
	}


	Fraction& operator +=(double numeratorObg)
	{
		Fraction temp(numeratorObg);
		this->numerator = this->numerator * temp.getDenominater() + temp.getNumerator() * this->denominater;
		this->denominater = this->denominater * temp.getDenominater();
		reduceFraction(); //сокращаем
		return *this;
	}
	Fraction& operator -=(double numeratorObg)
	{
		Fraction temp(numeratorObg);
		this->numerator = this->numerator * temp.getDenominater() + temp.getNumerator() * this->denominater;
		this->denominater = this->denominater * temp.getDenominater();
		reduceFraction(); //сокращаем
		return *this;
	}
	Fraction& operator *=(double numeratorObg)
	{
		Fraction temp(numeratorObg);
		this->numerator *= temp.getNumerator();
		this->denominater *= temp.getDenominater();
		reduceFraction();
		return *this;
	}
	// с проверкой на 0
	Fraction& operator /=(double numeratorObg)
	{
		if (numeratorObg != 0) {
			Fraction temp(numeratorObg);
			this->numerator *= temp.getDenominater();
			this->denominater *= temp.getNumerator();
			reduceFraction();

			// // Первые варианты то же самое, но без временного объекта
			//int denominatorObg = 1;
			//for (; (int)numeratorObg != numeratorObg; denominatorObg *= 10, numeratorObg *= 10) {};

			//reduceFraction();
			//this->numerator *= denominatorObg;
			//this->denominater *= (int)numeratorObg;
		}
		else
		{
			cout << " Error: divizion by zero \n Деление на ноль, операция не выполнена!\n";
		}
		//cout << "Assigment /=: \t\t" << this << "\n";
		return *this;
	}



	Fraction& operator +=(Fraction& obg)
	{
		//reduceFraction();//сокращаем
		//obg.reduceFraction();//сокращаем
		this->numerator = this->numerator * obg.getDenominater() + obg.getNumerator() * this->denominater;
		this->denominater = this->denominater * obg.getDenominater();
		reduceFraction(); //сокращаем
		//cout << "Assigment+=: \t\t" << this << "\n";
		return *this;
	}
	Fraction& operator -=(Fraction& obg)
	{
		//reduceFraction();//сокращаем
		//obg.reduceFraction();//сокращаем
		this->numerator = this->numerator * obg.getDenominater() - obg.getNumerator() * this->denominater;
		this->denominater = this->denominater * obg.getDenominater();
		reduceFraction(); //сокращаем
		//cout << "Assigment+=: \t\t" << this << "\n";
		return *this;
	}
	Fraction& operator *=(Fraction& obg)
	{
		//reduceFraction();
		//obg.reduceFraction();
		this->numerator *= obg.getNumerator();
		this->denominater *= obg.getDenominater();
		//cout << "Assigment*=: \t\t" << this << "\n";
		reduceFraction();
		return *this;
	}
	Fraction& operator /=(Fraction& obg)
	{
		reduceFraction();
		obg.reduceFraction();
		this->numerator *= obg.getDenominater();
		this->denominater *= obg.getNumerator();
		//cout << "Assigment /=: \t\t" << this << "\n";
		return *this;
	}


	Fraction& operator ++()
	{
		reduceFraction();
		numerator += denominater;
		//cout << "Assigment++: \t\t" << this << "\n";
		return *this;
	}
	Fraction operator ++(int)
	{
		reduceFraction();
		Fraction old = *this;
		this->numerator += this->denominater;
		//cout << "++Assigment: \t\t" << &old << "\n";
		return old;
	}
	Fraction& operator --()
	{
		reduceFraction();
		numerator -= denominater;
		//cout << "Assigment++: \t\t" << this << "\n";
		return *this;
	}
	Fraction operator --(int)
	{
		reduceFraction();
		Fraction old = *this;
		this->numerator -= this->denominater;
		//cout << "++Assigment: \t\t" << &old << "\n";
		return old;
	}

	//Методы
	// дробь на экран
	void printFraction() const { cout << numerator << "/" << denominater << " \n"; }
	void printProperFraction() //Преобразование в правильную дробь для печати
	{
		reduceFraction();
		cout << "Правильная дробь с целой частью:\t";

		// выводим целую часть, если она есть (она может быть отрицательной)
		if (numerator / denominater != 0)
			cout << numerator / denominater << " ";

		// выводим дробную часть, если она есть 
		// провераем числитель дробной части, если =0 то дробной части нет
		if (numerator - (numerator / denominater) * denominater != 0)
		{
			//Если перед этим была целая часть, выводим скобки
			if (numerator / denominater > 0) { cout << "("; }
			cout << numerator % denominater << "/" << denominater; //Дробная часть
			if (numerator / denominater > 0) { cout << ")"; }
		}
		cout << " \n";
	}
	//сокращение дроби
	void reduceFraction()
	{
		//если числитель = 0, то знаминатель устанавливаем =1 
		// для упрощения последующих расчетов
		if (this->numerator == 0)
		{
			denominater = 1;
		}
		//убираем отрицательность
		if (this->denominater < 0)
		{
			numerator *= -1;
			denominater *= -1;
		}
		//сокращаем
		for (int i = 2; (i <= numerator && i <= denominater); i++)
		{
			if ((numerator % i == 0) && (denominater % i == 0))
			{
				numerator /= i;
				denominater /= i;
				i = 1;
			}
		}
		//Если подобных расчетов много, то можно создать массив простых чисел (побольше, чем в примере)
		// arr[10]{2,3,5,7,11,13,17,19,23,29}
		// в цикле проверять не все числа, а только простые примерно так:

	 /* for (int i = 0; (arr[i] <= numerator && arr[i] <= denominater); )
		{
			if ((numerator % arr[i] == 0) && (denominater % arr[i] == 0))
			{
				numerator /= arr[i];
				denominater /= arr[i];
			else
				i++; //к следующему простому числу переходим только,
					 //если if получил ложь, иначе проверяем еще раз деление на этот же множитель
			}
		}*/
	}
};

//Внешние функции
bool operator ==(Fraction& obg1, Fraction& obg2) //дроби будем изменять - сокращать
{
	obg1.reduceFraction();
	obg2.reduceFraction();
	return obg1.getNumerator() == obg2.getNumerator() && obg1.getDenominater() == obg2.getDenominater();
}
bool operator !=(Fraction& obg1, Fraction& obg2) //дроби будем изменять - сокращать
{
	obg1.reduceFraction();
	obg2.reduceFraction();
	return obg1.getNumerator() != obg2.getNumerator() || obg1.getDenominater() != obg2.getDenominater();
}
bool operator > (const Fraction& obg1, const Fraction& obg2)
{
	return obg1.getNumerator() * obg2.getDenominater() > obg2.getNumerator() * obg1.getDenominater();
}
bool operator < (const Fraction& obg1, const Fraction& obg2)
{
	return obg1.getNumerator() * obg2.getDenominater() < obg2.getNumerator() * obg1.getDenominater();
}
bool operator >= (const Fraction& obg1, const Fraction& obg2)
{
	return obg1.getNumerator() * obg2.getDenominater() > obg2.getNumerator() * obg1.getDenominater();
}
bool operator <= (const Fraction& obg1, const Fraction& obg2)
{
	return obg1.getNumerator() * obg2.getDenominater() <= obg2.getNumerator() * obg1.getDenominater();
}

// функция, которая возвращает дробь, результат сложения дробей
Fraction operator +(const Fraction& obg1, const Fraction& obg2)
{
	Fraction Result;
	// числитель и знаменатель: по математическому правилу
	Result.setNumerator(obg1.getNumerator() * obg2.getDenominater() + obg2.getNumerator() * obg1.getDenominater());
	Result.setDenominater(obg1.getDenominater() * obg2.getDenominater());
	Result.reduceFraction(); //сокращаем
	//cout << "+Assigment: \t\t" << &Result << "\n";
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
	//cout << "-Assigment: \t\t" << &Result << "\n";
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
	//cout << "*Assigment: \t\t" << &Result << "\n";
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
	//cout << "/Assigment: \t\t" << &Result << "\n";
	return Result;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Первая, вторая и третья дроби.\n";
	Fraction drob1;
	drob1.printFraction();
	//drob1.printProperFraction();
	Fraction drob2 = 0.5;
	drob2 += drob1;
	drob2.printFraction();
	//drob2.printProperFraction();
	Fraction drob3(2, 3);
	drob3.printFraction();

	drob2 /= drob3;
	drob2.printFraction();

	drob2 /= 0;
	drob2.printFraction();
	cout << "\n" << (drob2 >= drob2) << "\n";

	//drob3.printProperFraction();

	//cout << "Четвертая дробь.\n";
	//Fraction drob4 = drob3 + drob2;
	//cout << "\nЧетвертая дробь, как сумма третьей и второй.\n";
	//drob4.printFraction();
	//drob4.printProperFraction();

	////cout << "Пятая дробь.\n";
	//Fraction drob5 = drob4 - drob1;
	//cout << "\nПятая дробь, как разность четвертой и первой.\n";
	//drob5.printFraction();
	//drob5.printProperFraction();

	////cout << "Шестая дробь.\n";
	//Fraction drob6 = drob3 * drob2;
	//cout << "\nШестая дробь, как произведение третьей и второй.\n";
	//drob6.printFraction();

	////cout << "Седьмая дробь.\n";
	//Fraction drob7;
	//drob7 = drob4 / drob5;
	//cout << "\nСедьмая дробь, как частное четвертой и пятой.\n";
	//drob7.printFraction();

	//cout << "\nВосьмая дробь.\n";
	//Fraction drob8(-200, -40);
	//drob8.printFraction();
	//cout << "сокращаем\n";
	//drob8.reduceFraction();
	//drob8.printFraction();

	cout << "\nДевятая дробь, без дробной части.\n";
	Fraction drob9(-200, -200);
	drob9.printFraction();
	drob9.printProperFraction();


	cout << "\n\n";
}
