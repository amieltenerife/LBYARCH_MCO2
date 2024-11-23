#include<stdio.h>
#include<stdlib.h>

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
	double* vector1 = malloc(size20 * sizeof(double));
	double* vector2 = malloc(size20 * sizeof(double));
	double sum = 0;
	int i;
	
	if (!vector1 || !vector2) {
		perror("Failed to allocate memory");
		return EXIT_FAILURE;
	}
	
	read_vector("vector1.bin", vector1, size20);
	read_vector("vector2.bin", vector2, size20);
	
	for (i = 0; i < size20; i++) {
		sum += vector1[i] * vector2[i];
	}
	
	printf("sdot (20): %.2f\n", sum);
	
	free(vector1);
	free(vector2);

	vector1 = malloc(size24 * sizeof(double));
	vector2 = malloc(size24 * sizeof(double));
	sum = 0;

	if (!vector1 || !vector2) {
		perror("Failed to allocate memory");
		return EXIT_FAILURE;
	}
	
	read_vector("vector1_large.bin", vector1, size24);
	read_vector("vector2_large.bin", vector2, size24);
	
	for (i = 0; i < size24; i++) {
		sum += vector1[i] * vector2[i];
	}
	
	printf("sdot (24): %.2f", sum);
	
	free(vector1);
	free(vector2);
	
	return 0;
}