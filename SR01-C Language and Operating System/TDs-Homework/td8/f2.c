#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
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
			} else {
				// On est dans le père
				printf("Parent : ");
				printf("Mon PID est %i et celui de mon fils est %i\n", getpid(), pid2);
			}
		}
	}
	return EXIT_SUCCESS;
}
