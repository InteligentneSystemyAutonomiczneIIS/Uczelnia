#include <stdlib.h>
#include <stdio.h>

#define L 8

void wyswietl(int tab[]);

int main() {
	int tab[L] = { 5,10,15,20,25,30,35,40 };

	wyswietl(tab);

	system("pause");
	return 0;
}

void wyswietl(int tab[])
{
	int *wsk = tab;
	wsk += L;

	for (; tab < wsk; tab++) {
		printf("%d\n", *tab);
	}
}
