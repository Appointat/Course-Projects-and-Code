#include<stdio.h>

typedef struct {
	float x;
	float y;
} complexe;

void Afficher(complexe c) {
	if (c.y<0) printf("%lf - %lfi\n", c.x, -c.y);
	else if (c.y==0) printf("%lf\n", c.x);
	else printf("%lf + %lfi\n", c.x, c.y);
}

int main() {
	complexe c;
	c.x = 1.2;
	c.y = -0.4;
	
	Afficher(c);
	return 0;
}
