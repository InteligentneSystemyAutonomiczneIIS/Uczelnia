#include <stdlib.h>
#include <stdio.h>

int main() {
	int cal;
	int *wsk;

	cal = 5;
	wsk = &cal;

	printf("Wartosc bezposrednio: %d \nWartosc przez wskaznik: %d \nAdres zmiennej: %p \n\n\n", cal, *wsk, wsk);

	*wsk = 10;

	printf("Wartosc bezposrednio: %d \nWartosc przez wskaznik: %d \nAdres zmiennej: %p \n\n\n", cal, *wsk, wsk);

	system("pause");
	return 0;
}