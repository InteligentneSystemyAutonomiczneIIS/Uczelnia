#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 5
#define N 5
#define MIN 1
#define MAX 9

void wyswietl(int tab[]);


int main() {
	//srand(time(NULL));

	int tab[25] ={0,1,0,0,0,
				0,0,1,0,1,
				0,0,0,1,0,
				0,0,1,0,1,
				0,1,0,0,0 };

	wyswietl(tab);


	system("pause");
	return 0;
}

void wyswietl(int tab[]){
	for (int i = 0; i < M*N; i++)
		printf((i + 1) % N == 0 ? "%d\n" : "%d ", tab[i]);
}
