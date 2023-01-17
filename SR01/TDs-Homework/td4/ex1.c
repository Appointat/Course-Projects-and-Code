#include<stdio.h>


void main() {
	char ch[100];	
	fgets(ch, 4, stdin);
	
	int i = 0;
	int len = 0;
	while (ch[i]!='\0') {
		len ++;
	}
	
	printf("%d", len);
}
