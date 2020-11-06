#include <iostream>
using namespace std;

int main()
{
	int f1[] = { 24, 12, 7, 15, 4, 4, 9, 5 };
	int f2[] = { 17, 6, 6, 1, 5, 2, 3, 1 };
	double a = 0;
	double b;
	double suma = 0;

	for (int i = 0; i < 8; i++)
	{
		a =a+ f1[i] * f2[i];
		b = 41;
	}
	suma = a/b;
	cout << "Aritmeticka sredina je: " << suma << endl;

	return 0;
};