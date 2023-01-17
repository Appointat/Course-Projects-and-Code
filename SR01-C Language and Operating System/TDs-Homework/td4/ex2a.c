#include<stdio.h>
#define TAILLE 10
int main() {
	int i = 0;
	int j = 0;
	for (i=0; i<TAILLE; i++) {
		for (j=0; j<TAILLE-i; j++) printf(" ");
		for (j=0; j<2*i-1; j++) printf("*"); 
		printf("\n");
	}
	
	for (i=0; i<4; i++) {
		for (j=0; j<TAILLE-3; j++) printf(" ");
		for (j=0; j<4; j++) printf("*");
		printf("\n");
	}
	
	return 0;
}
