#include <stdio.h>
#include <unistd.h>

int main() {
	int pid, pip[2];
	char instring[20];

	pipe(pip);
	pid = fork();
	if (pid == 0) // fils: envoie un message a son parent
		write(pip[1], "Salut !", 7); // envoyer un message
	else // parent : reoit le message envoy par le fils
		read(pip[0], instring, 7); // lire partir du pipe

	return 0;
}