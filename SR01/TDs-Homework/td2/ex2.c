#include<stdio.h>
#include"ex2.h"

void main() {
	int tab[MAX];
	int i;
	
	for (i=0; i<MAX; i++) {
		tab[i] = i + VAL;
		printf("%d ", tab[i]);
	}
}
