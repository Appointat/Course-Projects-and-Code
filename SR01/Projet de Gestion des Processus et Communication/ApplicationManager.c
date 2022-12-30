#include <stdio.h>#include <stdlib.h>#include <unistd.h>#include <signal.h>#include <sys/types.h>#include <sys/wait.h>#include <string.h>struct Application {	char* name;	char* path;	int argc;	char* argv[127];} *apps_ptr[20];int n_app = 0;pid_t pids[50];char* name_glo;void ApplicationManager();void ReadApplication(char* filename);void LancerApplication(char* path);void ArreterApplication(char* name);void handler(int signo);void InformerUtilisateur(char* name);void power_manager() {	sleep(1);	//kill(getpid(), SIGUSR2);}int main(int argc, char** argv) {	ApplicationManager();	return 0;}void ReadApplication(char* filename) {	FILE* fp = fopen(filename, "r"); // open file	if (fp == NULL) {		printf("%s\n", filename);		perror("fopen error\n");		exit(EXIT_FAILURE);	}	char buf[127]; // variable temporaire	if (fgets(buf, sizeof(buf), fp) == NULL) { // number d'applications		perror("error reading from list_appli\n");		exit(EXIT_FAILURE);	} else {		sscanf(buf, "nombre_applications=%d", &n_app);	}	int i = 0;	while (fgets(buf, sizeof(buf), fp) != NULL) {		if (strncmp(buf, "name=", 5) == 0) { // name			char* name;			// struct Application app;			strcpy(name, buf + 5);			name[strlen(name) - 1] = '\0';			strcpy((*apps_ptr)[i].name, name);			i ++;		} else if (strncmp(buf, "path=", 5) == 0) { // path			char* path;			strcpy(path, buf + 5);			path[strlen(path) - 1] = '\0';			strcpy((*apps_ptr)[i].path, path);		} else if (strncmp(buf, "nombre_arguments=", 17) == 0) { // argc			(*apps_ptr)[i].argc = atoi(buf + 17);		} else if (strncmp(buf, "arguments=", 10) == 0) { // argv			if ((*apps_ptr)[i].argc > 0) {				int j;				for (j = 0;j < (*apps_ptr)[i].argc; j++) {					if (fgets(buf, sizeof(buf), fp) != NULL) {						char* arg_tmp;						strcpy(arg_tmp, buf);						arg_tmp[strlen(arg_tmp) - 1] = '\0';						strcpy((*apps_ptr)[i].argv[j], arg_tmp);					}				}			}		}	}	fclose(fp);}void LancerApplication(char* filename) {	// Lire des application dans 'filename'	ReadApplication(filename);		// system() et fork()	int i;	for (i = 0; i < n_app; i++) {		struct sigaction S;		S.sa_handler = handler;		if (sigaction(SIGUSR1, &S, NULL) == -1) {			perror("signal error\n");			exit(EXIT_FAILURE);		}		if (sigaction(SIGUSR2, &S, NULL) == -1) {			perror("signal error\n");			exit(EXIT_FAILURE);		}		char *chaine;		char *chaine_argv;		pids[i] = fork();		switch (pids[i]) {		case -1:			perror("fork error\n");			exit(EXIT_FAILURE);		case 0: // Exécuter une application pendant run_time seconde			sprintf(chaine, "./%s", (*apps_ptr)[i].name);			int j;			for (j = 0; j < (*apps_ptr)[j].argc; j++) {				sprintf(chaine_argv, " %s", (*apps_ptr)[i].argv[j]);				strcat(chaine, chaine_argv);			}			system(chaine); // Exécuter			sleep(1);			name_glo = (*apps_ptr)[i].name;			if (kill(getpid(), SIGUSR1) == -1) {				perror("kill error\n");				exit(EXIT_FAILURE);			}			kill(getpid(), SIGKILL);			// exit(0);		default: // main branche			sleep(2);			break;		}	}}void ArreterApplication(char* name) {	InformerUtilisateur(name); // informer l’utilisateur en lui affichant le nom de l’application terminée	if (n_app == 1) {		printf("FIN : Toutes les applications sont fermées.\n");		exit(0);	}	int i = 0;	int flag = 0;	for (; i < n_app; i++) {		if (strcmp(name, (*apps_ptr)[i].name) == 0) {			(*apps_ptr)[i].name[0] = '\0';			break;		}	}	n_app--;}void handler(int signo) {	int i;	switch (signo) {	case SIGUSR1: // father		ArreterApplication(name_glo);		break;	case SIGUSR2: // child		for (i=1; i<n_app; i++) {			ArreterApplication((*apps_ptr)[i].name);			kill(pids[i], SIGKILL);		}		break;	default:		perror("handler error\n");		exit(EXIT_FAILURE);		break;	}}void InformerUtilisateur(char* name) {	printf("L'application '%s' est fermée", name);}/** Créer un ensemble de processus fils chacun est responsable à l’exécution d’une application,* Lors de l’arrêt d’une application, informer l’utilisateur en lui affichant le nom de l’application terminée* s’arrêter après avoir fermé toutes les applications en cours d’exécution lors de la réception d’un ordre de mise en veille de la part de power_manager (signal SIGUSR1)*/void ApplicationManager() {	char* filename = "list_appli.txt";	LancerApplication(filename);	while (1) {		sleep(1);	}}