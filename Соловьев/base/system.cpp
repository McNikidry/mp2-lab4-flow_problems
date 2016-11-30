#include"queue.h"
#include"task.h"
#include <conio.h>

Ttask::Ttask(int takt)
{
	if (takt < 1) throw("Enter a negative length");
	if (takt > MAX_TACTS) throw("Enter a long length");
	task = takt;
}
int Ttask::ReturnTaskTacts()
{
	return task;
}