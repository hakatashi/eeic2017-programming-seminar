#include<stdio.h>

int is_prime(int);

void main() {
	int i;
	for (i = 2; i <= 1000; i++) {
		if (is_prime(i) == 1) {
			printf("%d is prime\n", i);
		}
	}
}

int is_prime(int n) {
	int i;

	for (i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}

	return 1;
}
