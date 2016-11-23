#ifndef __QUEUE_H__
#define __QUEUE_H__

const int MAX_SIZE_QUEUE = 10000; 
const int MORE_MAX_SIZE_QUEUE = 100000;// �������������� ������ ��� ������������� ������


template <class ValType>
class TQueue
{
	int  size; // ������� ������ ������
	ValType *pMem;
	int start;// ������ �� ������ ������� �������
	int end; // ������ �� ��������� ������� �������
	int count; //  ��������� ���������
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
		pMem = new ValType[size + 1]; // ��� ����������� +1
		start = 0; //��������� �� ������
		end = 0;//��������� �� �����
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
		start = start - size + 1;//��������� start � ������ �������
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
	// ���� �����, ������ ������������� ������
	if (IsFull())
	{
		NewAllocation();
	}
	count++;
	pMem[end++] = elem;

	if (end > size)
		end = end - size + 1;//���������� end � ������ �������

}
template <class ValType>
void TQueue<ValType>::NewAllocation() // ���������� ��� ������, ���� ����������� ������ MAX_SIZE
{
	int i;
		ValType *tmp;
		tmp = new ValType[size + 1];
		int len = size;//���������� ������ ��� ����������� ������ ������� � �����.
		for ( i = 0; i < size + 1; i++)
			tmp[i] = pMem[i];
		delete[] pMem;
		size += 1000; // ��������� ������ ��� �� 1000
		if (size > MORE_MAX_SIZE_QUEUE) throw("Not enough memory");
		pMem = new ValType[size];
		for (i = 0; i < len + 1; i++)
			pMem[i] = tmp[i];
		delete[] tmp;
}

#endif