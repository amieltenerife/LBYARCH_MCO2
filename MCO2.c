#include<stdio.h>

extern double dotprod(int n, double* vector1, double* vector2);

int main() {
	double vector1[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
	double vector2[] = {11.11, 12.12, 13.13, 14.14, 15.15, 16.16, 17.17, 18.18, 19.19, 20.20};
	int n = 10;
	
	double sdot = dotprod(n, vector1, vector2);
	
	printf("%.2f", sdot);
	
	return 0;
}