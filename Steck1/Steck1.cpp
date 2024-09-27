/*Курс
«Объектно-ориентированное
программирование на C++»
Встреча №13
Тема: динамические сТрукТуры данных – сТек
Задания для самостоятельной работы:
Задание №2
Измените стек из первого задания со статического типа на
динамический (при нехватке свободного места нужно изменить
размер внутреннего массива без потери данных).
*/

#include <iostream>
using namespace std;

class Stack {
private:
	char* st;//Динамический массив
	int size; //Размер
	int top = -1; //Заполненность
public:
	Stack(int size);
	~Stack();

	void Push(char c);//Добавить элемент
	char Pop();//Текущий элемент, верхний обработать
	int getCount(); //Количество элементов в стеке сейчас
	//void upCount();// увеличение массива
	void Clear();//Очистить
	bool IsEmpty();//Пустой?
	bool IsFull();//Полный?
	char Pop_verh();//Текущий элемент, верхний только посмотреть
	int getSize(); //Размер массива
};
Stack::Stack(int size) {
	this->size = size; //FULL
	st = new char[size];
	top = 0;//EMPTY	
	/*cout << "\nадрес массива " << &(this->st) << "\n";
	cout << "\nадрес массива " << (int)*(this->st) << "\n";*/
}
Stack::~Stack() {
	delete[]st;
	//cout << "\nадрес массива " << &(this->st) << "\n";
	//cout << "\nадрес массива " << (int)*(this->st) << "\n";
	////delete[]st;
	//cout << "\nадрес массива " << &(this->st) << "\n";
	//cout << "\nадрес массива " << (int)*(this->st) << "\n";
}
void Stack::Clear() { top = -1; }
bool Stack::IsEmpty() { return top == -1; }
bool Stack::IsFull() { return top == size; }
int Stack::getCount() { return top; }
//void Stack::upCount() {
//	
//}

void Stack::Push(char c) {
	if (!IsFull()) {
		//upCount();
		st[++top] = c;
		cout << " " << top << ":" << c << ":" << st[top] << " ";
	}
	else {
		char* temp;
		temp = new char[size + 1];
		for (int i = 0; i < size + 1; i++)
		{
			temp[i] = st[i];
		}
		delete[]st;
		st = new char[size + 1];

		for (int i = 0; i < size + 1; i++)
		{
			st[i] = temp[i];
			cout << " " << i << ":" << temp[i] << " ";//в обратном порядке

		}
		this->size++; //Размер больше
		cout << "\n";
		cout << " " << top << ":" << c << ":" << st[top] << " ";

		delete[]temp;
		st[size++] = c;
		/*cout << "\nадрес массива " << &(this->st) << "\n";
		cout << "\nадрес массива " << (int)*(this->st) << "\n";*/
		//cout << "\nв обратном порядке ";

			//cout << " " << i << ":" << temp[i] << " ";//в обратном порядке

		/*cout << "\nв нужном порядке ";
		cout << "\nадрес массива " << &(this->st) << "\n";
		cout << "\nадрес массива " << (int)*(this->st) << "\n";*/

		/*cout << "\nадрес массива " << &(this->st) << "\n";
		cout << "\nадрес массива " << (int)*(this->st) << "\n";*/

		//cout << Pop_verh() << " " << i << "эл" " ";//в нужном порядке



	}
}
char Stack::Pop() {
	if (!IsEmpty()) { return st[top--]; }
	else return 0;
}
char Stack::Pop_verh() {
	if (!IsEmpty()) { return st[top]; }
	else return 0;
}

int Stack::getSize() { return size; }

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));
	int n = 2;
	//cout << "Введите количество элементов ";
	//cin >> n;
	Stack ST(n);//Объявление стека
	char c;
	//while (!ST.IsFull()) {//заполнение стека
	//	c = rand() % 4 + 2;
	//	cout << " " << ST.getCount() << ":" << c << " ";
	//	ST.Push(c);
	//	cout << " " << ST.getCount() << ":" << ST.Pop_verh() << " ";
	//}
	ST.Push('4');
	cout << " " << ST.getCount() << ":" << ST.Pop_verh() << " ";
	ST.Push('1');
	cout << " " << ST.getCount() << ":" << ST.Pop_verh() << " ";
	ST.Push('4');
	cout << " " << ST.getCount() << ":" << ST.Pop_verh() << " ";
	ST.Push('5');
	cout << " " << ST.getCount() << ":" << ST.Pop_verh() << " ";
	cout << endl;
	while (c = ST.Pop()) {//обработать элементы, вывод на экран
		cout << " " << ST.getCount() << ":" << c << " ";
		//cout << c << " ";
	}
	cout << endl;
	cout << ST.getSize() << " сколько всего" << endl;

	cout << ST.getCount() << " сколько заполнено" << endl;
	ST.Push('8');//Пополняем стек
	ST.Push('4');
	ST.Push('1');
	ST.Push('4');
	ST.Push('5');

	if (!ST.IsEmpty())
	{
		cout << ST.Pop_verh() << " Последний элемент посмотрели" << endl;
	}
	else
		cout << "Нет элементов\n";
	while (c = ST.Pop()) {
		cout << c << " ";
	}
	cout << endl;
	if (!ST.IsEmpty())
	{
		cout << ST.Pop_verh() << " Последний элемент посмотрели" << endl;
	}
	else
		cout << "Нет элементов\n";

	return 0;
}