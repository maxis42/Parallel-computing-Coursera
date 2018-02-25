#include <iostream>
#include "omp.h"
#include <string>

using namespace std;
int main()
{
	string hw = "Hello, world\n";
#pragma omp parallel
	cout << hw;
	return 0;
}
