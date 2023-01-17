#include<stdio.h>
#include<math.h>

int jeu_ordi (int nb_allum, int prise_max)
{
	int prise = 0;
	int s = 0;
	float t = 0;
	s = prise_max + 1;
	t = ((float) (nb_allum - s)) / (prise_max + 1);
	while (t != floor (t)) {
		s--;
		t = ((float) (nb_allum-s)) / (prise_max + 1);
	}
	prise = s - 1;
	if (prise == 0)
		prise = 1;
	
	return (prise);
}

void afficher_allumettes(int n) {
	int i;
	for (i=0; i<n; i++) printf("o  ");
	printf("\n");
	for (i=0; i<n; i++) printf("1  ");
	printf("\n");
}

int main() {
	int nb_max_d = 20; /*nbre d'allumettes maxi au départ*/
	int nb_allu_max = 3; /*nbre d'allumettes maxi qu'on peut tirer au maxi*/
	int qui= 0; /*qui joue? 0=Nous --- 1=PC*/
	int prise= 0; /*nbre d'allumettes prises par le joueur*/
	int nb_allu_rest = 0; /*nbre d'allumettes restantes*/
	
	nb_allu_rest = nb_max_d;
	while(nb_allu_rest) {
		afficher_allumettes(nb_allu_rest);
		if (qui) {
			nb_allu_rest -= jeu_ordi(nb_allu_rest, nb_allu_max);
			printf("L'ordinateur : %d\n", jeu_ordi(nb_allu_rest, nb_allu_max));
			qui = 0;
		} else {
			printf("Le jouer :\n");
			scanf("%d", &prise);
			while (prise>nb_allu_max) {
				printf("> nb_allu_max, le jouer :\n");
				scanf("%d", &prise);
			}
			nb_allu_rest -= prise;
			qui = 1;
		}
		printf("\n");
	}
	
	printf("\n");
	if (qui)
		printf("Ganant : ordinateur\n");
	else
		printf("Ganant : jouer\n");
		
	return 0;
}
