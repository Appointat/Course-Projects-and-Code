#include<stdio.h>


void main() {
	int MAX = 5;
	int tab1[5] = {6,4,5,10,8};
	int tab2[5] = {7,8,9,10,11};
	int tab3[5];
	
	int i=0;
	for (i=0; i<MAX; i++) {
		*(tab3+i) = *(tab1+i) + *(tab2+MAX-i-1);
	}
	
	for (i=0; i<MAX; i++) {
		printf("%d ", tab3[i]);
	}
}
