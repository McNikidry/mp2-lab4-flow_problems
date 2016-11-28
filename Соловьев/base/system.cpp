#include"queue.h"
#include"system.h"
#include <ctime>// библиотека для вычисления времени выполенния одной задачи

Task::Task(size_t t, double a, double b)
{
	if (t < 0) throw("Enter a negative length");
	if (t > MAX_TASKS) throw("Enter a long length");
	tact = t;
	if ((a < 0) || (a > 1)) throw("you have gone beyond");
	A = a;
	if ((b < 0) || (b >= 0.9))  throw("you have gone beyond");
	B = b;
}

void Task::WorkWithTasks()
{
	double *times;//Массив для вычисления среднего значения выполнения задачи
	times = new double[tact];

	int k = 0; // счетчик для этого массива.
	double t = 0; // среднее значение времени для отчета выполнения

	int count = 0;//сколько задач в очереди

	int i = 0;// счетчик для прохода по тактам.
	int plain = 0; // счетчик простоя процессора

	TQueue<int> queue(tact); //очередь для задач( берем тип int, по очереди будут заходить счетчик i++, т.е адресса задач)

	int cpu=0; //состояние процессора, 1 - занят, 0 - не занят.

	unsigned int start_time;
	unsigned int end_time;
	unsigned int search_time;

	int flag =0;

	while (i < tact)
	{
		double Atask = 0; // рандомное число
		srand(time(NULL));
		Atask = (double)rand() / (double)RAND_MAX*(1 - 0) + 0;
		if (Atask > A)
		{
			queue.Push(i); //значит появиалась новая задача
		}
		double Btask = 0;
		if (!queue.IsEmpty() && cpu==1)
		{
			srand(time(NULL));
			Btask = (double)rand() / (double)RAND_MAX*(0.9 - 0) + 0;
			if (Btask > B)
			{
				cpu = 0; // процессор свободен
			}
		}
		if (cpu == 0 && flag==1)//если процессор свободен и есть задачи, значит завершил программу, то время заканчивается.
		{
			end_time = clock();
			search_time = end_time - start_time;
			times[k++] = search_time;
		}
		if (cpu == 1) 
			plain++; // если процессор все-таки занят, то такт простоя.
		if (cpu == 0 && !queue.IsEmpty())
		{
			if (!queue.IsEmpty()) queue.Pop();  // берем задачу.
			cpu = 1;
		}
		if (cpu == 1)
		{
			start_time = clock(); // если процессор занят, то запустилось выполнение задачи
			flag = 1;
		}
		i++;
	}
	count = queue.GetCount();//получаем количество задач оставшиеся в очереди.
	for (i = 0; i < k; i++)//вычисляем среднее время.
		t += times[i];
	t = t / k;
	delete[] times;
	report(tact, plain, count, t);

}

void Task::report(size_t tacts, int plain, int count, double time)
{
	cout << endl;
	cout << "Отчет" << endl;
	cout << "Среднее временя требующее для выполнение одной задачи = " << time << endl;
	cout << "Число тактов  простоя процессора = " << plain << endl;
	cout << "Количество оставшихся задач в очереди = " << count << endl;
	cout << "Общее количество тактов = " << tacts << endl;
}

