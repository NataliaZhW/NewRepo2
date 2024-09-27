/*Курс
«Объектно-ориентированное
программирование на C++»
Встреча №13
Тема: динамические сТрукТуры данных – сТек
Задания для самостоятельной работы:
Задание №1
Реализуйте класс стека для работы с символами (символьный
стек). Стек должен иметь фиксированный размер. Также реализуйте
набор операций для работы со стеком: помещение символа в стек,
выталкивание символа из стека, подсчет количества
символов в стеке, проверку пустой ли стек, проверку полный ли
стек, очистку стека, получение без выталкивания верхнего символа в стеке.

*/

#include <iostream>

using namespace std;

class Stack {
private:
	enum { EMPTY = -1, FULL = 20 };// константы
	char st[FULL + 1];
	int top;
public:
	Stack();
	void Push(char c);//Добавить 
	char Pop();//Текущий элемент, верхний обработать
	int GetCount(); //Количество элементов в стеке сейчас
	void Clear();//Очистить
	bool IsEmpty();//Пустой?
	bool IsFull();//Полный?
	char Pop_verh();//Текущий элемент, верхний только посмотреть
};
Stack::Stack() { top = EMPTY; }
void Stack::Clear() { top = EMPTY; }
bool Stack::IsEmpty() { return top == EMPTY; }
bool Stack::IsFull() { return top == FULL; }
int Stack::GetCount() { return top + 1; }
void Stack::Push(char c) { if (!IsFull()) { st[++top] = c; } }
char Stack::Pop() {
	if (!IsEmpty()) { return st[top--]; }
	else return 0;
}
char Stack::Pop_verh() {
	if (!IsEmpty()) { return st[top]; }
	else return 0;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));
	Stack ST;//Объявление стека
	char c;
	while (!ST.IsFull()) {//заполнение стека
		c = rand() % 4 + 2;
		//cout << c << " ";
		ST.Push(c);
	}
	cout << endl;
	while (c = ST.Pop()) {//вывод на экран
		cout << c << " ";
	}
	cout << endl;

	ST.Push('a');//Пополняем стек
	ST.Push('b');
	ST.Push('c');

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
