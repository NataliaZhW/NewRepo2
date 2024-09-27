/*
сохранять информацию в файл и загружать из файла.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string path2 = "myFile2.txt";

	int length = 0;
	int length2 = 3;
	int length3;
	int length4;

	char ch[10]{ 'a','2','3','4','5','6','7','8','9','n' };
	char ch2[10]{};

	// запись в файл
	ofstream fout2;
	fout2.open(path2);
	if (!fout2.is_open())
		cout << "Ошибка открытия файла!\n";
	else
	{
		fout2.write((char*)&length, sizeof(int));	//Запись в файл в байтовом виде int	
		cout << length << "\n";
		fout2.write((char*)&length2, sizeof(int));
		cout << length2 << "\n";
		for (size_t i = 0; i < 10; i++)
		{
			fout2.write((char*)&ch[i], sizeof(char));//Запись в файл в байтовом виде char	
			cout << ch[i] << "\t";
		}
		cout << "\n";
	};
	fout2.close();

	cout << "\n";

	// Чтение из файла
	ifstream fin2;
	fin2.open(path2);
	if (!fin2.is_open())
		cout << "Ошибка открытия файла!\n";
	else
	{
		fin2.read((char*)&length3, sizeof(int));// Чтение из файла в байтовом виде int
		cout << length3 << "\n";
		fin2.read((char*)&length4, sizeof(int));
		cout << length4 << "\n";
		for (size_t i = 0; i < 10; i++)
		{
			fin2.read((char*)&ch2[i], sizeof(char));// Чтение из файла в байтовом виде char
			cout << ch2[i] << "\t";
		}
		cout << "\n";
	};
	fin2.close();

	std::cout << "Hello World!\n";
	return 0;

}