#include "GaussSeidel.h"
#include "omp.h"
#include <iomanip>
#include <cstdlib>
#include <iostream>

using namespace std;


int Calc_par(double** u, double** f, int N, double eps)
{

	double max = 0;
	double h = 1.0 / (N + 1);

	int IterCnt = 0; // Переменная хранящая количество выполненых итераций
	int BlockSize = 100; // Переменная отвечающая за размерность блока, для которого выполняется обработка
	int BlockCount; // Количество блоков

	// Здесь вы должны реализовать параллельный блочно-волновой алгоритм
	
	return IterCnt;
}
