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

//MOD
double Mod(double a[], double b[], int M) {
	int max_f = b[1];
	int max_v = a[1];
	//prvo napravimo petlju za sortiranje niza koja radi na nacin na na prvi mjesto stavi najveci clan, te u sljedecem
	//koraku provjerava da li je naredni clan veci od prethodnoga
	for (int g = 0; g < M; g++) {
		if (max_f < b[g]) {
			max_f = b[g];
		}
	}
	for (int r = 0; r < M; r++) {
		if (b[r] == max_f) {
			cout << "Mod: " << a[r] << endl;
		}
	}
	return 0;
}

int main() {
	double A[] = { 2.5,6.4,4.3,0.3,4.6,0.6,3.1,6.5,3.7,7.8,2.8,0.8,9.5,1.7,2.5,6.8,12.1,1.2,11.5,2.4 };
	double B[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	double C[] = { 3,7,5,1,5,1,3,7,3,7,3,1,9,1,3,7,13,1,11,3 };

	int n = sizeof(C) / sizeof(double);
	//pozivanje funkcija za grupiranje podataka i MOD
	GP(C, B, n);

	Mod(A, B, n);

	return 0;
}

