#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
	int i;
	double *data;
	double mean, variance, sum = 0.0f, variance_sum = 0.0f;

	data = (double *)malloc((argc - 1) * sizeof(double));

	for (i = 1; i < argc; i++) {
		data[i] = atof(argv[i]);
		sum += data[i];
	}

	if (argc > 1) {
		mean = sum / (double)(argc - 1);

		for (i = 1; i < argc; i++) {
			variance_sum += (data[i] - mean) * (data[i] - mean);
		}

		variance = variance_sum / (double)(argc - 1);

		printf("mean = %f, variance = %f\n", mean, variance);
	}

	return 0;
}
