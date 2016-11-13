#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inverse(double**);

int main(int argc, char **argv) {
	int i;
	double **in;

	if (argc < 5) {
		puts("Insufficient arguments");
		return 1;
	}

	in = (double **)malloc(2 * sizeof(double*));
	in[0] = (double *)malloc(2 * sizeof(double));
	in[1] = (double *)malloc(2 * sizeof(double));

	for (i = 0; i < 4; i++) {
		in[i / 2][i % 2] = atof(argv[i + 1]);
	}

	inverse(in);

	printf("{{%f, %f}, {%f, %f}}\n", in[0][0], in[0][1], in[1][0], in[1][1]);

	return 0;
}

void inverse(double **matrix) {
	double factor;
	double a, b, c, d;

	a = matrix[0][0];
	b = matrix[0][1];
	c = matrix[1][0];
	d = matrix[1][1];

	factor = a * d - b * c;

	matrix[0][0] = d / factor;
	matrix[0][1] = - b / factor;
	matrix[1][0] = - c / factor;
	matrix[1][1] = a / factor;

	return;
}
