#ifndef __TASK_H__
#define __TASK_H__

#include<iostream>

using namespace std;

const int MAX_TASKS = 10000;

class Task
{
private:
	size_t tact;// количество тактов всего 
	double A; // приоритет для появления новой задачи
	double B; // приоритет для выполнения задачи

public:
	Task(size_t t,double a,double b);
	void WorkWithTasks(); // работа с поток задач
	void report(size_t tacts, int plain, int count, double time); // отчет по завершению программы

};


#endif