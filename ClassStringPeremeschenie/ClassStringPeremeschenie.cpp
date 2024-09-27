#include <iostream>
class DynArray
{
	int* arr;
	int size;
public:
	DynArray(int sizeP)
		: arr{ new int[sizeP] {} }, size{ sizeP }
	{
		std::cout << "DynArr constructed for " << size
			<< " elements, for " << this << '\n';
	}
	DynArray() : DynArray(5) {}
	DynArray(const DynArray& object)
		: arr{ new int[object.size] }, size{ object.size }
	{
		/* В списке инициализаторов полей класса выше,
		выделяем новый блок динамической памяти того же
		размера, что и в копируемом экземпляре класса
		DynArray. Следующим циклом копируем элементы
		из оригинального блока памяти во вновь
		выделенный. */
		for (int i{ 0 }; i < size; ++i)
		{
			arr[i] = object.arr[i];
		}
		std::cout << "DynArr copy constructed for "
			<< size << " elements, for " << this
			<< '\n';
	}

	DynArray(DynArray&& object)
		: arr{ object.arr }, size{ object.size }
		/* копируем указатель на выделенный в исходном объекте блок динамической памяти и размер этого блока в инициализируемый конструктором объект */
	{
		/*	"отбираем" у исходного объекта право владения блоком
			динамической памяти и устанавливаем размер блока в 0 */
		object.arr = nullptr;
		object.size = 0;
		std::cout << "DynArr move constructed for "
			<< size << " elements, for " << this
			<< '\n';
	}
	DynArray& operator=(const DynArray& object)
	{
		// проверка на самоприсваивание
		if (!(this == &object))
		{
			/*	проверяем на невозможность "переиспользовать" блок
				памяти, выделеный под имеющийся массив */
			if (size != object.size)
			{
				/* в случае невозможности "переиспользования"
				необходимо освободить память, УЖЕ занимаимую
				элементами текущего динамического массива */
				delete[] arr;
				/*	выделяем новый блок памяти согласно
					размера копируемого массива */
				arr = new int[object.size];
			}
			size = object.size;

			/*	альтернативный способ копирования массива
				более эффективный с точки зрения времени выполнения
				ценой трех дополнительных указателей */
				//	указатель на начало массива-назначения копирования
			int* dest{ arr };
			//	указатель на начало массива-источника копирования
			int* src{ object.arr };
			/*	константный указатель на следующий за последним
				элементом в массиве-назначени - "конец массива источника" */
			int* const end{ arr + size };

			//	пока указатель "назначения" не превышает "конец"...
			while (dest < end)
			{
				/*	кладем по адресу указателя dest значение,
					хранимое по адресу src затем инкрементируем оба указателя */
				*dest++ = *src++;
			}
			// массив из obj.arr скопирован в arr.
		}

		std::cout << "DynArr copy assigned for "
			<< size << " elements, for " << this
			<< '\n';

		return *this;
	}
	int getElem(int idx)const { return arr[idx]; }
	void setElem(int idx, int val) { arr[idx] = val; }
	void print()const;
	void randomize();
	~DynArray()
	{
		std::cout << "Try to free memory from DynArray for"
			<< arr << " pointer\n";
		delete[] arr;
		std::cout << "DynArr destructed for " << size
			<< " elements, for " << this << '\n';
	}
};
void DynArray::print()const
{
	for (int i{ 0 }; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}
void DynArray::randomize()
{
	for (int i{ 0 }; i < size; ++i)
	{
		arr[i] = rand() % 10;
	}
}

DynArray arrayFactory(int arrSize)
{
	DynArray arr{ arrSize };
	arr.randomize();
	return arr;
}

int main()
{
	DynArray ar1{ arrayFactory(10) };
	std::cout << "ar1 elements: ";
	ar1.print();

	return 0;
}