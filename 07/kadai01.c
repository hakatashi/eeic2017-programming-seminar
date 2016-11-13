#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#ifndef NAME_MAX
#define NAME_MAX 1024
#endif

#ifndef MAX
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#endif

#ifndef MIN
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#endif

int main(int argc, char **argv) {
	int i, age;
	int age_max = -INT_MAX, age_min = INT_MAX, age_sum = 0, age_var = 0;
	double height_max = -DBL_MAX, height_min = DBL_MAX, height_sum = 0.0f, height_var = 0.0f;
	double weight_max = -DBL_MAX, weight_min = DBL_MAX, weight_sum = 0.0f, weight_var = 0.0f;
	int cnt = 0;
	double height, weight;
	char *filename, name[NAME_MAX];
	FILE *file;

	filename = argv[1];

	if ((file = fopen(filename, "r")) == NULL) {
		printf("Cannot open %s\n", filename);
		return 1;
	}

	while (fscanf(file, "%[^,],%d,%lf,%lf\n", name, &age, &height, &weight) != EOF) {
		age_sum += age;
		height_sum += height;
		weight_sum += weight;

		age_var += age * age;
		height_var += height * height;
		weight_var += weight * weight;

		age_max = MAX(age_max, age);
		height_max = MAX(height_max, height);
		weight_max = MAX(weight_max, weight);

		age_min = MIN(age_min, age);
		height_min = MIN(height_min, height);
		weight_min = MIN(weight_min, weight);

		cnt++;
	}

	printf("Age : (max,min,mean,stdev) = %d, %d, %f, %f\n", age_max, age_min, (double)age_sum / (double)cnt, ((double)age_var - (double)age_sum * (double)age_sum / (double)cnt) / (double)cnt);
	printf("Height : (max,min,mean,stdev) = %f, %f, %f, %f\n", height_max, height_min, height_sum / cnt, (height_var - height_sum * height_sum / cnt) / cnt);
	printf("Weight : (max,min,mean,stdev) = %f, %f, %f, %f\n", weight_max, weight_min, weight_sum / cnt, (weight_var - weight_sum * weight_sum / cnt) / cnt);

	fclose(file);

	return 0;
}
