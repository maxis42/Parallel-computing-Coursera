#include <iostream>
#include <stdio.h>
#include <omp.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	double k = 0;
#pragma omp parallel num_threads(4) firstprivate(k)
	{
		printf("Перед директивой single без nowait \n");
#pragma omp single
		{
			// Данный цикл добавлен для того, чтобы поток выполнил какую-нибудь работу
			for (int i = 0; i < 100000; i++)
			{
				k += (double)i / (i + 1);
			}
			printf("В директиве single \n");
		}
		printf("После директивы single без nowait. Это сообщение никогда не будет раньше предыдущих. k = %f \n",k);

#pragma omp barrier // Данная директива синхронизирует потоки, в следующих лекциях она будет рассмотрена. 

		printf("Перед директивой single c nowait \n");
#pragma omp single nowait
		{
			// Данный цикл добавлен для того, чтобы поток выполнил какую-нибудь работу
			for (int i = 0; i < 100000; i++)
			{
				k += (double)i / (i + 1);
			}
			printf("В директиве single \n");
		}
		printf("После директивы single c nowait. Это сообщение может быть раньше предыдущих. k =  %f \n", k);
	}
	return 0;
}
