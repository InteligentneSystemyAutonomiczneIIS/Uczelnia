#include <stdio.h>
#include <stdlib.h>		
#include <time.h>		//seed
#include <Windows.h>	//kolory

//------------------- PARAMETRY DO EDYCJI ---------------------

#define M 15 //wysokoœæ tablicy
#define N 20 //szerokoœæ tablicy
#define MIN 1 //wartoœæ minimalna losowanych liczb
#define MAX 9 //wartoœæ maksymalna losowanych liczb
#define X 2 //pozycja x liczby
#define Y 3 //pozycja y liczby

//------------------- PARAMETRY DO EDYCJI ---------------------

//----------------FUNKCJE
void wyswietl(int tab[]);
void wyswietl2(int tab[]);
void random(int tab[]);
int oblicz(int tab[]);

int main() {
	//------------DEKLARACJE
	srand(time(NULL));

	int tab[M*N];
	int mem;


	//------------------ TEST KOLORÓW
	//for (int i = 0; i < 50; i++) {
	//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
	//	printf("##############    %d\n",i);
	//}


	//------------FUNKCJE
	random(tab);
	wyswietl(tab);
	wyswietl2(tab);
	mem = oblicz(tab);

	//------------WYŒWIETLANIE
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("\n\n\n");
	printf("X: %d\n", X);
	printf("Y: %d\n", Y);
	printf("WYNIK: %d", mem);

	//------------KONIEC
	printf("\n\n\n");
	system("pause");
	return 0;
}


//===============================CIA£A FUNKCJI

//---------------------WYŒWIETL
void wyswietl(int tab[]){
	for (int i = 0; i < M*N; i++)
		printf((i + 1) % N == 0 ? "%d\n" : "%d ", tab[i]);
	printf("\n");
}

//---------------------RANDOM
void random(int tab[]){
	for (int i = 0; i < M*N; i++)
		tab[i] = rand() % (MAX-MIN+1)+MIN;
}

//---------------------OBLICZ
int oblicz(int tab[]){
	int memory = 0;
	for (int i = 1; i <= M; i++)
		for(int j=1;j<=N;j++)
			if(j-i==X-Y||j+i==X+Y)
				memory += tab[(i - 1)*N + (j - 1)];
	return memory;
}

//---------------------WYŒWIETL2 - KOLORY
void wyswietl2(int tab[]) {
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++) {
			if (j - i == X - Y || j + i == X + Y)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf(((i - 1)*N + (j - 1) + 1) % N == 0 ? "%d\n" : "%d ", tab[(i - 1)*N + (j - 1)]);
		}
	printf("\n");
}
