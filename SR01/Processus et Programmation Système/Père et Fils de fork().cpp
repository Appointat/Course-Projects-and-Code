#include <unistd.h>
#include <stdio.h> 

int main()
{
	pid_t fpid; //fpid表示fork函数返回的值
	int count = 0;
	fpid = fork();
	if (fpid < 0) {
		printf("error in fork!");
	} else if (fpid == 0) {
		printf("I am the child process, my process id is %d\n", getpid());
		count++;
	} else {
		printf("I am the parent process, my process id is %d\n", getpid());
		count++;
	}

	printf("The resualt of the count: %d\n", count);
	return 0;
}
/*
Output:
	I am the parent process, my process id is 1468
	The resualt of the count: 1
	I am the child process, my process id is 1472
	The resualt of the count: 1
*/


