#ifndef __TASK_H__
#define __TASK_H__

#include<iostream>

using namespace std;

const int MAX_TACTS = 100; // максимальнок колчиесвто так-тов для задачи

class Ttask
{

	int task;// задача

public:
	Ttask(int tact);
	int ReturnTaskTacts();
	//void WorkWithTasks(double a); // работа с поток задач
	//void report(size_t tacts, int plain, int count, double time); // отчет по завершению программы

};


#endif