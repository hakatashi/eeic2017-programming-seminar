#include <stdio.h>
#include <math.h>

int is_prime(int);

int main() {
	int i;
	double ret = 1.0f, pi;

	for (i = 2; i <= 1000; i++) {
		if (is_prime(i) == 1) {
			ret *= (1.0f - 1.0f / (i * i));
		}
	}

	pi = pow(ret / 6, -.5);
	printf("pi = %f\n", pi);

	return 0;
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
