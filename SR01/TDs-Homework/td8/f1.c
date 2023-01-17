#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t pid = fork();
	if (pid == -1) {
		// Il y a une erreur
		perror("fork");
		return EXIT_FAILURE;
	} else if (pid == 0) {
		// On est dans le fils
		printf("Fils : Mon PID est %i et celui de mon père est %i\n", getpid(), getppid());
	} else {
		// On est dans le père
		printf("Parent : Mon PID est %i et celui de mon fils est %i\n", getpid(), pid);
	}
	return EXIT_SUCCESS;
}
