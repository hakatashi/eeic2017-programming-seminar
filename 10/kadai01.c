#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef NAME_MAX
#define NAME_MAX 20
#endif

#ifndef HASH_SIZE
#define HASH_SIZE 1000
#endif

struct person {
	char name[NAME_MAX];
	int age;
	double weight;
	double height;
	struct person *next;
};

int hash(char *data) {
	if (strlen(data) == 1) {
		srand(data[0]);
	} else {
		srand(data[0] + hash(data + 1));
	}

	return rand();
}

int main(int argc, char **argv) {
	int age, hash_index, input_hash;
	double height, weight;
	char *filename, name[NAME_MAX], input[NAME_MAX];
	struct person *temp_person, **member_pointer;
	struct person *members[HASH_SIZE] = {NULL};
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

		hash_index = hash(name) % HASH_SIZE;

		member_pointer = &(members[hash_index]);
		while (*member_pointer != NULL) {
			member_pointer = &((*member_pointer)->next);
		}

		*member_pointer = temp_person;
	}

	fclose(file);

	fgets(input, NAME_MAX, stdin);
	strtok(input, '\n');


	input_hash = hash(input) % HASH_SIZE;
	temp_person = members[input_hash];

	while (temp_person != NULL) {
		if (strcmp(temp_person->name, input) == 0) {
			printf("%s,%d,%lf,%lf\n", temp_person->name, temp_person->age, temp_person->height, temp_person->weight);
		}

		temp_person = temp_person->next;
	}

	return 0;
}
