#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
	int a[] = { 15,38,50,150,302,200,81,30,26,20,15,18,14,9,7,6,8 };
	int suma = 0;
	int n = sizeof(a) / sizeof(int);
	//napravili smo petlju koja zbraja broj komada TV prijamnika 
	for (int i = 0; i < n; i++) {
		suma += a[i];
	}

	int M = suma / 2;
	int suma_m = 0;
	int suma_v = 0;
	//Petlja se vrti sve dok ne prijeðemo polovisu sume, odnosno M
	//isto tako u petlji smo postavili uvjet koji provjera tu èinjenicu
	for (int j = 0; j < n; j++) {
		suma_v += a[j];
		if (suma_v >= M) {
			suma_m = suma_v - a[j];
			break;
		}
	}
	//kad smo presli 500 stajemo i usporedujemo
	//za medijan odlucujemo tako da biramo onu vrijednost koja je bliza 500 
	if (abs(M - suma_v) > abs(M - suma_m)) {
		cout << "Medijan: " << suma_m << endl;
	}
	else {
		cout << "Medijan: " << suma_v << endl;
	}
}
