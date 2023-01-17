#include<stdio.h>

int main (void) {
	int x = 10;
	int y, z;
	x *= y =z =4;
	printf("x = %d, y = %d, z = %d\n", x, y, z);
	// x = 40, y = 4, z = 4
	
	x = 2;
	y = 1;
	z = 0;
	z += -x ++ + ++y;
	printf("x = %d, y = %d, z = %d\n", x, y, z);
	// x = 3, y = 2, z = 0
	
	x = 3;
	z = 0;
	z = x / ++x;
	printf("x = %d, z = %d\n", x, z);
	// x = 4, z = 1
	
	x = 3; // 011
	y = 2; // 010
	z = 1; // 001
	int a = x | y & ~z; // 011 010 110 -> 011 010 -> 011
	int b = x ^ y & ~z; // 011 010 110 -> 011 010 -> 001 // 从右往左运算
	printf("a = %d, b = %d, x = %d, y = %d, z = %d\n", a, b, x, y, z);
	// a = 3, b = 1, x = 3, y = 2, z = 1
	
	x = 1;
	y = -1;
	a = ~x | x;
	y <<= 3;
	printf("a = %d, x = %d, y = %d\n", a, x, y);
	// a = -1, x = 1, y = -8
	
	x = 3;
	y = 2;
	a = x < y ? x++ : y++; // 从左向右,并且不运算未通过的公式
	printf("a = %d, x = %d, y = %d\n", a, x, y);
	// a = 2, x = 3, y = 3
	
	x = -1;
	y = -1;
	z = -1;
	a = ++x && ++y || ++z; // ++x && ++y ->  0 || ++ z 
	printf("a = %d, x = %d, y = %d, z = %d\n", a, x, y, z);
	// a = 0, x = 0, y = -1, z = 0
	return 0;
}
