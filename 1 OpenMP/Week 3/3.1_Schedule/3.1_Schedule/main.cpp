#include <stdio.h>
#include <omp.h>
#include <locale>
#include <windows.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int i;
#pragma omp parallel private(i) num_threads(4)
	{
#pragma omp for schedule (static, 6)
//#pragma omp for schedule (dynamic, 6)
//#pragma omp for schedule (guided, 6)
		for (i = 0; i<200; i++)
		{
			printf("Поток %d выполнила итерацию %d\n", omp_get_thread_num(), i);
			Sleep(1); 
		}
	}
}
