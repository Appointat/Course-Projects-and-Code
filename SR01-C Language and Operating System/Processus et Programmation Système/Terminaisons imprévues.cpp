#include <signal.h> /* sigaction... */
#include <stdio.h> /* printf... */
#include <stdlib.h> /* EXIT_FAILURE... */
#include <sys/types.h> /* Types pid_t... */
#include <unistd.h>

pid_t pid;
void terminer(void) {
	printf("\nTerminaison du processus %d", pid);
}

void quitter(void) {
	printf("\nFin\n");
	exit(EXIT_SUCCESS);
}

void intercepter(int n) { // intercepter×è¸ô
	int i;
	printf("\nRception du signal %d (INT = %d, TERM = %d, QUIT = %d)", 
			n, SIGINT, SIGTERM, SIGQUIT);

	switch (n) {
	case SIGTERM: terminer();
	case SIGINT:
	case SIGQUIT: quitter();
	}
	printf("\nFin du handler");
}

int main(int argc, char** argv) {
	int i;
	struct sigaction S;
	// int argc = 2;
	// char * argv[2] = {"main.c", "5"};
	if (argc < 2) {
		printf("\n Usage : %s delais\n", argv[0]);
		return EXIT_SUCCESS;
	}
	pid = getpid();
	S.sa_handler = intercepter;
	if (sigaction(SIGTERM, &S, NULL) != 0 || \
		sigaction(SIGQUIT, &S, NULL) != 0 || \
		sigaction(SIGINT, &S, NULL) != 0) {
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	for (i = atoi(argv[1]); i > 0; i--) {
		printf("\nLe processus %d est vivant pour encore %d s.", pid, i);
		fflush(stdout);
		sleep(1);
	}
	return EXIT_SUCCESS;
}


/*
Output:

	Le processus 1029 est vivant pour encore 5 s.
	Le processus 1029 est vivant pour encore 4 s.
	Le processus 1029 est vivant pour encore 3 s.
	Le processus 1029 est vivant pour encore 2 s.
	Le processus 1029 est vivant pour encore 1 s.
*/