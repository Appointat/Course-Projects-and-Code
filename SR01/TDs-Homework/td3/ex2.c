#include<stdio.h>

int main() {
	char *jour[7] = {"lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche"};
	
	int premier_Jour, date;
	printf("Donner l'indice du premier jour du mois : ");
	scanf("%d", &premier_Jour);
	printf("Donner la date : ");
	scanf("%d", &date);
	
	int indice_Jour = (premier_Jour + date - 1)%7;
	printf("le %d est un ", date);
	int i = 0;
	while(jour[indice_Jour][i] != '\0') {
		printf("%c", jour[indice_Jour][i]);
		i++;
	}
	printf("\n");
	
	return 0;
}
