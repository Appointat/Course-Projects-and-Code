#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	//int tab1[10]={11,22,33,44,55,66,77,88,99,1000};
	char tab1[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	char tab2[10];
	int i,fd;

	fd=open("titi.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
	write (fd,tab1,10*sizeof(char));
	close(fd);
	fd=open("titi.txt",O_RDWR,0666);
	read (fd,tab2,10*sizeof(char));
	close(fd);

	for (i=0;i<10;i++)
		printf("%c,%c\n",tab2[i],tab1[i]);

	return 0;
}
