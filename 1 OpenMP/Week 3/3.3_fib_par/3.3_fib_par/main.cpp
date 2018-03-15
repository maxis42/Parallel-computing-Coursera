#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <locale>

int const splitter = 30; // После какого числа не пораждаются новые задачи
int const fib_num = 35; // Порядковый номер искомого числа Фибоначи

using namespace std;

// Последовательная рекурсивная функция вычисления числа Фибоначи
long int fib_seq(long int  n) 
{
	long int i, j;
	if ((n == 1) || (n == 0))	return n;
	else
	{
		return fib_seq(n - 1) + fib_seq(n - 2);
	}
}

// Параллельная рекурсивная функция вычисления числа Фибоначи
long int fib_par(long int n)
{
	long int a, b;
	if ((n == 1) || (n == 0))	return n;
	else
	{
#pragma omp task shared( a )
		a = fib_par(n - 1);
#pragma omp task shared( b )
		b = fib_par(n - 2);
#pragma omp taskwait
		return a + b;
	}

}

// Параллельная рекурсивная функция вычисления числа Фибоначи с дополнительными модификациями
long int fib_par_mod(long int n)
{
	long int i, j;
	if (n < splitter) {
		return fib_seq(n);
	}
	else
	{
	if ((n == 1) || (n == 0))	return n;
#pragma omp task shared( i )
		i = fib_par_mod(n - 1);
#pragma omp task shared( j )
		j = fib_par_mod(n - 2);
#pragma omp taskwait
		return i + j;
	}

}


int main()
{
	setlocale(LC_ALL, "Russian");

// Замер времени последовательной функции
	double t = omp_get_wtime();
	cout << "Последовательная функция " << fib_seq(fib_num) << endl;
	cout << "Время=" << omp_get_wtime() - t << endl;

// Замер времени параллельной функции
	t = omp_get_wtime();
#pragma omp parallel
	{
#pragma omp single nowait
		{
			cout << "Параллельная функция " << fib_par(fib_num) << endl;
		}
	}

	cout << "Время=" << omp_get_wtime() - t << endl;

// Замер времени параллельной функции с подификациями
	t = omp_get_wtime();
#pragma omp parallel
	{
#pragma omp single nowait
		{
			cout << " Параллельная с модификациями " << fib_par_mod(fib_num) << endl;
		}
	}

	cout << "Время=" << omp_get_wtime() - t << endl;
}
