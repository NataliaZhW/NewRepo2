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
	char* Wait;//Динамический массив
	int MaxQueueLenght;//Размер
	int QueueLenght;//Заполненность
	
public:
	Stack(int m);
	~Stack();

	void Push(char c);//Добавить элемент
	char Pop();//Текущий элемент, верхний обработать
	bool IsEmpty();//Пустой?
	bool IsFull();//Полный?
	int getCount(); //Количество элементов в стеке сейчас
	void Clear();//Очистить
	char Pop_verh();//Текущий элемент, верхний только посмотреть
	int getSize(); //Размер массива
	void printVerh();
};
Stack::Stack(int m) {
	MaxQueueLenght = m;
	QueueLenght = 0;
	Wait = new char[MaxQueueLenght];	
}
Stack::~Stack() { delete[]Wait; }
void Stack::Clear() { QueueLenght = 0; }
bool Stack::IsEmpty() { return QueueLenght == 0; }
bool Stack::IsFull() { return QueueLenght == MaxQueueLenght; }
int Stack::getCount() { return QueueLenght; }

void Stack::Push(char c) {
	if (!IsFull()) {
		Wait[QueueLenght++] = c;
		cout << Wait[QueueLenght - 1] << " ";
	}
	else {
		char* temp;
		temp = new char[MaxQueueLenght + 1];
		for (int i = 0; i < MaxQueueLenght + 1; i++)
		{
			temp[i] = Wait[i];//Сохраняем во временный массив
		}

		delete[]Wait;
		Wait = new char[MaxQueueLenght + 1];

		for (int i = 0; i < MaxQueueLenght ; i++)
		{
			Wait[i] = temp[i];//читаем из временного массива
		}
		this->MaxQueueLenght++; //Размер больше
		delete[]temp;
		Wait[QueueLenght++] = c; //добавляем элемент
		cout << Wait[QueueLenght - 1] << " ";
		}
}
char Stack::Pop() {
	if (!IsEmpty()) { return Wait[--QueueLenght]; }
	else return 0;
}
char Stack::Pop_verh() {
	if (!IsEmpty()) { return Wait[QueueLenght-1]; }
	else return 0;
}

int Stack::getSize() { return MaxQueueLenght; }

void Stack::printVerh()
{
	if (!IsEmpty())
	{
		cout << "\n" << Pop_verh() << " Последний элемент посмотрели" << endl;
	}
	else
		cout << "Нет элементов\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));
	int n = 2;
	cout << "Введите количество элементов ";
	cin >> n;
	Stack ST(n);//Объявление стека
	cout << ST.getSize() << " сколько всего" << endl;
	cout << ST.getCount() << " сколько заполнено" << endl;
	char c;
	cout << "\nзаполнение стека\n";
	while (!ST.IsFull()) {//заполнение стека
		c = rand() % 4 + 2;
		ST.Push(c);
	}
	ST.Push('4');
	ST.Push('1');
	ST.Push('4');
	ST.Push('5');
	cout << endl;
	cout << ST.getSize() << " сколько всего" << endl;
	cout << ST.getCount() << " сколько заполнено" << endl;
	
	cout << "\nОбработка стека последовательно\n";
	while (c = ST.Pop()) {//обработать элементы, вывод на экран
		cout << " " << ST.getCount() << "й:" << c << " ";
	}
	cout << endl;
	cout << ST.getSize() << " сколько всего" << endl;
	cout << ST.getCount() << " сколько заполнено" << endl;
	
	cout << "\nзаполнение стека\n";
	ST.Push('8');//Пополняем стек
	ST.Push('4');
	ST.Push('1');
	ST.Push('4');
	ST.Push('k');
	cout << endl;

	cout << ST.getSize() << " сколько всего" << endl;
	cout << ST.getCount() << " сколько заполнено" ;
	ST.printVerh();

	cout << "\nочитска стека\n";
	ST.Clear();
	cout << ST.getSize() << " сколько всего" << endl;
	cout << ST.getCount() << " сколько заполнено" << endl;	
	cout << endl;
	ST.printVerh();
	return 0;
}