#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
extern char etext, edata, end;
int main()
{
	int n;
	printf("\n etext %10p", &etext);
	printf("\n edata %10p", &edata);
	printf("\n end %10p", &end);
	printf("\n break point = %d = 0x%x", sbrk(0), sbrk(0));
	n = &edata - &etext;
	printf("\n edata - etext = %d = 0x%x", n, n);
	n = &end - &edata;
	printf("\n end - edata = %d = 0x%x", n, n);
	printf("\n");
	return 0;
}

