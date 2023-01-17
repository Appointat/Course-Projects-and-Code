#include<stdio.h>
#include"mystr.h"

void main() {
	char *s1 = "AbCdEfG";
	char s2[7];
	
	mystrupdown(s1, s2);
	
	int i = 0;
	for (i=0; i<7; i++) printf("%c", s2[i]);
	printf("\n");
}
