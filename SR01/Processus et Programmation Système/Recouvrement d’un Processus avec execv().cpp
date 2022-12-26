#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main() {
	pid_t pid;
	char* const arguments[] = { "/bin/ls", "-l", NULL };
	pid = fork();
	if (pid == -1)
		perror("erreur de fork()");
	else if (pid == 0) {
		execv("/bin/ls", arguments);
		printf("Retour non attendu. Doit tre une erreur execv\n");
	}
	return 0;
}