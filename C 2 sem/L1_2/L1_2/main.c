#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 5 //iloœæ wczytanych napisów
#define L 80 //d³ugoœæ ci¹gu

void wczytaj(char tab[N][L]);
void wyswietl(char tab[N][L]);
void sortuj(char tab[N][L]);

int main() {
	char tab[N][L];
	
	wczytaj(tab);




	printf("\n\n\n");
	system("pause");
	return 0;
}

void wczytaj(char tab[N][L]){
	for (int i = 0; i < N, i++)
		fgets(tab[i], L + 1, stdin);
}

void wyswietl(char tab[N][L]){
	for (int i = 0; i < N, i++)
		printf("%c", tab[i]);
}

void sortuj(char tab[N][L]){
	for(int i=0,i<N;i++)
		
}
