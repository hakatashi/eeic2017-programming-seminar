#include <stdio.h>
#include <math.h>
#include <float.h>

double f(double);
double dfdx(double);
double newton(double);

int main() {
	double x0 = 1.0;
	double solution = newton(x0);
	printf("solution is %f\n", solution);
	return 0;
}

double f(double x) {
	return exp(x) + x;
}

double dfdx(double x) {
	return exp(x) + 1;
}

double newton(double x0) {
	double delta;

	delta = f(x0) / dfdx(x0);

	if (delta < FLT_EPSILON) {
		return x0;
	} else {
		return newton(x0 - delta);
	}
}
