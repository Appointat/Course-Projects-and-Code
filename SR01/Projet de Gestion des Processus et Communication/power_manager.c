#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void power_manager(int argc, char** argv) {
	sleep(1);

	kill(getpid(), SIGUSR2);
}

int main (int argc, char** argv) {
	power_manager(argc, argv);
	return 0;
}

