#include<iostream>
using namespace std;

double GP(double a[], double b[], int N) {
	int br = 0;
	double *z;
	z = new double[N];

	//prvo vrijednosti clanova sporednog niza postavimo na nula "0"
	for (int i = 0; i < N; i++) {
		z[i] = 0;
		for (int j = i + 1; j < N; j++) {
			//sad cemo grupirati clanove koji se ponavljaju
			if (a[i] == a[j]) {
				for (int k = i - 1; k >= 0; k--) {
					//provjeravamo da li je se vec ovaj broj negdje pojavio
					if (a[i] == a[k]) {
						br++; //ukoliko je se pojavio uvecaj brojcanik
					}
				}
				if (br == 0) {
					b[i] += b[j];
					z[i] = b[i];
				}
				//postavimo vrijednost nula prije ponovnog ulaska u petlju
				br = 0;
			}
			else {
				//provjera broja otpornika
				for (int k = i - 1; k >= 0; k--) {
					if (a[i] == a[k]) {
						br++;
					}
				}
				//ukoliko se otpornik nije prije pojavljivao, onda cemo ga spremiti
				if (br == 0) {
					z[i] = b[i];
				}
				br = 0;
			}
		}
	}
	for (int t = 0; t < N; t++) {
		b[t] = z[t];
	}
	return 0;
}
//sad cemo posebno napisati funkcije za racunanje aritmeticke sredine, geometrijske sredine, te harmonijske
double AritmetièkaSredina(double X1[], double F1[], int N1) {
	double a1 = 0;
	double b1 = 0;
	double sum1 = 0;

	for (int i = 0; i < N1; i++)
	{
		a1 += F1[i] * X1[i];
		b1 += F1[i];
	}
	sum1 = a1 * 1 / b1;
	cout << " Aritmeticka sredina je : " << sum1 << endl;
	return 0;
}
double GeometrijskaSredina(double X2[], double F2[], int N2) {
	double a2 = 0;
	double b2 = 0;
	double c2 = 0;
	double sum2 = 0;
	for (int j = 0; j < N2; j++)
	{
		a2 += F2[j] * log(X2[j]);
		b2 += F2[j];
	}
	c2 = a2 * 1 / b2;
	sum2 = exp(c2);
	cout << " Geometrijska sredina je : " << sum2 << endl;
	return 0;
}
double HarmonijskaSredina(double X3[], double F3[], int N3) {
	double a3 = 0;
	double b3 = 0;
	double sum3 = 0;
	for (int k = 0; k < N3; k++)
	{
		a3 += F3[k] / X3[k];
		b3 += F3[k];
	}
	sum3 = b3 / a3;
	cout << " Harmonijska sredina je : " << sum3 << endl;
	return 0;
}
int main() {

	double interval;
	double x[] = { 2.5,6.4,4.3,0.3,4.6,0.6,3.1,6.5,3.7,7.8,2.8,0.8,9.5,1.7,2.5,6.8,12.1,1.2,11.5,2.4 };

	int n = sizeof(x) / sizeof(double);

	cout << "Unesite vrijednost intervala:  " << endl;
	cin >> interval;

	double DG = 0;
	double GG = 0;
	double xsr = 0;
	double *f;
	f = new double[n];

	for (int i = 0; i < n; i++) {
		f[i] = 0;
		int c = x[i] / interval;
		DG = c * interval;
		GG = DG + interval;
		xsr = (DG + GG) / 2;
		f[i] = xsr;
		cout << f[i] << endl;
	}

	GP(x, f, n);

	AritmetièkaSredina(x, f, n);
	GeometrijskaSredina(x, f, n);
	HarmonijskaSredina(x, f, n);

	int b;
	cin >> b;
}