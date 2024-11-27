#include<stdio.h>
#include<stdlib.h>
#include<time.h>

extern double dotprod(int n, double* vector1, double* vector2);

void read_vector(const char* filename, double* vector, size_t size) {
	FILE* file = fopen(filename, "rb");
	if (!file) {
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}
	
	fread(vector, sizeof(double), size, file);
	fclose(file);
}

int main() {
	size_t size20 = 1 << 20;
	size_t size24 = 1 << 24;
	size_t size29 = 1 << 29;

	double* vector1 = malloc(size20 * sizeof(double));
	double* vector2 = malloc(size20 * sizeof(double));

	if (!vector1 || !vector2) {
		perror("Failed to allocate memory");
		return EXIT_FAILURE;
	}
	
	read_vector("vector1.bin", vector1, size20);
	read_vector("vector2.bin", vector2, size20);

	clock_t start_time = clock();
	double sdot = dotprod(size20, vector1, vector2);
	clock_t end_time = clock();
	double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

	printf("sdot (20): %.2f\n", sdot);
	printf("elapsed time: %.4f seconds\n\n", elapsed_time);

	free(vector1);
	free(vector2);

	vector1 = malloc(size24 * sizeof(double));
	vector2 = malloc(size24 * sizeof(double));

	if (!vector1 || !vector2) {
		perror("Failed to allocate memory");
		return EXIT_FAILURE;
	}

	read_vector("vector1_large.bin", vector1, size24);
	read_vector("vector2_large.bin", vector2, size24);
	
	start_time = clock();
	sdot = dotprod(size24, vector1, vector2);
	end_time = clock();
	elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	
	printf("sdot (24): %.2f\n", sdot);
	printf("elapsed time: %.4f seconds\n\n", elapsed_time);
	
	free(vector1);
	free(vector2);

	vector1 = malloc(size29 * sizeof(double));
	vector2 = malloc(size29 * sizeof(double));

	if (!vector1 || !vector2) {
		perror("Failed to allocate memory");
		return EXIT_FAILURE;
	}

	read_vector("vector1_largest.bin", vector1, size29);
	read_vector("vector2_largest.bin", vector2, size29);
	
	start_time = clock();
	sdot = dotprod(size29, vector1, vector2);
	end_time = clock();
	elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	
	printf("sdot (29): %.2f\n", sdot);
	printf("elapsed time: %.4f seconds\n", elapsed_time);
	
	return 0;
}