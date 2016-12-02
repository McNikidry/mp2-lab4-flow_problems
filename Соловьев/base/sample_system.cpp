#include "task.h"
#include"queue.h"
#include<time.h>
#include<conio.h>

int main()
{
	setlocale(LC_ALL, "Russian");

	double A; // вероятность появление новой задачи
	int Midle_Tacts;// среднее значения для тактов

	do
	{
		system("cls");
		cout << "Введите вероятность появления новой задачи в пределах от 0 до 1, A = ";
		cin >> A;
		cout << endl;
	} while (A < 0 || A >1);
	do
	{
		system("cls");
		cout << "Введите макимальное среднее значение для каждой задачи = ";
		cin >> Midle_Tacts;
		cout << endl;
	} while (Midle_Tacts < 0 || Midle_Tacts > 101);


	double tact = 0; // тактов всего
	int plain = 0; // такты простоя процессора
	int cpu = 0; //состояния процессора 1-занят, 0-свободен
	double completed_task = 0; // количетсво выполненых задач
	int tasks = 0; // количество задач всего
	int count = 0; // количество задач в очереди
	TQueue<int> queue(MAX_TACTS);//очередь для задач
	int tmp;
	int tmp_one=0;
	int waste_cycles = 1;//циклы для проверки завершения программы
	srand(time(NULL));

	while (!_kbhit()) // функция, которая ждет нажатия клавиватуры..
	{
		system("cls");
		cout << "Идет выполнение работы......" << endl;
		cout << "Нажмите любую клавишу, чтобы остановить работу программы" << endl;
		tact++; // + один такт
		tmp = rand() % Midle_Tacts + 1;
		Ttask task(tmp);
		double Atask;
		Atask = (double)rand() / (double)RAND_MAX*(1 - 0) + 0;
		if (Atask > A)
		{
			queue.Push(tmp);
			tasks++;
		}
		if (!queue.IsEmpty() && cpu == 0)
		{
			tmp_one = queue.Pop();//берем задачу
			cpu = 1;
		} 
		if (tmp_one == (waste_cycles++) && cpu == 1) // то задача выполнилась
		{
			cpu = 0;
			completed_task++;
			waste_cycles = 1;
		} 
		if (cpu == 1 && !queue.IsEmpty()) // такт простоя
			plain++;

	}
	double t=(completed_task / tact);
	count = queue.GetCount();
	system("cls");
	cout << "Количество отработанных тактов всего - "<<tact << endl;
	cout << "Среднее время выполнения задач - "<< t << endl;
	cout << "Количество всего принятых задач - "<< tasks << endl;
	cout << "Количество выполненых задач - "<< completed_task << endl;
	cout << "Количество тактов простоя - "<< plain << endl;
	cout << "Количество задач, оставшихся в очереди - " << count << endl;


	return 0;
}