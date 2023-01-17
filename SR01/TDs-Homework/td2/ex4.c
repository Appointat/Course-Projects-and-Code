#include<stdio.h>

typedef struct {
	float x;
	float y;
} Complexe;
typedef union {
	int entier; 
	float reel; 
	Complexe complexe;
} valeur;
typedef enum {entier=1, reel, complexe} genre;
typedef struct {genre g; valeur v;} nombre;

void Afficher(Complexe c) {
	if (c.y<0) printf("%f - %fi\n", c.x, -c.y);
	else if (c.y==0) printf("%f\n", c.x);
	else printf("%f + %fi\n", c.x, c.y);
}

nombre Saisir_Nombre() {
	nombre n;
	printf("Quel type de nombre ? (1.entier, 2.reel ou 3.complexe)\n");
	while (1) {
		scanf("%u", &n.g);
		if (n.g!=1 && n.g!=2 && n.g!=3){ 
			printf("Type erreur, veuillez le saisir à nouveau (1.entier, 2.reel ou 3.complexe).\n"); 
			continue;
		}
		break;
	}

	printf("Quel est la valeur du nombre?\n");
	if (n.g == entier) scanf("%d", &n.v.entier);
	else if(n.g == reel) scanf("%f", &n.v.reel);
	else scanf("%f %f", &n.v.complexe.x, &n.v.complexe.y);
	return n;
}

void Afficher_Nombre(nombre n) {
	if (n.g == 1) printf("entier : %d\n", n.v.entier);
	else if (n.g == 2) printf("reel : %lf\n", n.v.reel);
	else {
		printf("complexe : ");
		Afficher(n.v.complexe);
	}
}


int main () {
	nombre n = Saisir_Nombre();
	Afficher_Nombre(n);
	return 0;
}
