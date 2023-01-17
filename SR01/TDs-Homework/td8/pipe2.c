#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

       #include <sys/types.h>
       #include <sys/wait.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>
       #include <string.h>


#define STDIN 0
#define STDOUT 1

void fonc_pere();
void fonc_fils();
int f;
int fd[2];

main() {
	int i;
	pipe(fd);
	f=fork();
	switch(f)
	{
		case -1 : printf("erreur");exit(0);
		case  0 : fonc_fils();break;
		default : fonc_pere();break;
	}
}

void fonc_fils(){
	close(STDOUT);
	dup(fd[1]);
	/*close(fd[0]);
	close(fd[1]);*/
	execlp("ls","ls","-la",0);
}


void fonc_pere(){
	close(STDIN);
	dup(fd[0]);
	/*close(fd[0]);*/
	close(fd[1]);
	wait(f);
	execlp("wc","wc","-l",0);
}
