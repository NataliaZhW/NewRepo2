/*
сохранять динамический массив в файл и загружать из файла.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string path2 = "myFile2.txt";

	// Создаем динамические массивы
	cout << "Создаем динамические массивы\n";
	int size = 2;
	int size2 = 4;
	char* ch{ new char[size] };
	char* ch2{ new char[size2] };
	for (int i = 0; i < size; i++)
	{
		ch[i] = 's';//заполняем
		cout << ch[i] << "\t";
	}
	cout << "\n";
	for (int i = 0; i < size2; i++)
	{
		ch2[i] = 'f';//заполняем
		cout << ch[i] << "\t";
	}
	cout << "\n";

	// запись в файл
	ofstream fout2;
	fout2.open(path2);
	if (!fout2.is_open())
		cout << "Ошибка открытия файла!\n";
	else
	{
		cout << "Запись в файл в байтовом виде\n";
		fout2.write((char*)&size, sizeof(int));	//Запись в файл в байтовом виде int	
		cout << size << "\n";
		for (int i = 0; i < size; i++)
		{
			fout2.write((char*)&ch[i], sizeof(char));//Запись в файл в байтовом виде char	
			cout << ch[i] << "\t";
		}
		cout << "\n";

		fout2.write((char*)&size2, sizeof(int));//Запись в файл в байтовом виде int	
		cout << size2 << "\n";
		for (int i = 0; i < size2; i++)
		{
			fout2.write((char*)&ch2[i], sizeof(char));//Запись в файл в байтовом виде char	
			cout << ch2[i] << "\t";
		}
		cout << "\n";
	};
	fout2.close();

	cout << "\n";

	// Чтение из файла
	ifstream fin2;
	fin2.open(path2);
	int size3;
	int size4;
	char* ch3 = nullptr;
	char* ch4 = nullptr;
	if (!fin2.is_open())
		cout << "Ошибка открытия файла!\n";
	else
	{
		cout << "Чтение из файла в байтовом виде\n";
		fin2.read((char*)&size3, sizeof(int));	//Чтение из файла в байтовом виде размера int	
		cout << size3 << "\n";
		ch3 = new char[size3]; //Создание
		for (int i = 0; i < size3; i++)
		{
			fin2.read((char*)&ch[i], sizeof(char));//Чтение из файла в байтовом виде char	
			cout << ch[i] << "\t";
		}
		cout << "\n";

		fin2.read((char*)&size4, sizeof(int));//Чтение из файла в байтовом виде int	
		cout << size4 << "\n";
		ch4 = new char[size4];
		for (int i = 0; i < size4; i++)
		{
			fin2.read((char*)&ch2[i], sizeof(char));//Чтение из файла в байтовом виде char	
			cout << ch2[i] << "\t";
		}
		cout << "\n";

		fin2.close();
	}
	//Освобождаем память
	delete[]ch;
	delete[]ch2;
	delete[]ch3;
	delete[]ch4;
	return 0;

}