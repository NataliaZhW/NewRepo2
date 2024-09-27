/* Курс: Объектно - ориентированное
программирование на C++
Встреча №14
Тема : динамические сТрукТуры данных –
очередь, очередь с приориТеТами
Задания для самостоятельной работы :
Задание №1
Создайте шаблонный класс обычной очереди для работы с целыми значениями.Требуется создать реализации для типичных
операций над элементами :
■ IsEmpty – проверка очереди на пустоту
■ IsFull – проверка очереди на заполнение
■ Enqueue – добавление элемента в очередь
■ Dequeue – удаление элемента из очереди
■ Show – отображение всех элементов очереди на экран
*/

#include <iostream>
using namespace std;

template <class T>
class Queue
{
private:

	T* Wait;
	int MaxQueueLenght;
	int QueueLenght;
public:
	Queue(int m);
	~Queue();
	void EnQueue(T c);
	T DeQueue();
	bool IsEmpty();
	bool IsFull();
	int getCount();
	void Shou();
};

template <class T>
Queue<T>::Queue(int m)
{
	MaxQueueLenght = m;
	QueueLenght = 0;
	Wait = new T[MaxQueueLenght];
}

template <class T>
Queue<T>::~Queue() { delete[]Wait; }

template<class T>
void Queue<T>::EnQueue(T c) { 
	if (!IsFull()) { Wait[QueueLenght++] = c; } 
	else {
		T* temp;
		temp = new T[MaxQueueLenght + 1];
		for (int i = 0; i < MaxQueueLenght + 1; i++)
		{
			temp[i] = Wait[i];
		}
		delete[]Wait;
		Wait = new T[MaxQueueLenght + 1];
		
		for (int i = 0; i < MaxQueueLenght +1; i++)
		{
			Wait[i]=temp[i] ;
		}
		this->MaxQueueLenght++; //Размер больше
		cout << "\n";

		delete[]temp;
		Wait[QueueLenght++] = c;
	}

}

template<class T>
T Queue<T>::DeQueue() {
	if (!IsFull()) {
		T temp = Wait[0];
		for (int i = 1; i < QueueLenght; i++) {
			Wait[i - 1] = Wait[i];
		}
		QueueLenght--;
		return temp;
	}
	else return -1;
}

template<class T>
bool Queue<T>::IsEmpty() { return QueueLenght == 0; }

template<class T>
bool Queue<T>::IsFull() { return QueueLenght == MaxQueueLenght; }

template<class T>
int Queue<T>::getCount() { return QueueLenght; }

template<class T>
void Queue<T>::Shou()
{
	cout << "\n" << "-----------" << "\n";
	for (int i = 0; i < QueueLenght; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n" << "-----------" << "\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите количество элементов ";
	cin >> n;
	Queue<int> QU(n);
	for (int i = 0; i < n; i++) {
		QU.EnQueue(rand() % (2 * n));

	}
	QU.Shou();
QU.EnQueue(5);
QU.Shou();

	cout << "Hello World!\n";
}
