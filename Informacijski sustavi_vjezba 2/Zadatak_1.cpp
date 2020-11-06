#include <iostream>
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

int main() {
	//unesimo nizove s vjezbe koje cemo grupirati
	double A[] = { 1,3.3,0.3,1,5.6,10,1.2,1,0.3,1,0.3,5.6,0.3,1.2,10,2.2,1.2 };
	double B[] = { 2,1,2,4,2,3,5,10,1,2,5,4,10,6,8,2,5 };

	int n = sizeof(A) / sizeof(double);
	//poziv funkcije za grupiranje podataka
	GP(A, B, n);
	//ispis vrijednosti otpornika...
	for (int e = 0; e < n; e++) {
		if (B[e] != 0) {
			cout << "Vrijednost otpornika  "<< A[e] << "  kOhm " <<" je "<< B[e] << endl;
		}
	}

	return 0;
}



