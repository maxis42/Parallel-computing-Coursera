#include <stdlib.h>
#include <iostream>

const int n = 10;
using namespace std;
int main()
{
	int i;
	int K1[n], K2[n], L1[n], L2[n];


	for (i = 0; i < n; i++)
	{
		K1[i] = rand() % 10;
		K2[i] = rand() % 10;
		L1[i] = 0.0;
		L2[i] = 0.0;
		if (K1[i] > K2[i])
			L1[i] = K1[i];
		else
			L2[i] = K2[i];
	}

	for (i = 0; i < n; i++)
	{
		cout << L1[i] << " " << L2[i] << " " << K1[i] << " " << K2[i] << endl;
	}
}