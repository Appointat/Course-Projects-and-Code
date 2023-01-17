#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	int status;
	for (int i=0; i<2; i++) {
		pid_t pid = fork();
		if (pid == -1) {
			// Il y a une erreur
			perror("fork");
			return EXIT_FAILURE;
		} else if (pid == 0) {
			// On est dans le fils
			printf("Fils1 : ");
			printf("Mon PID est %i et celui de mon père est %i\n", getpid(), getppid());
			exit(11);
		} else {
			// On est dans le père
			int pid2 = fork();
			if (pid2 == -1) {
				// Il y a une erreur
				perror("fork");
				return EXIT_FAILURE;
			} else if (pid2 == 0) {
				// On est dans le fils
				printf("Fils2 : ");
				printf("Mon PID est %i et celui de mon père est %i\n", getpid(), getppid());
				exit(22);
			} else {
				// On est dans le père
				int pid_f;
				printf("j'attend la fin de mon deuxieme fils .......................\n");
				pid_f = waitpid(pid2, &status, 0);
				printf("mon deuxieme fils a fait un exit(%d)\n", status >> 8);
				pid_f = waitpid(pid,&,0);
				printf("mon premier fils de pid a  fait un exit(%d)\n", status >> 8);
				
				printf("Parent : ");
				printf("Mon PID est %i et celui de mon fils est %i\n", getpid(), pid2);
			}
		}
	}
	return EXIT_SUCCESS;
}
