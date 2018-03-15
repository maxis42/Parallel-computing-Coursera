#include <stdio.h>
#include <omp.h>
#include <locale>

int main()
{
	setlocale(LC_ALL, "Russian");
	int i, n;
#pragma omp parallel private (i, n)
	{
		n = omp_get_thread_num();
#pragma omp for ordered
		for (i = 0; i<5; i++)
		{
			printf("Поток %d, итерация %d\n", n, i);
#pragma omp ordered
			{
				printf("ordered: Поток %d, итерация %d\n", n, i);
			}
		}
	}
}
