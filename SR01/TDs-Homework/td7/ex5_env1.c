#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
	char var[50] , ex[50], *result;
	//var="SR01TD1=un_example_de_var_env_mofif";
	printf("nom variable :");
	scanf("%s",var);
	
	result=getenv(var);
	if(result!=NULL)
	{
		printf("notre variable initiale est %s\n", result);
	
		strcpy(ex,var);
		strcat(ex,"=val_modif");
		//printf("notre variable initiale est %s\n", getenv("SR01TD1"));
		putenv(ex);
		//printf("notre variable modifier est %s\n", getenv("SR01TD1"));
		printf("notre variable modifier est %s\n", getenv(var));
	}
	else printf("\n c'est pas une variable d'env \n");	
	
	return 0;
}
