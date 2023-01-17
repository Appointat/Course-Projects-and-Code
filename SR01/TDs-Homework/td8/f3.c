#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	pid_t pid = fork();
	int status;
	if (pid == -1) {
		// Il y a une erreur
		perror("fork");
		return EXIT_FAILURE;
	} else if (pid == 0) {
		// On est dans le fils
		printf("Fils : Mon PID est %i et celui de mon père est %i\n", getpid(), getppid());
		exit(43);
	} else {
		// On est dans le père
		pid = wait(&status);
		status = WEXITSTATUS(status);
		printf("Parent : Mon PID est %i et celui de mon fils est %i, status = %d\n", getpid(), pid, status);
	}
	return EXIT_SUCCESS;
}
