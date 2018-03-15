#include <stdio.h>
#include <omp.h>
#include <locale>

int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
#pragma omp parallel
	{
#pragma omp critical
	{
		n = omp_get_thread_num();
		printf("Поток %d\n", n);
	}
	}
}
