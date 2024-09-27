/*Курс
«Объектно-ориентированное
программирование на C++»
Встреча №2
Тема: Конструкторы, деструкторы
Задание.
Создайте приложение "Телефонная книга". Необходимо
хранить данные об абоненте (ФИО, домашний телефон,
рабочий телефон, мобильный телефон, дополнительная
информация о контакте) внутри соответствующего класса. Наполните класс переменными-членами,
функциями-членами, конструкторами, inline-функциями-членами,
используйте инициализаторы, реализуйте деструктор.
Обязательно необходимо выделять динамически память
под ФИО. Предоставьте пользователю возможность добавлять новых абонентов, удалять абонентов,
искать абонентов по ФИО, показывать всех абонентов, сохранять
информацию в файл и загружать из файла.
*/


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Person
{
private:
	const int poleSize = 7;

	int pole[7]{ 1,2,3,4,5,6,7, };
	/*int surnameSize{ 1 };
	int nameSize{ 2 };
	int name2Size{ 3 };
	int home_telSize{ 4 };
	int work_telSize{ 5 };
	int mob_telSize{ 6 };
	int otherSize{ 7 };*/

	char* data[7]{ // 7  полей
		new char[pole[0]] {'1'},
		new char[pole[1]] {'2','2'},
		new char[pole[2]] {'3','3','3'},
		new char[pole[3]] {'4','4','4','4'},
		new char[pole[4]] {'5','5','5','5','5'},
		new char[pole[5]] {'6','6','6','6','6','6'},
		new char[pole[6]] {'7','7','7','7','7','7','7'}
	};

public:
	int getPoleSize()
	{
		return poleSize;
	}
	int getPole(int i)
	{
		return pole[i];
	}
	char getData(int i, int j)
	{
		return data[i][j];
	}
	Person(int a)
	{
		char temp[1]{ ' ' };

		for (int i = 0; i < poleSize; i++)
		{
			setPole(temp, i, sizeof(temp));
		}
		setPersonConsole();
		cout << "\nЗапустился конcтруктор  " << this << "\n";
	};
	Person()
	{
		char temp[1]{ ' ' };

		for (int i = 0; i < poleSize; i++)
		{
			setPole(temp, i, sizeof(temp));
		}
		cout << "\nЗапустился конcтруктор по умолчанию " << this << "\n";
	};

	Person(const char* surname, const char* name, const char* name2, const char* home_tel, const char* work_tel,
		const char* mob_tel, const char* other)
	{
		cout << "\nКонструктор со значениями " << this << " \n";
		setPole(surname, 0, sizeof(surname));
		setPole(name, 1, sizeof(name));
		setPole(name2, 2, sizeof(name2));
		setPole(home_tel, 3, sizeof(home_tel));
		setPole(mob_tel, 4, sizeof(mob_tel));
		setPole(work_tel, 5, sizeof(work_tel));
		setPole(other, 6, sizeof(other));
	};
	~Person()
	{
		cout << "\nЗапустился деструктор " << this << "\n";
		for (int i = 0; i < poleSize; i++)
		{
			delete[]data[i];
		}
		cout << "конец деструктора " << "\n";

	};

	void MonitorPerson()
	{
		cout << "\nВывод объекта класса " << this << "\n";
		for (int i = 0; i < poleSize; i++)
		{
			MonitorPole(i);
		}
		cout << "\n";
	}

	void MonitorPole(int i)
	{
		//cout << "\nВывод поля объекта " << this << "\n";
		cout << textZaprosa(i) << ": ";
		for (size_t j = 0; j < pole[i]; j++)
		{
			cout << data[i][j] << "";
		}
		cout << "   размер " << pole[i];
		cout << "\n";
	}

	string textZaprosa(int i)
	{
		switch (i + 1)
		{
		case 1:
			return "фамилия";
			break;
		case 2:
			return "имя";
			break;
		case 3:
			return "отчество";
			break;
		case 4:
			return "домашний телефон";
			break;
		case 5:
			return "рабочий телефон";
			break;
		case 6:
			return "мобильный телефон";
			break;
		case 7:
			return "другое";
			break;
			/*default:
				return "ошибка";
				break;*/
		};
	}
	//Изменение целого объекта с консоли   
	void setPersonConsole()
	{
		char temp[50]{};

		for (int i = 0; i < poleSize; i++)
		{
			setPoleConsole(i);
		}
	}

	//Изменение поля с консоли   
	void setPoleConsole(int i)
	{
		char temp[50]{};
		cout << "Введите новое значение - " << textZaprosa(i) << ": ";
		cin >> temp;
		//определяем размер введенного текста
		int tempSize = 0;
		for (tempSize = 0; tempSize < 50; tempSize++)
		{
			if (temp[tempSize] == '\0')
				break;
		}
		//cout << "размер текста " << tempSize << "\n";

		//перезаписываем поле
		if (pole[i] != tempSize)
		{
			pole[i] = tempSize;
			delete[]data[i];
			data[i] = new char[pole[i]];
		}
		for (size_t j = 0; j < pole[i]; j++)
		{
			data[i][j] = temp[j];
		}
	}

	//Изменение поля
	void setPole(const char* temp, int i, int sizeTemp)
	{
		int tempSize = 0;
		for (tempSize = 0; tempSize < 50; tempSize++)
		{
			if (temp[tempSize] == '\0')
				break;
		}
		if (pole[i] != tempSize)
		{
			pole[i] = tempSize;
			delete[]data[i];
			data[i] = new char[pole[i]];
		}
		for (size_t j = 0; j < pole[i]; j++)
		{
			data[i][j] = temp[j];
		}
	}
	//Изменение размера поля
	void setPoleSize(int i, int sizeTemp)
	{
		if (pole[i] != sizeTemp)
		{
			pole[i] = sizeTemp;
			delete[]data[i];
			data[i] = new char[pole[i]];
		}
	}

	//Изменение знака
	void setZnak(char znak, int i, int j)
	{
		data[i][j] = znak;
	}

};


int main()
{
	setlocale(LC_ALL, "Russian");

	vector<Person*> vectorPerson; // пустой список 
	//vectorPerson.reserve(5);
	vectorPerson.push_back(new Person("Ivanov", "Ivan", "Ivanovich", "3-33-33", "33-33-33", "333-33-33", "Russian"));
	vectorPerson.push_back(new Person("Petrov", "Petr", "Petrovich", "2-22-22", "2-22-22", "2-22-22", "Ru"));
	/*vectorPerson.push_back(new Person("Sidorov", "Sidor", "Sidorovich", "1-11-11", "1-11-11", "1-11-11", "Rus"));
	vectorPerson.push_back(new Person("Sid", "Sidor", "Sidorovich", "1-11-11", "1-11-11", "1-11-11", "Rus"));*/

	string path2 = "myFile2.txt";
	ofstream fout2;
	fout2.open(path2);
	if (!fout2.is_open())
		cout << "Ошибка открытия файла!\n";
	else
	{
		cout << "Запись в файл в байтовом виде\n";
		for (auto it = vectorPerson.begin(); it != vectorPerson.end(); it++)
		{
			int temp = ((*it)->getPoleSize());
			//cout << temp << " количество полей \n";
			fout2.write((char*)&temp, sizeof(int));	//Запись в файл в байтовом виде int	количество полей
			//cout << temp << " количество полей \n";
			for (int i = 0; i < (*it)->getPoleSize(); i++)
			{
				temp = (*it)->getPole(i);
				fout2.write((char*)&temp, sizeof(int));	//Запись в файл в байтовом виде int	размер полей
				for (int j = 0; j < (*it)->getPole(i); j++)
				{
					char temp1 = (*it)->getData(i, j);
					fout2.write((char*)&temp1, sizeof(char));	//Запись в файл в байтовом виде char	
					//cout << temp1 << "  ";
				}
			}
		}
		fout2.close();
	};




	int event = 0; // диалог с пользователем
	while (1) {
		cout << "Что будем делать: \n";
		cout << "1 - добавить абонента.\n";
		cout << "2 - удалить абонента. \n";
		cout << "3 - искать абонента по фамилии. \n";
		cout << "4 - вывести на экран всех абонентов. \n";
		cout << "5 - сохранить справочник в файл. \n";
		cout << "6 - считать справочник из файла. \n";
		cout << "7 - выход. \n";

		event = 0;
		while (1) {// Цикл запроса действия
			cin >> event;
			if ((event > 0) && (event <= 7)) break;
			else cout << "нет такого пункта в меню \n";
		}
		switch (event)
		{
		case 1:
			vectorPerson.push_back(new Person(2));
			break;
		case 2:
		{
			//find
			char temp[50]{};
			cout << "Введите фамилию, кого удаляем: ";
			cin >> temp;
			bool flag = 1;
			auto it = vectorPerson.begin();
			for (; it != vectorPerson.end(); it++, flag = 1) {

				for (int j = 0; j < (*it)->getPole(0); j++)
				{
					//cout << "\n" << temp[j] << " " << (*it)->getData(0, j);
					if (temp[j] != (*it)->getData(0, j))
					{
						flag = 0;
					}

				}
				if (flag) {
					vectorPerson.erase(it);
					cout << "Объект удален \n";
					break;
				}
			}
			if (!flag)
			{
				cout << "нет совпадений \n";
			}
			break;
		}
		case 3:
		{
			//find
			char temp[50]{};
			cout << "Введите фамилию, кого ищем: ";
			cin >> temp;
			bool flag = 1;
			auto it = vectorPerson.begin();
			for (; it != vectorPerson.end(); it++, flag = 1) {

				for (int j = 0; j < (*it)->getPole(0); j++)
				{
					//cout << "\n" << temp[j] << " " << (*it)->getData(0, j);
					if (temp[j] != (*it)->getData(0, j))
					{
						flag = 0;
					}

				}
				if (flag) {
					(*it)->MonitorPerson();
					break;
				}
			}
			if (!flag)
			{
				cout << "нет совпадений \n";
			}
			break;
		}
		case 4:
			for (auto it = vectorPerson.begin(); it != vectorPerson.end(); it++)
			{
				(*it)->MonitorPerson();
			}
			break;
		case 5:
		{
			// запись в файл
			string path2 = "myFile2.txt";
			ofstream fout2;
			fout2.open(path2);
			if (!fout2.is_open())
				cout << "Ошибка открытия файла!\n";
			else
			{
				cout << "Запись в файл в байтовом виде\n";
				for (auto it = vectorPerson.begin(); it != vectorPerson.end(); it++)
				{
					//int temp = ((*it)->getPoleSize());
					//cout << temp << " количество полей \n";
					//fout2.write((char*)&temp, sizeof(int));	//Запись в файл в байтовом виде int	количество полей
					//cout << temp << " количество полей \n";
					int temp;
					for (int i = 0; i < (*it)->getPoleSize(); i++)
					{
						temp = (*it)->getPole(i);
						fout2.write((char*)&temp, sizeof(int));	//Запись в файл в байтовом виде int	размер полей
						for (int j = 0; j < (*it)->getPole(i); j++)
						{
							char temp1 = (*it)->getData(i, j);
							fout2.write((char*)&temp1, sizeof(char));	//Запись в файл в байтовом виде char	
							//cout << temp1 << "  ";
						}
					}
				}
				fout2.close();
			};
			//cout << "\n";
		}
		break;
		case 6:
		{
			vectorPerson.clear();
			// Чтение из файла
			string path2 = "myFile2.txt";
			ifstream fin2;
			fin2.open(path2);
			if (!fin2.is_open())
				cout << "Ошибка открытия файла!\n";
			else
			{
				while (fin2.get()) {
					//cout << "it = " << (*it) << "\n";
					int tempPole[7]{};
					char* tempData[7]{ nullptr, };
					for (int i = 0; i < 7; i++)
					{
						fin2.read((char*)&tempPole[i], sizeof(int));//Чтение из файла в байтовом виде размера int					
						tempData[i] = new char[tempPole[i]];
						for (int j = 0; j < tempPole[i]; i++)
						{
							fin2.read((char*)&tempData[i][j], sizeof(char));	//Запись в файл в байтовом виде char
						}
					}
					vectorPerson.push_back(new Person(tempData[0], tempData[1], tempData[2], tempData[3], tempData[4], tempData[5], tempData[6]));
					//cout << "\n push_back\n";
					//auto it = vectorPerson.end();
					for (int i = 0; i < 7; i++)//(*it)->getPoleSize()
					{
						delete[]tempData[i];
					}
				}
				fin2.close();
			}

		};
		break;
		case 7:
		{
			return 0;
		}
		}
	}

	return 0;
}

//Person a1;
////a1.MonitorPerson();
//a1.setZnak('E', 4, 3);
//char temp[]{ 'e', 'e', 'e', 'e', 'e', 'e', 'e' };
//a1.setPole(temp, 2, sizeof(temp));
////a1.setPersonConsole();
//a1.MonitorPerson();

//Person p1("Ivanov", "Ivan", "Ivanovich", "3-33-33", "33-33-33", "333-33-33", "Russian");
//p1.MonitorPerson();
//Person p2("Petrov", "Petr", "Petrovich", "2-22-22", "2-22-22", "2-22-22", "Ru");
//p2.MonitorPerson();
//Person p3("Sidorov", "Sidor", "Sidorovich", "1-11-11", "1-11-11", "1-11-11", "Rus");
//p3.MonitorPerson();


// //string path2 = "myFile2.txt";
//// Создаем динамические массивы
//cout << "Создаем динамические массивы\n";
//int size = 2;
//int size2 = 4;
//char* ch{ new char[size] };
//char* ch2{ new char[size2] };
//for (int i = 0; i < size; i++)
//{
//	ch[i] = 's';//заполняем
//	cout << ch[i] << "\t";
//}
//cout << "\n";
//for (int i = 0; i < size2; i++)
//{
//	ch2[i] = 'f';//заполняем
//	cout << ch[i] << "\t";
//}
//cout << "\n";

//// запись в файл
//ofstream fout2;
//fout2.open(path2);
//if (!fout2.is_open())
//	cout << "Ошибка открытия файла!\n";
//else
//{
//	cout << "Запись в файл в байтовом виде\n";
//	fout2.write((char*)&size, sizeof(int));	//Запись в файл в байтовом виде int	
//	cout << size << "\n";
//	for (int i = 0; i < size; i++)
//	{
//		fout2.write((char*)&ch[i], sizeof(char));//Запись в файл в байтовом виде char	
//		cout << ch[i] << "\t";
//	}
//	cout << "\n";

//	fout2.write((char*)&size2, sizeof(int));//Запись в файл в байтовом виде int	
//	cout << size2 << "\n";
//	for (int i = 0; i < size2; i++)
//	{
//		fout2.write((char*)&ch2[i], sizeof(char));//Запись в файл в байтовом виде char	
//		cout << ch2[i] << "\t";
//	}
//	cout << "\n";
//};
//fout2.close();

//cout << "\n";

//// Чтение из файла
//ifstream fin2;
//fin2.open(path2);
//int size3;
//int size4;
//char* ch3 = nullptr;
//char* ch4 = nullptr;
//if (!fin2.is_open())
//	cout << "Ошибка открытия файла!\n";
//else
//{
//	cout << "Чтение из файла в байтовом виде\n";
//	fin2.read((char*)&size3, sizeof(int));	//Чтение из файла в байтовом виде размера int	
//	cout << size3 << "\n";
//	ch3 = new char[size3]; //Создание
//	for (int i = 0; i < size3; i++)
//	{
//		fin2.read((char*)&ch[i], sizeof(char));//Чтение из файла в байтовом виде char	
//		cout << ch[i] << "\t";
//	}
//	cout << "\n";

//	fin2.read((char*)&size4, sizeof(int));//Чтение из файла в байтовом виде int	
//	cout << size4 << "\n";
//	ch4 = new char[size4];
//	for (int i = 0; i < size4; i++)
//	{
//		fin2.read((char*)&ch2[i], sizeof(char));//Чтение из файла в байтовом виде char	
//		cout << ch2[i] << "\t";
//	}
//	cout << "\n";

//	fin2.close();
//}
////Освобождаем память
//delete[]ch;
//delete[]ch2;
//delete[]ch3;
//delete[]ch4;
