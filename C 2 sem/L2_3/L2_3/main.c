#include <stdio.h>
#include <stdlib.h>

void sprawdzenie(int liczba, int *parzysta, int *pierwsza, int *podzielna);

int main() {
	int fpa=0, fpi=0, fpo=0;
	int liczba = 2;
	sprawdzenie(liczba, &fpa, &fpi, &fpo);

	printf("Liczba: %d \n\n 1 - TAK, 0 - NIE \n\n	Parzysta: %d \n	Pierwsza: %d \n	Podzielna: %d \n\n\n", liczba, fpa, fpi, fpo);




	system("pause");
	return 0;
}

void sprawdzenie(int liczba, int *parzysta, int *pierwsza, int *podzielna){
	*parzysta = liczba % 2 == 0 ? 1 : 0;

	*podzielna = liczba % 3 == 0 ? 1 : 0;

	for (int i = 2; i <= liczba; i++) {
		if (liczba%i == 0) {
			*pierwsza = 0;
			i = 500;
		}
		else {
			*pierwsza = 1;
			i = 500;
		}
	}


	
}
