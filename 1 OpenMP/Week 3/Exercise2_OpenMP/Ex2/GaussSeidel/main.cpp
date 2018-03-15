//------------------------------------------------------------
// Программа решения уравнений пуассона методом Гаусса-Зейделя
//------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <omp.h>
#include "submit.h"
#include "GaussSeidel.h"
#include "locale.h"
using namespace std;

int main(int argc, char **argv)
{
		
	double **u=NULL, **f=NULL;
	double **u_ser=NULL, **f_ser=NULL;
	double **u_par1 = NULL, **f_par1 = NULL;
	
	setlocale(LC_ALL, "Russian");
	
	int N = 1000; // Количество точек сетки по каждой размерности
	double eps = 0.01; // Точность вычислений
	int IterCnt; // Количество итераций
	double tt;

	
	
	//	 Последовательная программа

		tt = omp_get_wtime(); 
		f_ser = new_arr(N); // Выделение переменной под правую часть значений уравнения
		u_ser = new_arr(N + 2); // Выделение памяти под неизвестные и краевые условия
		Init(u_ser, f_ser, N); // Инициализация краевых условий и правой части уравнения
		cout << "Проводятся расчеты по методу Гаусса-Зейделя (последовательный вариант)" << endl;
		IterCnt=Calc_seq(u_ser, f_ser, N, eps); // Вызов функции расчета по методу Гаусса-Зейделя
		tt = omp_get_wtime() - tt;
		cout << "Serial Time = " << tt << " IterCnt = " << IterCnt << endl;
		cout << "Результаты расчетов" << endl;
		UOutput(u_ser, N); // Вывод результатов на экран. Выводится 10 строчек и столбцов итогового решения. Растояние между выведеными столбцами строчками одинаковое.
		cout << endl;

	   // Параллельная программа 
		tt = omp_get_wtime();
		f_par1 = new_arr(N); // Выделение переменной под правую часть значений уравнения
		u_par1 = new_arr(N + 2); // Выделение памяти под неизвестные и краевые условия
		Init(u_par1, f_par1, N); // Инициализация краевых условий и правой части уравнения
		cout << "Проводятся расчеты по методу Гаусса-Зейделя (параллельный вариант)" << endl;
		IterCnt = Calc_par(u_par1, f_par1, N,  eps); // Вызов функции расчета по методу Гаусса-Зейделя
		tt = omp_get_wtime() - tt;
		cout << "Par1 Time = " << tt << " IterCnt = " << IterCnt << endl;
		cout << "Результаты расчетов" << endl;
		UOutput(u_par1, N); // Вывод результатов на экран. Выводится 11 строчек и столбцов итогового решения. Растояние между выведеными столбцами строчками одинаковое.


	
//	Submit_Part1(N,eps,Calc_seq);
	
//	Submit_Part2(Calc_par);

	return 0;
}
