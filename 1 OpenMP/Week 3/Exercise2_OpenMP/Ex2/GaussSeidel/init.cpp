#include "GaussSeidel.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Функция задания границчных значений
double G(double x, double y)
{
	if (x == 0) return 1 - 2 * y;
	if (x == 1) return -1 + 2 * y;
	if (y == 0) return 1 - 2 * x;
	if (y == 1) return -1 + 2 * x;
}

// Функция задания правой части
double F(double x, double y)
{
	return 2.2;
}
// Функция вывода матрицы. Выводятся только 11 строк и 11 столбцлв матрицы расположенных на одинаковом растоянии друг от друга
void UOutput(double** u, int N)
{
	cout << fixed << setprecision(3);
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
			cout << setw(7) << u[i * (N + 1) / 10][j * (N + 1) / 10];
		cout << endl;
	}
}

// Функция выделения памяти под массив
double** new_arr(int N)
{
	double** f = new double*[N];
	for (int i = 0; i < N; i++)
	{
		f[i] = new double[N];
	}
	return f;
}

// Функция освобождения памяти 
int delete_arr(double** arr,int N)
{
	for (int i = 0; i < N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	return 0;
}

// Инициализация значений массивов. Заданий правой части и краевых условий
void Init(double **u,double **f, int N)
{
	double h = 1.0 / (N + 1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			f[i][j] = F((i + 1) * h, (j + 1) * h);
	}
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
			u[i][j] = 0.2;
		u[i][0] = G(i * h, 0);
		u[i][N + 1] = G(i * h, (N + 1) * h);
	}
	for (int j = 0; j < N + 2; j++)
	{
		u[0][j] = G(0, j * h);
		u[N + 1][j] = G((N + 1) * h, j * h);
	}
}