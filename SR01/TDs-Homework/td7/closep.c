#include <stdio.h>
#include <fcntl.h>

#include <stdlib.h>
#include <unistd.h>

int main() {
	int pid,i,status;
	int fd,fd2;

	fd=open("/dev/tty",O_RDWR|O_CREAT,0666); // 6 = 110
	printf("avant close, %d\n", fd);
	close(1);
	dup(1);
	printf("apres close, %d\n", fd2);
	fd2 = dup(fd);
	//dup() -> closep.c
	printf("apres dup, %d\n", fd2);
	//close(1);
	close(fd);
	//close(1);
	printf("Le 4eme printf...\n");
	
	return 0;
}
