#include<stdio.h>

int main(int argc, char **argv) {
	if (argc==0) {
		printf("Error, argc=0.\n");
		return 0;
	}	
	
	printf("Variable : %s\n",argv[0]);
	
	return 0;
}
