#include <iostream>
#include <vector>
#include <windows.h>
#include "omp.h"
#include "stdio.h"

using namespace std;

#define NUM_NUMBERS 100000

vector<int> divisors[NUM_NUMBERS+1];

int factorization();

int main()
{
#pragma noinline
   factorization();

  // ¬ывод простых множителей произвольных 10 чисел
  for (int i = 0; i < 10; i++)
  {
    int randomIdx = 1 + rand() % NUM_NUMBERS;
    cout << randomIdx << ":\t";
    int size = static_cast<int>(divisors[randomIdx].size());
    for (int j = 0; j < size;j++)
    {
      cout << divisors[randomIdx][j] << "\t";
    }
    cout << endl;
  }

}

int factorization() 
{
  

		for (int i = 1; i < NUM_NUMBERS; i++)
		{
			int number = i;
			int idx = number/2;

			for (int j = 2; j < idx; j++)
			{
				if (number == 1) break;

				int r;
				r = number % j;
				if (r == 0)
				{
					number /= j;
					divisors[idx].push_back(j);
					j--;
				}
			}
		}
  return 0;
}
