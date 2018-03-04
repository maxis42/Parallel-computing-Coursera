#include "submit.h"
#include "omp.h"
#include "stdlib.h"
#include "time.h"
#include "ex_function.h"
//#include <iostream>

//using namespace std;

float* vec_random(int n, bool normal)
{
	float* rand_arr = new float[n];
	
	// ----------------------------------------------------------
	// Комментарий 1. После этого комментария должен быть ваш код
	// ----------------------------------------------------------

#pragma omp parallel num_threads(n)
	{
		// Array index to generate
		int index = omp_get_thread_num();

		// Initialize random seed
		srand(index);

		// Get pseudo-random number in [1, 100]
		rand_arr[index] = float(rand() % 100);

		if (normal)
		{
#pragma omp barrier // Это дериктива синхронизации. Мы с вами их еще не рассматривали, 
					// но для корректной реализации при выполнении этого кода внутри
					// параллельной области, она необходима
			vec_random_norm(rand_arr, n);
		}

		// Submit answer
		Submit_test();
	}
	// ----------------------------------------------------------------------------------------
	// -- весь код между этим комментарием и комментарий 1 должен быть в параллельной области--
	// ----------------------------------------------------------------------------------------
return rand_arr;
}