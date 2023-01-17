#include <signal.h> /* sigaction... */
#include <sys/types.h> /* Types pid_t... */
#include <unistd.h> /* fork()... */
#include <stdio.h> /* printf... */
#include <stdlib.h> /* EXIT_FAILURE... */
#define CODE_RETOUR_FILS 4
pid_t pid, pid_fils;

void intercepter(int n) {
	printf("Proc %d : rception du signal %d (SIGCLD=%d)\n\n", pid, n, SIGCLD);
}

int main(int argc, char** argv) {
	int i, delais_fils, delais_pere;
	struct sigaction S;
	if (argc < 3)
	{
		printf("\n Usage : %s delais_fils delais_pere\n", argv[0]);
		return EXIT_SUCCESS;
	}

	delais_fils = atoi(argv[1]);
	delais_pere = atoi(argv[2]);
	S.sa_handler = intercepter;
	pid = getpid();
	if (sigaction(SIGCHLD, &S, NULL) != 0) {
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	switch (pid_fils = fork()) {
	case (pid_t)-1: /* echec (eg. manque de ressources) */
		perror("main/fork");
		return EXIT_FAILURE;
	case (pid_t)0: /* Retour du fork() = 0 => processus fils */
		pid = getpid();
		for (i = delais_fils; i > 0; i --) {
			printf("Le fils %d:vivant pour encore %d secondes.\n", pid, i);
			fflush(stdout); sleep(1);
		}
		return CODE_RETOUR_FILS;
	default: /* Retour du fork() != 0 donc c¡¯est le pere */
		for (i = delais_pere; i > 0; i --) {
			printf("Le pere %d:vivant pour encore %d secondes.\n", pid, i);
			fflush(stdout); sleep(1);
		}
	}
	printf("\n"); 
	return EXIT_SUCCESS;
}

/*
Input: main.c 3 6
Output:
	 Le pere 65:vivant pour encore 6 secondes.
	 Le fils 69:vivant pour encore 3 secondes.
	 Le pere 65:vivant pour encore 5 secondes.
	 Le fils 69:vivant pour encore 2 secondes.
	 Le pere 65:vivant pour encore 4 secondes.
	 Le fils 69:vivant pour encore 1 secondes.
	 Le pere 65:vivant pour encore 3 secondes.
	 Proc 65 : rception du signal 17 (SIGCLD=17)

	 Le pere 65:vivant pour encore 2 secondes.
	 Le pere 65:vivant pour encore 1 secondes.

*/