#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

struct application {
  char *name; // 应用程序名称
  char *path; // 应用程序路径
  int argc; // 参数个数
  char **argv; // 参数列表
};
//全局变量，用以存储有多少个进程在运行
static int counter;
// 从文件中读取应用程序信息，并将它们存储在应用程序数组中，返回读取到的程序数量
int read_applications_from_file(const char *filename, struct application **apps)
{
	//打开这个司马文件
	FILE *fp=fopen(filename,"r");
	if(fp==NULL)
	{
		perror("fopen");
		return -1;
	}
	//读取应用程序的个数
	char buf[128];
	int nombre_applications; // 用于存储数字
	
	if(fgets(buf,sizeof(buf),fp)!=NULL)
	{
		sscanf(buf,"nombre_applications=%d",&nombre_applications);
	}
	else
	{
		perror("Error reading from file list!");
		exit(EXIT_FAILURE);
	}
	(*apps)=(struct application *)malloc(nombre_applications*sizeof(struct application));
    int i = -1;
    while(fgets(buf,sizeof(buf),fp)!=NULL)
    {
		if(strncmp(buf,"name=",5)==0)
		{
			// 读取应用程序名称信息
            ++i;
			char *name= strdup(buf+5);
			name[strlen(name)-1]='\0';//去掉换行符
			(*apps)[i].name=strdup(name);
			free(name);
		}
		else if(strncmp(buf,"path=",5)==0)
		{
			//读取应用程序路径
			char *path=strdup(buf+5);
			path[strlen(path)-1]='\0';
			(*apps)[i].path=strdup(path);
			free(path);
		}
		else if(strncmp(buf, "nombre_arguments=", 17)==0)
		{
			//读取应用程序参数个数
			(*apps)[i].argc=atoi(buf+17);
		}
		else if(strncmp(buf,"arguments=",10)==0)
		{
			if((*apps)[i].argc==0)
				continue;//读取到参数信息行并且参数个数为0，则继续while循环时会因为不满足while循环条件而退出，进入下一个应用程序信息的读取
			//如果参数个数不为0进入读取参数阶段
			(*apps)[i].argv=malloc(((*apps)[i].argc + 1) * sizeof(char *));//最后一位设为NULL
			(*apps)[i].argv[(*apps)[i].argc]=NULL;
			for(int j=0;j<(*apps)[i].argc;j++)
			{
				if(fgets(buf,sizeof(buf),fp)!=NULL)
				{
					char *argtemp=strdup(buf);
					argtemp[strlen(argtemp)-1]='\0';
					(*apps)[i].argv[j]=strdup(argtemp);
					free(argtemp);
				}
			}//理论上，在程序读取完参数列表之后，退出这个for循环会进入到while循环，而while会读取到换行符，因此可以实现最外层的for循环继续执行
		}
    }

	fclose(fp);
	return nombre_applications;
}


// 创建子进程来执行应用程序
int launch_application(struct application app)
{
	//创建子进程
	pid_t pid=fork();
	if(pid<0)
	{
		//创建进程失败
		perror("fork");
		return -1;
	}
	else if(pid == 0)
	{
		//在子进程中执行应用程序
		execv(app.path,app.argv);
		counter++;
		//如果执行到这里说明execv函数执行失败了
		perror("execv");
		exit(EXIT_FAILURE);
	}
	return pid;
}
// 在进程终止时输出信息
void print_exit_info(int sig, siginfo_t *info, void *ucontext)
{

	// 获取退出的子进程ID
	pid_t pid = info->si_pid;
	// 输出退出信息
	printf("Child with PID %d exited.\n", pid);

    	// 将计数器减1
	counter--;
}

// 在收到SIGUSR1信号时终止程序
void terminate(int sig)
{
	// 停止所有子进程
	kill(0, SIGKILL);
	// 结束进程
	exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	// 从文件中读取应用程序信息
	struct application *apps;
	if (argc != 2) 
	{
	fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
	return 1;
	}	
	int n = read_applications_from_file(argv[1], &apps);
	if (n < 0)
	{
	fprintf(stderr, "Error reading applications!\n");
	return EXIT_FAILURE;
	}
	
	// 为SIGUSR1信号设置信号处理函数
	struct sigaction act;
	act.sa_handler = terminate;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);

	// 为SIGCHLD信号设置信号处理函数
	struct sigaction act2;
	act2.sa_sigaction = print_exit_info;
	sigemptyset(&act2.sa_mask);
	act2.sa_flags = SA_SIGINFO;
	sigaction(SIGCHLD, &act2, NULL);	
	// 创建子进程执行应用程序
	pid_t pid[n];
	for (int i = 0; i < n; i++)
	{
	pid[i]=launch_application(apps[i]);
	if (pid[i]< 0)
	{
	fprintf(stderr, "Error launching application %s!\n", apps[i].name);
	return EXIT_FAILURE;
	}
	}

	//等待所有子进程终止
	while(1)
	{
	if(counter==0)
		break;
	pause();
	}
	return 0;
}

