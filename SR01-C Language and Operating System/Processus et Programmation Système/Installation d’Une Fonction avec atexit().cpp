#include <sys/types.h> /* Types pid_t... */
#include <unistd.h> /* fork()... */
#include <stdio.h> /* printf... */
#include <stdlib.h> /* EXIT_FAILURE... */

void terminer(void) {
	printf("\nTerminaison du processus %d (fonction \"terminer\")", pid);
}

void quitter(void) {
	printf("\nFin (fonction \"quitter\")\n");
}

int main(int argc, char** argv) {
	int i;
	// int argc = 2;
	// char* argv[2] = { "main.c", "5" };
	if (argc < 2) {
		printf("\n Usage : %s delais\n", argv[0]);
		return EXIT_SUCCESS;
	}

	pid = getpid();
	if (atexit(quitter) != 0 || atexit(terminer) != 0) {
		perror("main/atexit");
		return EXIT_FAILURE;
	}
	for (i = atoi(argv[1]); i > 0; i--) {
		printf("\nLe proc. %d vivant pour encore %d s.", pid, i);
		fflush(stdout);
		sleep(1);
	}
	return EXIT_SUCCESS;
}

/*
Input: main.c 5 (in terminal)
Output:

	Le proc. 222 vivant pour encore 5 s.
	Le proc. 222 vivant pour encore 4 s.
	Le proc. 222 vivant pour encore 3 s.
	Le proc. 222 vivant pour encore 2 s.
	Le proc. 222 vivant pour encore 1 s.
	Terminaison du processus 1111 (fonction "terminer")
	Fin (fonction "quitter")

*/