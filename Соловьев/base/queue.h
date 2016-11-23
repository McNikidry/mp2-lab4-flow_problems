#ifndef __QUEUE_H__
#define __QUEUE_H__

const int MAX_SIZE_QUEUE = 10000; 
const int MORE_MAX_SIZE_QUEUE = 100000;// дополнительный размер для перевыделения памяти


template <class ValType>
class TQueue
{
	int  size; // текущий размер памяти
	ValType *pMem;
	int start;// индекс на первый элемент очереди
	int end; // индекс на последний элемент очереди
	int count; //  количетво элементов
public:
	TQueue(int size);
	~TQueue();
	bool IsEmpty();
	bool IsFull();
	int GetSize()
	{
		return size;
	}
	int GetCount()
	{
		return count;
	}
	ValType Pop();
	ValType Top();
	void Push(ValType elem);
	void NewAllocation();
};

template <class ValType>
TQueue<ValType>::TQueue(int len)
{
	if (len < 1) throw("negative queue length");
	size = len;
	if (size > MAX_SIZE_QUEUE) throw("Too much memory required for the queue");
	count = 0;
		pMem = new ValType[size + 1]; // для кольцевания +1
		start = 0; //указывает на начало
		end = 0;//указывает на конец
}

template <class ValType>
TQueue<ValType>::~TQueue()
{
	delete[] pMem;
}

template <class ValType>
bool TQueue<ValType>::IsEmpty()
{
	return (count == 0);
}
template <class ValType>
bool TQueue<ValType>::IsFull()
{
	return(count == size);
}
template <class ValType>
ValType TQueue<ValType>::Pop()
{
	if (IsEmpty()) throw("The queue is empty");
	count--;
	int  tmp=start;
	start++;
	if (start > size)
		start = start - size + 1;//возращаем start в начало очереди
	return pMem[tmp];
}

template <class ValType>
ValType TQueue<ValType>::Top()
{
	if (IsEmpty()) throw("The queue is empty");
	return pMem[start];
}
template <class ValType>
void TQueue<ValType>::Push(ValType elem)
{
	// если полон, делаем перевыделение памяти
	if (IsFull())
	{
		NewAllocation();
	}
	count++;
	pMem[end++] = elem;

	if (end > size)
		end = end - size + 1;//возвращаем end в начало очереди

}
template <class ValType>
void TQueue<ValType>::NewAllocation() // добавление еще памяти, если закончилась данная MAX_SIZE
{
	int len = size;//запоминаем размер для копирования старой очереди в новую
	size += 1000; // добавляем каждый раз по 1000
	if (size > MORE_MAX_SIZE_QUEUE) throw("Not enough memory");
	int i;
	ValType *tmp;
	tmp = new ValType[len + 1];
	 for ( i = 0; i < len + 1; i++)
		tmp[i] = pMem[i];
	delete[] pMem;
	pMem = new ValType[size];
	 for (i = 0; i < len + 1; i++)
		pMem[i] = tmp[i];
	delete[] tmp;
}

#endif