#include <sys/types.h> /* Types pid_t... */
#include <unistd.h> /* fork()... */
#include <stdio.h> /* printf... */
#include <stdlib.h> /* EXIT_FAILURE... */
#define DURATION 15
int main()
{
	pid_t pid_fils; 
	int i;
	switch (pid_fils = fork()) {
		case (pid_t)-1: /* Retour du fork() = -1 => echec (eg. manque de ressources) */
			perror("main/fork");
			return EXIT_FAILURE;
		case (pid_t)0: /* Retour du fork() = 0 => processus fils */
			for (i = DURATION; i > 0; i--) {
				printf("Fils : je suis vivant pour encore %d secondes.\n", i);
				fflush(stdout); sleep(1);
			}
			return EXIT_SUCCESS;
		default: /* Retour du fork() != 0 donc c¡¯est le pere */
			for (i = DURATION; i > 0; i--) {
				printf("Pere : je suis vivant pour encore %d secondes.\n", i);
				fflush(stdout); sleep(1);
			}
	}
	return EXIT_SUCCESS;
}
/*
Explanation: the process father and the process son run concurrently.
Output:
	Pere : je suis vivant pour encore 15 secondes.
	Fils : je suis vivant pour encore 15 secondes.
	Pere : je suis vivant pour encore 14 secondes.
	Fils : je suis vivant pour encore 14 secondes.
	Pere : je suis vivant pour encore 13 secondes.
	Fils : je suis vivant pour encore 13 secondes.
	Pere : je suis vivant pour encore 12 secondes.
	Fils : je suis vivant pour encore 12 secondes.
	Pere : je suis vivant pour encore 11 secondes.
	Fils : je suis vivant pour encore 11 secondes.
	Pere : je suis vivant pour encore 10 secondes.
	Fils : je suis vivant pour encore 10 secondes.
	Pere : je suis vivant pour encore 9 secondes.
	Fils : je suis vivant pour encore 9 secondes.
	Pere : je suis vivant pour encore 8 secondes.
	Fils : je suis vivant pour encore 8 secondes.
	Pere : je suis vivant pour encore 7 secondes.
	Fils : je suis vivant pour encore 7 secondes.
	Pere : je suis vivant pour encore 6 secondes.
	Fils : je suis vivant pour encore 6 secondes.
	Pere : je suis vivant pour encore 5 secondes.
	Fils : je suis vivant pour encore 5 secondes.
	Pere : je suis vivant pour encore 4 secondes.
	Fils : je suis vivant pour encore 4 secondes.
	Pere : je suis vivant pour encore 3 secondes.
	Fils : je suis vivant pour encore 3 secondes.
	Pere : je suis vivant pour encore 2 secondes.
	Fils : je suis vivant pour encore 2 secondes.
	Pere : je suis vivant pour encore 1 secondes.
	Fils : je suis vivant pour encore 1 secondes.
*/




