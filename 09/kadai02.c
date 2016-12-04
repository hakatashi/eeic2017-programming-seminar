#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef NAME_MAX
#define NAME_MAX 20
#endif

struct person {
	char name[NAME_MAX];
	int age;
	double weight;
	double height;
	struct person *next;
};

int main(int argc, char **argv) {
	int i, age;
	double height, weight;
	char *filename, name[NAME_MAX];
	struct person *first_person = NULL, *previous_person = NULL, *temp_person;
	FILE *file;

	filename = argv[1];

	if ((file = fopen(filename, "r")) == NULL) {
		printf("Cannot open %s\n", filename);
		return 1;
	}

	while (fscanf(file, "%[^,],%d,%lf,%lf\n", name, &age, &height, &weight) != EOF) {
		temp_person = (struct person*)malloc(sizeof(struct person));
		strcpy(temp_person->name, name);
		temp_person->age = age;
		temp_person->height = height;
		temp_person->weight = weight;
		temp_person->next = NULL;

		if (first_person == NULL) {
			first_person = temp_person;
		}

		if (previous_person != NULL) {
			previous_person->next = temp_person;
		}

		previous_person = temp_person;
	}

	fclose(file);

	temp_person = first_person;

	while (temp_person != NULL) {
		printf("%s,%d,%lf,%lf\n", temp_person->name, temp_person->age, temp_person->height, temp_person->weight);
		temp_person = temp_person->next;
	}

	return 0;
}
