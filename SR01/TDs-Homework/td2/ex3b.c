#include<stdio.h>

typedef struct {
	float x;
	float y;
} complexe;

void Afficher(complexe c) {
	if (c.y<0) printf("%f - %fi\n", c.x, -c.y);
	else if (c.y==0) printf("%f\n", c.x);
	else printf("%f + %fi\n", c.x, c.y);
}

complexe Somme(complexe a, complexe b) {
	complexe c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	
	return c;
}

complexe Produit(complexe a, complexe b) {
	complexe c;
	c.x = a.x * b.x - a.y * b.y;
	c.y = a.x * b.y + a.y * b.x;
	
	return c;
}

int main () {
	complexe a, b;
	a.x = 1;
	a.y = 2;
	b.x = 2;
	b.y = -2;
	
	printf("SOMME : ");
	Afficher(Somme(a, b));
	
	printf("PRODUIT : ");
	Afficher(Produit(a, b));
	return 0;
}
