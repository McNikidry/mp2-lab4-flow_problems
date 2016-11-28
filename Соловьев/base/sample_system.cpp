#include "system.h"
int main()
{
	setlocale(LC_ALL, "Russian");

	unsigned int n;

	cout << " Введите количество тактов Tack = ";
	cin >> n;
	cout << endl;

	double a, b;

	cout << "Введите приоритет появления новой задачи в пределах от 0 до 1, A = ";
	cin >> a;
	cout << endl;
	cout << "Введите приоритет выполнения задачи в пределах от 0 до 0.9, B = ";
	cin >> b;
	cout << endl;

	Task sample(n, a, b);

	sample.WorkWithTasks();

	return 0;
}