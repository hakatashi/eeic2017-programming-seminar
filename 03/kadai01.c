#include <stdio.h>

double legendre(int n, double x);

int main() {
	double v = legendre(16, 0.5);
	printf("%f\n", v);
	v = legendre(32, 0.7);
	printf("%f\n", v);
	return 0;
}

double legendre(int n, double x) {
	double valA, valB;

	if (n == 0) {
		return 1;
	} else if (n == 1) {
		return x;
	} else {
		valA = (double)(2 * n - 1) * x * legendre(n - 1, x);
		valB = (double)(n - 1) * legendre(n - 2, x);
		return (valA - valB) / n;
	}
}
