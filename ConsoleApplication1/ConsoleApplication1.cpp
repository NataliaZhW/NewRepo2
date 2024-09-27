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

	int pole[7]{ 1,1,1,1,1,1,1 };

	char* data[7]{ // 7  полей
		new char[pole[0]] {'1'},
		new char[pole[1]] {'2'},
		new char[pole[2]] {'3'},
		new char[pole[3]] {'4'},
		new char[pole[4]] {'5'},
		new char[pole[5]] {'6'},
		new char[pole[6]] {'7'}
	};

public:
	Person()
	{
		char temp[1]{ ' ' };
		for (int i = 0; i < poleSize; i++)
		{
			setPole(temp, i, mySizeof(temp));
		}
		//cout << "\nЗапустился конcтруктор по умолчанию " << this << "\n";
	};
	Person(int a)
	{
		char temp[1]{ ' ' };
		for (int i = 0; i < poleSize; i++)
		{
			setPole(temp, i, sizeof(temp));
		}
		setPersonConsole();
		//cout << "\nЗапустился конcтруктор заполнения " << this << "\n";
	};
	Person(int s0, char* surname, int s1, char* name, int s2, char* name2, int s3, char* home_tel,
		int s4, char* work_tel, int s5, char* mob_tel, int s6, char* other)
	{
		//cout << "\nКонструктор чтения из файла " << this << " \n";
		setPole(surname, 0, s0);
		setPole(name, 1, s1);
		setPole(name2, 2, s2);
		setPole(home_tel, 3, s3);
		setPole(mob_tel, 4, s4);
		setPole(work_tel, 5, s5);
		setPole(other, 6, s6);
	};
	Person(const char* surname, const char* name, const char* name2, const char* home_tel, const char* work_tel,
		const char* mob_tel, const char* other)
	{
		//cout << "\nКонструктор со значениями " << this << " \n";

		setPole(surname, 0, mySizeof(surname));
		setPole(name, 1, mySizeof(name));
		setPole(name2, 2, mySizeof(name2));
		setPole(home_tel, 3, mySizeof(home_tel));
		setPole(mob_tel, 4, mySizeof(mob_tel));
		setPole(work_tel, 5, mySizeof(work_tel));
		setPole(other, 6, mySizeof(other));
	};
	~Person()
	{
		//cout << "\nЗапустился деструктор " << this << "\n";
		for (int i = 0; i < poleSize; i++)
		{
			delete[]data[i];
		}
		//cout << "конец деструктора " << "\n";
	};


	int getPoleSize()//количество полей
	{
		return poleSize;
	}
	int getPole(int i)// массива поля
	{
		return pole[i];
	}
	char getData(int i, int j) //ячейка массива
	{
		return data[i][j];
	}
	string textZaprosa(int i)
	{
		switch (i + 1)
		{
		case 1:
			return "фамилия:          ";
			break;
		case 2:
			return "имя:              ";
			break;
		case 3:
			return "отчество:         ";
			break;
		case 4:
			return "домашний телефон: ";
			break;
		case 5:
			return "рабочий телефон:  ";
			break;
		case 6:
			return "мобильный телефон:";
			break;
		case 7:
			return "другое            ";
			break;
		default:
			break;
		};
	}
	int mySizeof(const char* text)
	{
		int tempSize1 = 0;
		for (tempSize1 = 0; tempSize1 < sizeof(text); tempSize1++)
		{
			if (text[tempSize1] == '\0')
				break;
		}
		return tempSize1;
	}

	void MonitorPerson()
	{
		//cout << "\nВывод объекта класса " << this << "\n";
		for (int i = 0; i < poleSize; i++)
		{
			MonitorPole(i);
		}
		cout << "\n";
	}

	void MonitorPole(int i)
	{
		//cout << "\nВывод поля объекта " << this << "\n";
		cout << textZaprosa(i) << " ";
		for (size_t j = 0; j < pole[i]; j++)
		{
			cout << data[i][j] << "";
		}
		//cout << "   размер " << pole[i];
		cout << "\n";
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
		if (pole[i] != sizeTemp)
		{
			pole[i] = sizeTemp;
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
	string path1 = "myFile1.txt";
	string path2 = "myFile2.txt";

	vector<Person*> vectorPerson; // пустой список 

	//Чтение из файла в байтовом виде int размер листа
	size_t tempSizeList;
	ifstream fin1;
	fin1.open(path1);
	if (!fin1.is_open())
		cout << "Ошибка открытия файла!\n";
	else
	{
		fin1.read((char*)&tempSizeList, sizeof(size_t));
		//cout << "Размер листа " << tempSizeList << "\n";
		fin1.close();
	};
	// Чтение из файла
	ifstream fin2;
	fin2.open(path2);
	if (!fin2.is_open())
		cout << "Ошибка открытия файла!\n";
	else
	{
		int tempPole[7]{};
		for (size_t its = 0; its < tempSizeList; its++)
		{
			char* tempData[7]{ nullptr, };
			for (int i = 0; i < 7; i++)
			{
				fin2.read((char*)&tempPole[i], sizeof(int));//Чтение из файла в байтовом виде размера int					
				//cout << "\n" << tempPole[i] << " размер поля " << i << "  ";
				tempData[i] = new char[tempPole[i]];
				for (int j = 0; j < tempPole[i]; j++)
				{
					fin2.read((char*)&tempData[i][j], sizeof(char));	//Чтение из файла в байтовом виде char
					//cout << tempData[i][j];
				}
			}

			vectorPerson.push_back(new Person(tempPole[0], tempData[0], tempPole[1], tempData[1],
				tempPole[2], tempData[2], tempPole[3], tempData[3], tempPole[4], tempData[4],
				tempPole[5], tempData[5], tempPole[6], tempData[6]));

			for (int i = 0; i < 7; i++)
			{
				delete[]tempData[i];
			}
		}
		fin2.close();
	}

	//vectorPerson.push_back(new Person("Ivanov", "Ivan", "Ivanovich", "3-33-33", "33-33-33", "333-33-33", "Russian"));
	//vectorPerson.push_back(new Person("Petrov", "Petr", "Petrovich", "2-22-22", "2-22-22", "2-22-22", "Ru"));
	//vectorPerson.push_back(new Person("Sidorov", "Sidor", "Sidorovich", "1-11-11", "1-11-11", "1-11-11", "Rus"));
	//vectorPerson.push_back(new Person("Sid", "Sidor", "Sidorovich", "1-11-11", "1-11-11", "1-11-11", "Rus"));

	////Запись в файл в байтовом виде int размер листа
	//ofstream fout1;
	//fout1.open(path1);
	//if (!fout1.is_open())
	//	cout << "Ошибка открытия файла!\n";
	//else
	//{
	//	cout << "Запись в файл в байтовом виде\n";
	//	size_t temp = vectorPerson.size();
	//	cout << "Размер листа" << temp << "\n";
	//	fout1.write((char*)&temp, sizeof(size_t));
	//	fout1.close();
	//};

	//ofstream fout2;
	//fout2.open(path2);
	//if (!fout2.is_open())
	//	cout << "Ошибка открытия файла!\n";
	//else
	//{
	//	cout << "Запись в файл в байтовом виде\n";
	//	for (auto it = vectorPerson.begin(); it != vectorPerson.end(); it++)
	//	{
	//		int temp;
	//		for (int i = 0; i < (*it)->getPoleSize(); i++)
	//		{
	//			temp = (*it)->getPole(i);
	//			fout2.write((char*)&temp, sizeof(int));	//Запись в файл в байтовом виде int	размер полей
	//			cout << "\n" << temp << " ";
	//			for (int j = 0; j < (*it)->getPole(i); j++)
	//			{
	//				char temp1 = (*it)->getData(i, j);
	//				fout2.write((char*)&temp1, sizeof(char));	//Запись в файл в байтовом виде char	
	//				cout << temp1 << "";
	//			}
	//		}
	//		cout << "\n";
	//	}
	//	fout2.close();
	//};

	int event = 0; // диалог с пользователем
	while (1) {
		cout << "\n\nЧто будем делать: \n";
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
			cout << "\n";
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
			char temp[50]{};
			cout << "Введите фамилию, кого удаляем: ";
			cin >> temp;
			bool flag = 1;
			bool flag1 = 0;
			auto it = vectorPerson.begin();
			for (; it != vectorPerson.end(); it++, flag = 1) {

				for (int j = 0; j < (*it)->getPole(0); j++)
				{
					if (temp[j] != (*it)->getData(0, j))
					{
						flag = 0;
					}

				}
				if (flag) {
					vectorPerson.erase(it);
					cout << "Объект удален \n";
					flag1 = 1;
					break;
				}
			}
			if (!flag1)
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
			bool flag1 = 0;
			auto it = vectorPerson.begin();
			for (; it != vectorPerson.end(); it++, flag = 1) {

				for (int j = 0; j < (*it)->getPole(0); j++)
				{
					if (temp[j] != (*it)->getData(0, j))
					{
						flag = 0;
					}
				}
				if (flag) {
					cout << "совпадение найдено \n";
					(*it)->MonitorPerson();
					flag1 = 1;
					break;
				}
			}
			if (!flag1)
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
			ofstream fout2;
			fout2.open(path2);
			if (!fout2.is_open())
				cout << "Ошибка открытия файла!\n";
			else
			{
				cout << "Запись в файл в байтовом виде\n";
				for (auto it = vectorPerson.begin(); it != vectorPerson.end(); it++)
				{
					int temp;
					for (int i = 0; i < (*it)->getPoleSize(); i++)
					{
						temp = (*it)->getPole(i);
						fout2.write((char*)&temp, sizeof(int));	//Запись в файл в байтовом виде int	размер полей
						//cout << "\n" << temp << " ";
						for (int j = 0; j < (*it)->getPole(i); j++)
						{
							char temp1 = (*it)->getData(i, j);
							fout2.write((char*)&temp1, sizeof(char));	//Запись в файл в байтовом виде char	
							//cout << temp1 << "";
						}
					}
					//cout << "\n";
				}
				fout2.close();
			};
			//cout << "\n";
		}
		break;
		case 6:
		{
			vectorPerson.clear();
			//Чтение из файла в байтовом виде int размер листа
			size_t tempSizeList;
			ifstream fin1;
			fin1.open(path1);
			if (!fin1.is_open())
				cout << "Ошибка открытия файла!\n";
			else
			{
				fin1.read((char*)&tempSizeList, sizeof(size_t));
				//cout << "Размер листа " << tempSizeList << "\n";
				fin1.close();
			};
			// Чтение из файла
			string path2 = "myFile2.txt";
			ifstream fin2;
			fin2.open(path2);
			if (!fin2.is_open())
				cout << "Ошибка открытия файла!\n";
			else
			{
				int tempPole[7]{};
				for (size_t its = 0; its < 7; its++)
				{
					char* tempData[7]{ nullptr, };
					for (int i = 0; i < 7; i++)
					{
						fin2.read((char*)&tempPole[i], sizeof(int));//Чтение из файла в байтовом виде размера int					
						//cout << "\n" << tempPole[i] << " размер поля " << i << "  ";
						tempData[i] = new char[tempPole[i]];
						for (int j = 0; j < tempPole[i]; j++)
						{
							fin2.read((char*)&tempData[i][j], sizeof(char));	//Чтение из файла в байтовом виде char
							//cout << tempData[i][j];
						}
					}

					vectorPerson.push_back(new Person(tempPole[0], tempData[0], tempPole[1], tempData[1],
						tempPole[2], tempData[2], tempPole[3], tempData[3], tempPole[4], tempData[4],
						tempPole[5], tempData[5], tempPole[6], tempData[6]));

					for (int i = 0; i < 7; i++)
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