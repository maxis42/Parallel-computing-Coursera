#include <iostream>
const int n = 6;

using namespace std;

int main()
{
	int i, j;
	float* a = new float[n*n];


	for (int i = 0; i < n*n; i++)
		a[i] = 1.0f;

	for (int k = 0; k < 1; k++)
	{
		j = 2;
		for (i = 6; i < n*n; i++)
		{
			a[i] = a[i - j - 1] / (a[i - j] * a[i - j]) + 1;
			if ((i + 1) % n == 0)
			{
				j = j + 1;
			}
		}
	}
	cout << "example2" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i*n + j] << " ";
		}
		cout << endl;
	}


	return 0;
}