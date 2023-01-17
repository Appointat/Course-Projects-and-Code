#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
	pid_t pid = getpid();
	pid_t ppid = getppid();
	printf("Mon pid : %d\n", (int) pid);
	printf("Pere pid : %d\n", (int) ppid);
	
	pid_t uid = getuid();
	pid_t id = getgid();
	return 0;
}
