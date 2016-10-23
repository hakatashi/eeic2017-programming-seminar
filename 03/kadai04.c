#include <stdio.h>
#include <stdlib.h>

void factorize(int, int);

void main() {
	int n = 123456789;
	printf("Prime factor of %d\n", n);
	printf("%d = ", n);
	factorize(n, 2);
}

void factorize(int n, int factor) {
	int i;

	for (i = factor; i * i <= n; i++) {
		if (n % i == 0) {
			printf("%d * ", i);
			factorize(n / i, i);
			return;
		}
	}

	printf("%d\n", n);
	return;
}
