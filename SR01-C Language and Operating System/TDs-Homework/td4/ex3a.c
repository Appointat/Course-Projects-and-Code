#include<stdio.h>
#define N 2
#define M 2
void matrice_info(int mat[M][N]) {
	int i, j;
	int n_zero = 0;
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			printf("%d %d  %d\n", i, j, mat[i][j]);
			if (mat[i][j] == 0) {
				n_zero ++;	
			}
		}
	}
	
	printf("nombre de zeros est %d\n", n_zero);
}

int main() {
	int mat[M][N];
	int i, j;
	for (i=0; i<M; i++) {
		for (j=0; j<N; j++) {
			mat[i][j] = i*N + j;
			// printf("%d\n", mat[i][j]);
		}
	}
			
	// printf("%d", **mat);
	matrice_info(mat);
	return 0;
}
