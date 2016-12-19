#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#ifndef MAX_BUF
#define MAX_BUF 2048
#endif

int main(int argc, char **argv) {
	char *input_filename, *output_filename, buf[MAX_BUF];
	int width, height, temp_int;
	double noise_ratio;
	FILE *infile, *outfile;
	bool **image;

	if (argc != 4) {
		printf("Usage: %s [input] [outut] [noise ratio]", argv[0]);
		return 1;
	}

	input_filename = argv[1];
	output_filename = argv[2];
	noise_ratio = atof(argv[3]);

	srand((unsigned)time(NULL));

	if ((infile = fopen(input_filename, "r")) == NULL) {
		printf("Cannot open %s\n", input_filename);
		return 1;
	}

	fscanf(infile, "%s", buf); // "P1"
	fscanf(infile, "%d %d", &width, &height);

	image = (bool**)malloc(sizeof(bool*) * height);

	for (size_t y = 0; y < height; y++) {
		image[y] = (bool*)malloc(sizeof(bool) * width);

		for (size_t x = 0; x < width; x++) {
			fscanf(infile, "%d", &temp_int);

			if (temp_int == 1) {
				image[y][x] = true;
			} else {
				image[y][x] = false;
			}
		}
	}

	fclose(infile);

	for (size_t y = 0; y < height; y++) {
		for (size_t x = 0; x < width; x++) {
			if (rand() < (double)RAND_MAX * noise_ratio) {
				image[y][x] = !image[y][x];
			}
		}
	}

	if ((outfile = fopen(output_filename, "w")) == NULL) {
		printf("Cannot open %s\n", output_filename);
		return 1;
	}

	fprintf(outfile, "P1\n");
	fprintf(outfile, "%d %d\n", width, height);

	for (size_t y = 0; y < height; y++) {
		for (size_t x = 0; x < width; x++) {
			fprintf(outfile, "%c ", image[y][x] ? '1' : '0');
		}

		fprintf(outfile, "\n");
	}

	fclose(outfile);

	return 0;
}
