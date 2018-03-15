#include <stdio.h>
#include <omp.h>
#include <locale>
#include <Windows.h>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	int n; 
	omp_lock_t lock;
	omp_init_lock(&lock);
#pragma omp parallel private (n)
	{
		n = omp_get_thread_num();
		omp_set_lock(&lock);
		printf("Начало закрытой секции, поток %d\n", n);
		Sleep(5);
		printf("Конец закрытой секции, поток %d\n", n);
		omp_unset_lock(&lock);
	}
	omp_destroy_lock(&lock);
	return 0;
}
