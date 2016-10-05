#include <stdio.h>

int main() {
	int i, n = 158340421;

	for (i = 0; i * i * i < n; i++) ;

	if (i * i * i == n) {
		printf("%d\n", i);
	}

	return 0;
}
