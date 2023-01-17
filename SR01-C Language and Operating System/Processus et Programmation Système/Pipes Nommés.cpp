#include <fcntl.h>
#include <signal.h> /* sigaction... */
#include <sys/types.h> /* Types pid_t... */
#include <unistd.h> /* fork()... */
#include <stdio.h> /* printf... */
#include <stdlib.h> /* EXIT_FAILURE... */
#define PIPE "fifo"


// Serveur.c
int main() {
	int fd; char readbuf[20];
	mknod(PIPE, S_IFIFO | 0660, 0); // cration du pipe
	fd = open(PIPE, O_RDONLY, 0); // ouvrir le pipe
	for (;;) {
		if (read(fd, &readbuf, sizeof(readbuf)) < 0) { // lire du pipe
			perror("Error reading pipe"); exit(1);
		}
		printf("Received string: %s\n", readbuf);
	}
	exit(0);
}

// Client.c
#include <signal.h> /* sigaction... */
#include <sys/types.h> /* Types pid_t... */
#include <unistd.h> /* fork()... */
#include <stdio.h> /* printf... */
#include <stdlib.h> /* EXIT_FAILURE... */
#define PIPE fifo

int main() {
	int fd;
	char writebuf[20] = Hello; // ouvrir le pipe
	fd = open(PIPE, O_WRONLY, 0); // crire dans le pipe
	write(fd, writebuf, sizeof(writebuf));
	exit(0);
}