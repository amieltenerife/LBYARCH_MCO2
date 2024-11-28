#include<stdio.h>
#include<stdlib.h>
#include<time.h>

extern double dotprod(int n, double* vector1, double* vector2);

int main() {
	int n = 5;
	int i;

	double* A = (double*)malloc(n * sizeof(double));
	double* B = (double*)malloc(n * sizeof(double));

	if (!A || !B) {
		perror("Failed to allocate memory");
		return EXIT_FAILURE;
	}

	for (i = 0; i < n; i++) {
		scanf("%lf", &A[i]);
	}

	for (i = 0; i < n; i++) {
		scanf("%lf", &B[i]);
	}

	clock_t start_time = clock();
	double sdot = dotprod(n, A, B);
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	printf("sdot: %.2f\n", sdot);
	printf("time: %.6f\n\n", elapsed_time);

	free(A);
	free(B);
	
	return 0;
}