#include<stdio.h>
#include<stdlib.h>

int main(int nb, char* avg[]) {
	char *file = avg[1];
	char ch;
	
	FILE *fp = fopen(file, "rb");
	if (!fp) {
		printf("Can't open file...");
		exit(1);
	}	
	
	fseek(fp, 0L, SEEK_END);
	long int last = ftell(fp);
	long int count;
	for (count=1L; count<= last; count++) {
		fseek(fp, -count, SEEK_END);
		ch = getc(fp);
		if (ch != '\032' && ch != '\r') {
			putchar(ch);
		}
	}	
	putchar('\n');
	fclose(fp);
	
	return 0;
}
