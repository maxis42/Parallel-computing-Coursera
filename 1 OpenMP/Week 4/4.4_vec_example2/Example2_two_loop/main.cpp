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
		for (int i = 1; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				a[n*i + j] = a[n*i + j - (i + 1) - 1] / (a[n*i + j - (i + 1)] * a[n*i + j - (i + 1)]) + 1;
			}
	
	cout << "example2_two_loop" << endl;
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