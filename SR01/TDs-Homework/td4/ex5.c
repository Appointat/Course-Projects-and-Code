#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 40
#define M 20
void initialsation(int torique[][N]) {
	//int** torique = (int**)malloc(M*sizeof(int*));
	int i, j;
	//for(i=0; i<N; i++) torique[i] = (int*)malloc(N*sizeof(int));
	
	time_t t=10;
	srand((unsigned) time(&t));
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			torique[i][j] = (rand()%3+1)%2*rand()%2;-
		}
	}
	
	//return torique;
}

void regle(int torique[][N], int x, int y) {
	int n = 0;
	if (torique[(x-1+M)%M][y]) n ++;
	if (torique[(x+1)%M][y]) n ++;
	if (torique[x][(y-1+N)%N]) n ++;
	if (torique[x][(y+1)%N]) n ++;

	if (n<2 || n>3) torique[x][y] = 0;
	else if (n==3) {
		torique[x][y] = 1;
		//if (x-1>-1 && !torique[x-1][y]) torique[x-1][y] = 1;
		//if (x+1<n && !torique[x+1][y]) torique[x+1][y] = 1;
		//if (y-1>-1 && !torique[x][y-1]) torique[x][y-1] = 1;
		//if (y+1<n && !torique[x][y+1]) torique[x][y+1] = 1;
	} else if (!torique[x][y] && n==4) torique[x][y] = 1;
}

void afichage(int torique[][N]) {
	int i,j;
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			printf("%d ", torique[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

int fini(int torique[][N]) {
	int i,j;
	int fini = 1;
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			if (torique[i][j] == 1) {
				fini = 0;
				break;
			}
		}
		if (fini==0) break;
	}
	if (fini) printf("Ce jeu de la vie est fini!\n");
	return fini;
}

void delay(int x) {
	clock_t start = clock();
	clock_t lay = (clock_t) x * CLOCKS_PER_SEC;
	while ((clock() - start) < lay) ;
}

int main() {
	int torique[M][N]; 
	initialsation(torique);
	afichage(torique);
	int fin = fini(torique);
	
	while(!fin) {
		delay(1);
		int i,j;
		for (i=0; i<M; i++) for (j=0; j<N; j++) regle(torique, i, j);
		afichage(torique);
		fin = fini(torique);
	}
	return 0;
}
