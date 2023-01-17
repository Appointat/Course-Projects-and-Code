#include<stdio.h>

void mystrupdown(char *s1, char *s2) {
	int tmp;
	int i = 0;
	while (s1[i] != '\0') {
		if (s1[i]-'a'>=0&&'z'-s1[i]>=0) {
			tmp = s1[i] - 'a';
			s2[i] = tmp + 'A';
		} else {
			tmp = s1[i] - 'A';
			s2[i] = tmp + 'a';
		}
		i ++;
	}
}

void mystrchv(char *s1, char *s2) {
	int n, i;
	i = 0;
	while (s1[i++] != '\0') n ++;
	for (i=0; i<n; i++) {
		s2[i] = s1[n-1-i];
	}
}

int mystrchn(char *s, char c) {
	int count = 0;
	int i = 0;
	while(s[i] != '\0') {
		if (s[i] == c) {
			count ++;
		}
		i ++;
	}
	
	return count;
}

void mystrncpy(char *s1, char *s2, int n) {
	int len = 0;
	int i = 0;
	while (s1[i++] != '\0') len ++;
	
	for (i=0; i<n; i++) {
		s2[i] = s1[len - n + i];
	}	
}


void mystrncat(char *s1, char *s2, int n) {
	int len = 0;
	int i = 0;
	while (s1[i++] != '\0') len ++;
	
	int len2 = 0;
	while (s2[len2++] != '\0');
	
	for (i=0; i<n; i++) {
		s2[len2 + i] = s1[len - n + i];
	}
}
