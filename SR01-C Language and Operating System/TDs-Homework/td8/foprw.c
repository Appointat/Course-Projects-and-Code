/* fop.c -- demo fopen fread ... */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 80

int main()
{ 
	FILE * fa, *fin, *fout;
 	char buf[MAX_STRING_LENGTH+1];
 	char buf_in[MAX_STRING_LENGTH+1];
 	char buf_out[MAX_STRING_LENGTH+1];
 	int n;
	fa = fopen("fop.txt","a+");
	if (fa==NULL) {
		perror("fop erreur :");
		exit(0);
	}
	fin = fopen("fop_in.txt", "a+");
	fout = fopen("fop_out.txt", "a+");
	
	
	n = fread(buf, 1, MAX_STRING_LENGTH, fa);
	buf[n]='\0'; // buf from fop
	n = fread(buf_in,1, MAX_STRING_LENGTH,fin); // 
	if (n!=MAX_STRING_LENGTH) {
		perror("read");
	}
	buf_in[n]='\0';
	
	printf ("n=%d => \n%s\n\n",n,buf);
		
	int i, k = 0, m = 0;
	
	for (i=0; i<n; i++) {
		if (buf_in[i]=='\n') {
			while(buf[k]!='\n') {
				buf_out[i+k-m] = buf[k];
				k ++;
			}
			buf_out[i+k-m] = buf_in[i];
			m ++;
			k ++;
		} else {
			buf_out[i+k-m] = buf_in[i];
		}
	}
	buf_out[i+k-m] = '\0';
	printf ("n=%d => \n%s",n,buf_out);
	n = fwrite (buf_out,1,MAX_STRING_LENGTH,fout);
	if (n!=8) {
		//	perror("write"); 
	}
	fclose(fa);
}
