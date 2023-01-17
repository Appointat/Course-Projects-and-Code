 /*ex3b.c: Lecture de données avec sacnf()*/

#include<stdio.h>

int main()
{
  int i1, i2, i3;
  float r1, r2, r3;
  char c1, c2, c3;
  char s1[10], s2[10], s3[10];
  char s4[4], s5[4], s6[4];

  printf("Entrez trois nombres décimaux :  ");
  scanf("%d%d%d",&i1, &i2, &i3);
  printf("Vous avez entré : %d %d %d\n", i1, i2, i3);

  printf("Entrez trois nombres décimaux :  ");
  scanf("%4f%4f%4f",&r1, &r2, &r3);
  printf("Vous avez entré : %f %f %f\n", r1, r2, r3);

  /* Lecture des chaines de caractères */
 
  printf("Entrez du texte :  ");
  scanf("%s%s%s",s1, s2, s3);
  printf("s1=|%s| s2=|%s| s3=|%s| \n", s1, s2, s3);
  getchar();
  //setbuf(stdin, NULL);
  scanf("%c%c%c",&c1, &c2, &c3);
  printf("c1='%c' c2='%c' c3='%c' \n", c1, c2, c3);

  printf("Entrez du texte :  ");
  getchar();
  // char c = getchar();
  // while(c != EOF && c != '\n') c = getchar();
  scanf("%4c%4c%4c",s4, s5, s6);
  printf("s4=|%.4s| s5=|%.4s| s6=|%.4s| \n", s4, s5, s6);
}
