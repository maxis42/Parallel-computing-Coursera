#include "omp.h"
#include <iostream>
#include "submit.h"
using namespace std;

void vec_random_norm(float* rand_arr, int n)
{
	float min_elem, max_elem;

	// Calculate min and max array elements in single thread and copy to private variables
#pragma omp single copyprivate(min_elem, max_elem)
	{
		// Search for the min and max elements
		min_elem = rand_arr[0];
		max_elem = rand_arr[0];

		for (int i = 1; i < n; i++) {
			if (rand_arr[i] < min_elem) min_elem = rand_arr[i];
			if (rand_arr[i] > max_elem) max_elem = rand_arr[i];
		}
	}

	// Get thread index for array
	int index = omp_get_thread_num();

	// Normalize value
	rand_arr[index] = (rand_arr[index] - min_elem) / (max_elem - min_elem);

	Submit_test();
}